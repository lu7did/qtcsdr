/*
This software is part of qtcsdr.


Copyright (c) 2015, Andras Retzler <randras@sdr.hu>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANDRAS RETZLER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//*--------------------------[System Word Handler]---------------------------------------------------
//* getSSW Return status according with the setting of the argument bit onto the SW
//*--------------------------------------------------------------------------------------------------
bool getWord (unsigned char SysWord, unsigned char v) {

  return SysWord & v;

}
//*--------------------------------------------------------------------------------------------------
//* setSSW Sets a given bit of the system status Word (SSW)
//*--------------------------------------------------------------------------------------------------
void setWord(unsigned char* SysWord,unsigned char v, bool val) {

  *SysWord = ~v & *SysWord;
  if (val == true) {
    *SysWord = *SysWord | v;
  }

}

#include <cmath>
#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include "../PixiePi/src/lib/CAT817.h"


CAT817 *cat=new CAT817(NULL,NULL,NULL,NULL,NULL);

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QProcess>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define CMD_IQSERVER "pgroup -9 rtl_tcp -a 127.0.0.1 -s %SAMP_RATE% -p 4950 -f 89500000"
#define CMD_DISTRIB "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4950; sleep .3; done) | nmux -p 4951 -a 127.0.0.1 -b %NMUX_BUFSIZE% -n %NMUX_BUFCNT%\""
#define CMD_MOD_WFM "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %WFM_DECIM% 0.05 HAMMING  | csdr fmdemod_quadri_cf | csdr fractional_decimator_ff 5 | csdr deemphasis_wfm_ff 48000 50e-6 | csdr convert_f_i16 |  %AUDIOPLAYER%\""
#define CMD_MOD_NFM "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr fmdemod_quadri_cf | csdr limit_ff | csdr deemphasis_nfm_ff 48000 | csdr fastagc_ff | csdr convert_f_i16 |       %AUDIOPLAYER%\""
#define CMD_MOD_AM  "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr amdemod_cf | csdr fastdcblock_ff | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |                           %AUDIOPLAYER%\""
#define CMD_MOD_USB "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc 0 0.1 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |          %AUDIOPLAYER%\""
#define CMD_MOD_LSB "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc -0.1 0 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |         %AUDIOPLAYER%\""
#define CMD_FFT     "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr fft_cc 2048 %FFT_READ_SIZE% | csdr logpower_cf -70 | csdr fft_exchange_sides_ff 2048\""
#define CMD_MOD_CW  "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc 0 0.1 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |          %AUDIOPLAYER%\""
#define CMD_MOD_CWR "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc -0.1 0 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |         %AUDIOPLAYER%\""

#define CMD_ARECORD "arecord %ADEVICE% -f S16_LE -r 48000 -c 1"

#define CMD_TX_WFM  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr gain_ff 70000 | csdr convert_f_samplerf 20833 | (gksu touch; sudo rpitx -i- -m RF -f %TXFREQ%)\""
#define CMD_TX_NFM  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr gain_ff 7000 | csdr convert_f_samplerf 20833 | (gksu touch; sudo rpitx -i- -m RF -f %TXFREQ%)\""
#define CMD_TX_AM   "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr add_dcoffset_cc | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_AM%)\""
#define CMD_TX_USB  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc 0 0.1 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_LSB  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc -0.1 0 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_CWR  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc -0.1 0 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_CW   "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc 0 0.1 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""

#define NMUX_MEMORY_MBYTE 50

//#define CMD_WFM "pgroup -9 bash -c \"rtl_tcp -s 2400000 -p 4951 -f 89500000 & (sleep 1; nc localhost 4951 | csdr convert_u8_f | csdr shift_addition_cc -0.085 | csdr fir_decimate_cc 10 0.05 HAMMING | csdr fmdemod_quadri_cf | csdr fractional_decimator_ff 5 | csdr deemphasis_wfm_ff 48000 50e-6 | csdr convert_f_i16 | mplayer -cache 768 -quiet -rawaudio samplesize=2:channels=1:rate=48000 -demuxer rawaudio -)\""



QString MainWindow::getNextArgAfter(QString what)
{
    if(QCoreApplication::arguments().contains(what))
    {
        int indexOfWhat = QCoreApplication::arguments().indexOf(what);
        if(QCoreApplication::arguments().count()>indexOfWhat+1)
        {
            if(!QCoreApplication::arguments().at(indexOfWhat+1).startsWith("--"))
            {
                return QCoreApplication::arguments().at(indexOfWhat+1);
            }
        }
    }
    return "";
}


//void MainWindow::CATchangeFreq () {
//}
//void MainWindow::CATchangeStatus() {
//}
//void MainWindow::CATchangeMode() {
//}
//void MainWindow::CATgetRX() {
//}
//void MainWindow::CATgetTX() {
//}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), qStdOut(stdout),m_serial(new QSerialPort(this)) 
{
    ui->setupUi(this);

    if(QCoreApplication::arguments().contains("--rpitx"))
    {
        ui->toggleTransmit->setEnabled(true);
        ui->comboSampRate->setCurrentIndex(4);
        //ui->spinOffset->setValue(100000);
        ui->spinCenter->setValue(28200000);
        this->resize(this->width(),ui->widgetControls->height()+100);
    }

    QString nextArg;

    //CAT817 *cat=new CAT817(NULL,NULL,NULL,NULL,NULL);
    //*cat=new CAT817(NULL,NULL,NULL,NULL,NULL);
    //*cat=new CAT817(NULL,NULL,NULL,NULL,NULL);
    cat->sendChar=(CALLBACK)&MainWindow::CATCallBack;


    if(QCoreApplication::arguments().contains("--mplayer"))
    {
         audioPlayerCommand="mplayer -cache 1024 -quiet -rawaudio samplesize=2:channels=1:rate=48000 %ADEVICE% -demuxer rawaudio -";
         if(!(alsaDevice=getNextArgAfter("--mplayer")).isEmpty())
         {
             audioPlayerCommand=audioPlayerCommand.replace("%ADEVICE%",QString("-ao alsa:device=")+alsaDevice.replace(",",".").replace(":","="));
         }
         else
             audioPlayerCommand=audioPlayerCommand.replace("%ADEVICE%","");
    }
    else
    {
        audioPlayerCommand  = "csdr mono2stereo_i16 | aplay -f S16_LE -r48000 -c2 -D ";
        if (!(alsaDevice=getNextArgAfter("--alsa")).isEmpty())
            audioPlayerCommand+=alsaDevice;
        else
            audioPlayerCommand+="default";
    }
    qDebug() << audioPlayerCommand;


//errorOccurred
    //connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    qDebug() << "Connected m_serial with readyRead function";


    modsButtons.append(ui->toggleAM);
    modsButtons.append(ui->toggleNFM);
    modsButtons.append(ui->toggleWFM);
    modsButtons.append(ui->toggleLSB);
    modsButtons.append(ui->toggleUSB);
    connect(&tmrRead, SIGNAL(timeout()), this, SLOT(tmrRead_timeout()));
    connect(ui->widgetFFT, SIGNAL(shiftChanged(int)), this, SLOT(on_shiftChanged(int)));
    tmrRead.start(10);
    //connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
}

void MainWindow::openSerialPort()
{
    //const SettingsDialog::Settings p = m_settings->settings();
    qDebug() << "openSerialPort()";


    m_serial->setPortName("/tmp/ttyv1");
    m_serial->setBaudRate(QSerialPort::Baud4800);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::TwoStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        //m_console->setEnabled(true);
        //m_console->setLocalEchoEnabled(p.localEchoEnabled);
        //m_ui->actionConnect->setEnabled(false);
        //m_ui->actionDisconnect->setEnabled(true);
        //m_ui->actionConfigure->setEnabled(false);
        //showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
        //                  .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
        //                  .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        //QMessageBox::critical(this, tr("Error"), m_serial->errorString());
        //showStatusMessage(tr("Open error"));
    }
}
void MainWindow::closeSerialPort()
{
    qDebug() << "closeSerialPort()";

    if (m_serial->isOpen())
        m_serial->close();
    //m_console->setEnabled(false);
    //m_ui->actionConnect->setEnabled(true);
    //m_ui->actionDisconnect->setEnabled(false);
    //m_ui->actionConfigure->setEnabled(true);
    //showStatusMessage(tr("Disconnected"));
}

void MainWindow::writeData(const QByteArray &data)
{
    qDebug() << "writeData()";
    m_serial->write(data);
}

void MainWindow::CATCallBack() {

   fprintf(stderr,"CATCallBack():received char(%d)\n",cat->bufChar[0]);

}

void MainWindow::readData()
{
    char buffer[18];
    byte BCDbuf[12];
    BCDbuf[0]=0x00;
    BCDbuf[1]=0x00;
    BCDbuf[2]=0x00;
    BCDbuf[3]=0x00;
    BCDbuf[4]=0x00;
    BCDbuf[5]=0x00;
    BCDbuf[6]=0x00;
    BCDbuf[7]=0x00;
    const QByteArray data = m_serial->readAll();
    qDebug() << "readData()" << data; 
    qDebug() << "readData() size()" << data.size();
    for (int i = 0; i < data.size(); ++i) {
        fprintf(stderr,"Byte[%d] %d\n",i,data.at(i));
        BCDbuf[i]=data.at(i);
    }
    cat->sendSerial(&BCDbuf[0],data.size());
    cat->hex2str(&buffer[0],&BCDbuf[0],data.size());
    fprintf(stderr,"CAT Frame->%s\n",buffer);
    //cat->sendSerial((byte*)BCDbuf[0],(int)data.size());

    //fprintf(stderr,"BCD function %d\n",cat->decToBcd(28217));
   //m_console->putData(data);
}
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        //QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}


void MainWindow::untoggleOtherModButtonsThan(QPushButton* pb)
{
    static bool protect;
    if(protect) return;
    protect = true;
    foreach(QPushButton* ipb, modsButtons) if(ipb!=pb) ipb->setChecked(false); else pb->setChecked(true);
    protect = false;

    //we select the new demodulator

    if(ui->toggleRun->isChecked())
    {
        if(procDemod.pid()) kill(procDemod.pid(), SIGTERM);
        procDemod.waitForFinished(1000);
        procDemod.start(getDemodulatorCommand());
        procDemod.waitForStarted(1000);
        setShift();
    }

    updateFilterBw();
}

void MainWindow::redirectProcessOutput(QProcess &proc, bool onlyStdErr)
{
    if(proc.pid()!=0)
    {
        QString temp = ((onlyStdErr)?"":proc.readAllStandardOutput()) + proc.readAllStandardError();
        if(temp.length()) qStdOut << temp;
    }
    qStdOut.flush();
}

void MainWindow::tmrRead_timeout()
{
    redirectProcessOutput(procDemod);
    redirectProcessOutput(procDistrib);
    redirectProcessOutput(procIQServer);
    redirectProcessOutput(procFFT, true);
    redirectProcessOutput(procTX);

    if(procFFT.pid()!=0)
    {
        FFTDataBuffer += procFFT.readAll();
        while(ui->widgetFFT->takeOneWaterfallLine(&FFTDataBuffer));
    }

}

MainWindow::~MainWindow()
{
    if(ui->toggleRun->isChecked()) on_toggleRun_toggled(false); //so that we kill all subprocesses
    delete ui;
}

void MainWindow::on_toggleWFM_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleWFM); }
void MainWindow::on_toggleNFM_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleNFM); }
void MainWindow::on_toggleAM_toggled(bool checked)  { untoggleOtherModButtonsThan(ui->toggleAM); }
void MainWindow::on_toggleUSB_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleUSB); }
void MainWindow::on_toggleLSB_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleLSB); }

void MainWindow::on_shiftChanged(int newOffset)
{
    ui->spinOffset->setValue(newOffset);
}

QString MainWindow::getDemodulatorCommand()
{
    QString myDemodCmd;
    if(ui->toggleWFM->isChecked()) myDemodCmd=CMD_MOD_WFM;
    if(ui->toggleNFM->isChecked()) myDemodCmd=CMD_MOD_NFM;
    if(ui->toggleAM->isChecked())  myDemodCmd=CMD_MOD_AM;
    if(ui->toggleLSB->isChecked()) myDemodCmd=CMD_MOD_LSB;
    if(ui->toggleUSB->isChecked()) myDemodCmd=CMD_MOD_USB;
    if(ui->toggleCW->isChecked())  myDemodCmd=CMD_MOD_CW;
    if(ui->toggleCWR->isChecked()) myDemodCmd=CMD_MOD_CWR;
   
    myDemodCmd=myDemodCmd
            .replace("%FIFO%", fifoPipePath)
            .replace("%AUDIOPLAYER%", audioPlayerCommand)
            .replace("%SAMP_RATE%",ui->comboSampRate->currentText())
            .replace("%DECIM%", QString::number(ui->comboSampRate->currentText().toInt()/48000))
            .replace("%WFM_DECIM%", QString::number(ui->comboSampRate->currentText().toInt()/240000));
    qDebug() << "myDemodCmd ="<<myDemodCmd;
    return myDemodCmd;
}

QString MainWindow::getModulatorCommand()
{
    QString myModCmd;
    if(ui->toggleWFM->isChecked()) myModCmd=CMD_TX_WFM;
    if(ui->toggleNFM->isChecked()) myModCmd=CMD_TX_NFM;
    if(ui->toggleAM->isChecked())  myModCmd=CMD_TX_AM;
    if(ui->toggleLSB->isChecked()) myModCmd=CMD_TX_LSB;
    if(ui->toggleUSB->isChecked()) myModCmd=CMD_TX_USB;
    if(ui->toggleUSB->isChecked()) myModCmd=CMD_TX_CW;
    if(ui->toggleUSB->isChecked()) myModCmd=CMD_TX_CWR;
    myModCmd=myModCmd
            .replace("%ARECORD%", CMD_ARECORD)
            .replace("%ADEVICE%", (alsaDevice.isEmpty())?"":"-D "+alsaDevice)
            .replace("%TXFREQ_AM%", QString::number((ui->spinFreq->value()+10000)/1000,'f',0))
            .replace("%TXFREQ%", QString::number(ui->spinFreq->value()/1000,'f',0))
            .replace("%TXFREQ_SSB%", QString::number((ui->spinFreq->value()+2000)/1000,'f',0));
    ui->lcdNumberPanel->display(float(ui->spinFreq->value()+10000)/1000);
    qDebug() << "myModCmd ="<<myModCmd;
    return myModCmd;
}


void MainWindow::updateFilterBw()
{
    ui->widgetFFT->offsetFreq = ui->spinOffset->value();
    if(ui->toggleWFM->isChecked()) { ui->widgetFFT->filterLowCut=-70000; ui->widgetFFT->filterHighCut=70000; }
    if(ui->toggleNFM->isChecked()) { ui->widgetFFT->filterLowCut=-4000; ui->widgetFFT->filterHighCut=4000; }
    if(ui->toggleAM->isChecked())  { ui->widgetFFT->filterLowCut=-4000; ui->widgetFFT->filterHighCut=4000; }
    if(ui->toggleLSB->isChecked()) { ui->widgetFFT->filterLowCut=-4000; ui->widgetFFT->filterHighCut=0; }
    if(ui->toggleUSB->isChecked()) { ui->widgetFFT->filterLowCut=0; ui->widgetFFT->filterHighCut=4000; }
    if(ui->toggleCW->isChecked())  { ui->widgetFFT->filterLowCut=0; ui->widgetFFT->filterHighCut=600; }
    if(ui->toggleCWR->isChecked()) { ui->widgetFFT->filterLowCut=-600; ui->widgetFFT->filterHighCut=0; }
}

void MainWindow::on_toggleRun_toggled(bool checked)
{
    if(checked)
    {

        ui->widgetFFT->sampleRate=ui->comboSampRate->currentText().toInt();
        ui->comboSampRate->setEnabled(false);
        fifoPipePath = QString("/tmp/qtcsdr_shift_pipe_")+QString::number(rand());
        mkfifo(fifoPipePath.toStdString().c_str(), 0600);
        fifoPipe=open(fifoPipePath.toStdString().c_str(), O_RDWR);
        setShift();
        QString IQCommand = QString(CMD_IQSERVER).replace("%SAMP_RATE%",ui->comboSampRate->currentText());
        qDebug() << "IQCommand =" << IQCommand;
        procIQServer.start(IQCommand);
        procIQServer.waitForStarted(1000);
        int nmuxBufsize = 0, nmuxBufcnt = 0, sampRate = ui->comboSampRate->currentText().toInt();
        while (nmuxBufsize < sampRate/4) nmuxBufsize += 4096; //taken from OpenWebRX
        while (nmuxBufsize * nmuxBufcnt < NMUX_MEMORY_MBYTE * 1e6) nmuxBufcnt += 1;
        QString distribCommand = QString(CMD_DISTRIB)
                .replace("%NMUX_BUFSIZE%", QString::number(nmuxBufsize))
                .replace("%NMUX_BUFCNT%", QString::number(nmuxBufcnt));
        qDebug() << "distribCommand =" << distribCommand;
        procDistrib.start(distribCommand);
        procDistrib.waitForStarted(1000);
        procDemod.start(getDemodulatorCommand());
        QString FFTCommand = QString(CMD_FFT).replace("%FFT_READ_SIZE%", QString::number(ui->comboSampRate->currentText().toInt()/10));
        qDebug() << "FFTCommand" << FFTCommand;
        procFFT.start(FFTCommand);

        this->openSerialPort();

        on_spinFreq_valueChanged(ui->spinFreq->value());
        on_lcdNumberPanel_valueChanged(ui->spinFreq->value());
        on_comboDirectSamp_currentIndexChanged(0);

        updateFilterBw();
    }
    else
    {
        ui->comboSampRate->setEnabled(true);
        unlink(fifoPipePath.toStdString().c_str());
        if(procDemod.pid()!=0)    kill(procDemod.pid(), SIGTERM);
        if(procDistrib.pid()!=0)  kill(procDistrib.pid(), SIGTERM);
        if(procIQServer.pid()!=0) kill(procIQServer.pid(), SIGTERM);
        if(procFFT.pid()!=0)      kill(procFFT.pid(), SIGTERM);
        this-> closeSerialPort();
        procFFT.readAll();
        FFTDataBuffer.clear();
    }
}

void MainWindow::on_toggleTransmit_toggled(bool checked)
{
    if(checked)
    {
        QString modCmd = getModulatorCommand();
        procTX.start(modCmd);
        procTX.waitForStarted(1000);
    }
    else
    {
        if(procTX.pid()!=0)
        {
            procKillTX.start("bash -c \"gksu touch; sudo killall rpitx\"");
            kill(procTX.pid(), SIGTERM);
        }
    }
}

void MainWindow::setShift()
{
    QString shiftString = QString::number(-ui->spinOffset->value()/(float)ui->comboSampRate->currentText().toInt())+"\n";
    write(fifoPipe,shiftString.toStdString().c_str(),shiftString.length());
    ui->widgetFFT->offsetFreq = ui->spinOffset->value();
}

void MainWindow::sendCommand(unsigned char cmd_num, unsigned value)
{
    //docs: https://github.com/pinkavaj/rtl-sdr/blob/master/src/rtl_tcp.c#L324
    unsigned char cmd[5];
    cmd[0] = cmd_num; //set_freq
    cmd[1] = (value>>24)&0xff;
    cmd[2] = (value>>16)&0xff;
    cmd[3] = (value>>8)&0xff;
    cmd[4] = value&0xff;
    procDistrib.write((char*)cmd, 5);
}

void MainWindow::on_lcdNumberPanel_valueChanged(int val)
{
    ui->lcdNumberPanel->setSmallDecimalPoint(true);
    ui->lcdNumberPanel->display(float(val/1000));  //* Intervention to update LCD

}
void MainWindow::on_spinFreq_valueChanged(int val)
{
    ui->spinCenter->setValue(ui->spinFreq->value()-ui->spinOffset->value());
//    ui->lcdNumberPanel->setSmallDecimalPoint(true);
//    ui->lcdNumberPanel->display(float(val/1000));  //* Intervention to update LCD
    //sprintf(hi,"%8.2f",float(val/1000));
    //ui->lcdNumberPanel->display(hi);  //* Intervention to update LCD
    sendCommand(RTLTCP_SET_FREQ, ui->spinCenter->value());

    //procDemod.write("\x01\x05\x55\xa9\x60");
    //procDemod.write("macska\n");
}

void MainWindow::on_spinOffset_valueChanged(int arg1)
{
    setShift();
    ui->spinFreq->setValue(ui->spinCenter->value()+ui->spinOffset->value());
    ui->lcdNumberPanel->display(float(ui->spinCenter->value()+ui->spinOffset->value())/1000);

    
}

void MainWindow::on_spinCenter_valueChanged(int arg1)
{
    sendCommand(RTLTCP_SET_FREQ, ui->spinCenter->value());
    ui->spinFreq->setValue(ui->spinCenter->value()+ui->spinOffset->value());
    ui->lcdNumberPanel->display(float(ui->spinCenter->value()+ui->spinOffset->value())/1000);
}

void MainWindow::on_comboDirectSamp_currentIndexChanged(int index)
{
    sendCommand(RTLTCP_SET_DIRECT_SAMPLING,ui->comboDirectSamp->currentIndex());
}
