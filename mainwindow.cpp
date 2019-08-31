/*
This software is a fork evolution of  qtcsdr.
Copyright (c) 2015, Andras Retzler <randras@sdr.hu>
All rights reserved.

---------------------------------------------------------------------------
qtcsdr extensions
Copyright (c) 2019, Dr. Pedro E. Colla <LU7DID> lu7did@gmail.com
All rights reserved

Libraries incorporated from PixiePi package (http://www.github.com/lu7did/PixiePi).
---------------------------------------------------------------------------
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

#include "../PixiePi/src/pixie/pixie.h"
#include "../PixiePi/src/lib/CAT817.h"
#include "../PixiePi/src/lib/DDS.h"
#include "../PixiePi/src/lib/VFOSystem.h"

CAT817 *cat=new CAT817(NULL,NULL,NULL,NULL,NULL);
DDS *dds=new DDS(NULL);

bool running=true;
void setPTT(bool statePTT);
byte FT817;
int  shift=VFO_SHIFT;
int  ritofs=0;
int  step=0;
byte ddspower=MAXLEVEL;
byte ptt=KEYER_OUT_GPIO;
byte txonly=ALWAYS;
int  keyer_brk=KEYER_BRK;
byte vfo[2];
//*---- Keyer specific definitions
byte sidetone_gpio=SIDETONE_GPIO;
float ppm=1000.0;
struct sigaction sa;
byte keepalive=0;
byte backlight=BACKLIGHT_DELAY;
char port[80];
long catbaud=CATBAUD;
byte gpio=GPIO04;
bool fSwap=false;

int maxrit=MAXRIT;
int minrit=MINRIT;
int ritstep=RITSTEP;
int ritstepd=RITSTEPD;

int vfoLower=88000000;
int vfoUpper=107000000;
int vfoCenter=6900000;
byte vfoAB=VFOA;

//*--- Keyer related memory definitions

char snd_dev[64]="hw:0";

const char   *PROGRAMID="qtcsdr";
const char   *PROG_VERSION="2.0";
const char   *PROG_BUILD="01";
const char   *COPYRIGHT="(c) LU7DID 2019";

#include "../PixiePi/src/iambic/iambic.c"




#include <QDebug>
#include <QProcess>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

//*----------------------------------------------------------------------------------------------------------------------------------------------------
//* Static (default) DSP processor command set
//*----------------------------------------------------------------------------------------------------------------------------------------------------
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
#define CMD_MOD_DSP "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc 0 0.1 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |          %AUDIOPLAYER%\""
#define CMD_MOD_PKT "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc 0 0.1 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |          %AUDIOPLAYER%\""


#define CMD_ARECORD "arecord %ADEVICE% -f S16_LE -r 48000 -c 1"

#define CMD_TX_WFM  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr gain_ff 70000 | csdr convert_f_samplerf 20833 | (gksu touch; sudo rpitx -i- -m RF -f %TXFREQ%)\""
#define CMD_TX_NFM  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr gain_ff 7000 | csdr convert_f_samplerf 20833 | (gksu touch; sudo rpitx -i- -m RF -f %TXFREQ%)\""
#define CMD_TX_AM   "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr add_dcoffset_cc | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_AM%)\""
#define CMD_TX_USB  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc 0 0.1 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_LSB  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc -0.1 0 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_CWR  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc -0.1 0 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_CW   "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc 0 0.1 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_DSP  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc 0 0.1 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_PKT  "pgroup bash -c \"%ARECORD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc 0 0.1 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""

#define NMUX_MEMORY_MBYTE 50
//#*----------------------------------------------------------------------------------------------------------------------------------------------------
//*                                                         Callback and IPC hooks
//*-----------------------------------------------------------------------------------------------------------------------------------------------------

//*-----------------------------------------------------------------------------------------------------------------------------------------------------
//* setPTT
//* build time reference for iambic.c
//* called when the transmitter needs to be turned on
//*-----------------------------------------------------------------------------------------------------------------------------------------------------
MainWindow* h=NULL;       // Pointer to GUI main window to be initialized within the CONSTRUCTOR

void setPTT(bool statePTT) {

    if (h!=NULL) {
       qDebug() << "Test Power2S(-119 dBm)" << h->power2S(-119.0);
    }
    fprintf(stderr,"setPTT()\n");
    return;
}
//*------------------------------------------------------------------------------------------------------------------------------------
//* MainWindow GUI constructor
//* GUI constructor and program initialization
//*------------------------------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), qStdOut(stdout),m_serial(new QSerialPort(this)) 
{

//*--- create GUI

    ui->setupUi(this);

//*--- Initialize status of main controls
    h=this;          // Reference to the GUI main window to be used by non Qt functions
    iambic_init();

    ui->labelCAT->setHidden(false);
    ui->labelPWR->setHidden(false);
    ui->labelPTT->setHidden(false);
    ui->labelCAT->setStyleSheet("QLabel { background-color : blue; }");
    ui->labelPWR->setStyleSheet("QLabel { background-color : green; }");
    ui->labelPTT->setStyleSheet("QLabel { background-color : #800000; }");


    ui->progressBarMeter->setMinimum(0);
    ui->progressBarMeter->setMaximum(15);

    ui->labelVFO->setHidden(true);
    ui->labelMODE->setHidden(true);
    ui->labelMETER->setHidden(true);
    ui->progressBarMeter->setHidden(true);


    ui->lcdNumberPanel->setStyleSheet("QLabel { background-color : #FFCF9E; }");

    ui->dial->setMinimum(0);
    ui->dial->setMaximum(100);
    ui->dial->setWrapping(false);
    ui->dial->setEnabled(false);
    dialAnt=ui->dial->value();
    dialDelta=0;
    dialChanged=false;
    TDIAL=3;

    ui->spinCenter->setEnabled(true);
    ui->spinOffset->setEnabled(true);

    if(QCoreApplication::arguments().contains("--rpitx"))
    {
        ui->toggleTransmit->setEnabled(true);
        ui->comboSampRate->setCurrentIndex(4);
        //ui->spinOffset->setValue(100000);
        ui->spinCenter->setValue(28200000);
        this->resize(this->width(),ui->widgetControls->height()+100);
    }

    QString nextArg;


//*--- initialize CAT hooks


    cat->sendChar=(CALLBACK)&MainWindow::CATCallBack;
    cat->changeFreq=(CALLBACK)&MainWindow::CATchangeFreq;
    cat->changeStatus=(CALLBACK)&MainWindow::CATchangeStatus;
    cat->changeMode=(CALLBACK)&MainWindow::CATchangeMode;
    cat->METER=0x00;


//*--- Different sound devices

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


//*--- create general purpose 100 mSec timer for system management

    QTimer *t = new QTimer(this);



//*--- Create group of buttons

    modsButtons.append(ui->toggleAM);
    modsButtons.append(ui->toggleNFM);
    modsButtons.append(ui->toggleWFM);
    modsButtons.append(ui->toggleLSB);
    modsButtons.append(ui->toggleUSB);
    modsButtons.append(ui->toggleCW);
    modsButtons.append(ui->toggleCWR);
    modsButtons.append(ui->toggleDSP);
    modsButtons.append(ui->togglePKT);

//*--- Connect SIGNALS with SLOTS of the GUI objects

    connect(&tmrRead, SIGNAL(timeout()), this, SLOT(tmrRead_timeout()));
    connect(ui->widgetFFT, SIGNAL(shiftChanged(int)), this, SLOT(on_shiftChanged(int)));
    connect(t,SIGNAL(timeout()),this,SLOT(handleTimer()));
    connect(ui->dial,SIGNAL(valueChanged(int)),this,SLOT(on_dial_valueChanged(int)));
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);

//*--- initialize CAT and DDS

   vfo[VFOA]=vfoLower;
   vfo[VFOB]=vfoUpper;
   vfoAB=VFOA;
   (vfoAB==VFOA?ui->labelVFO->setText("VFOA"):ui->labelVFO->setText("VFOB"));
   

   setWord(&FT817,SPLIT,false);
   setWord(&FT817,RIT,false);
   setWord(&FT817,LOCK,false);
   setWord(&FT817,TXONLY,true);
   cat->FT817=FT817;


//*--- Generate DDS (code excerpt mainly from tune.cpp by Evariste Courjaud F5OEO

    dds->gpio=byte(gpio);
    dds->power=byte(ddspower);
    cat->POWER=dds->power;


//*--- Activate timers

    t->start(100);
    tmrRead.start(10);

}

//*---------------------------------------------------------------------------------------------------------------
//* GUI Destructor
//* Called upon program termination
//*---------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{

    delete(dds);
    running=false;
    iambic_close();
    if(ui->toggleRun->isChecked()){
       on_toggleRun_toggled(false); //so that we kill all subprocesses
    }
    delete ui;
}

//*------------------------------------------------------------------------------------------------------------------------------------
//* getNextArgAfter
//* process arguments
//*------------------------------------------------------------------------------------------------------------------------------------
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

//*------------------------------------------------[CAT Management]-------------------------------------------------
//* This is the implementation of the methods contained in the CAT817.h library, the program emulates a Yaesu FT-817
//* commands are assumed to come from a serial port or a pipe emulating one (if on a same machine loopback)
//*-----------------------------------------------------------------------------------------------------------------
void MainWindow::openSerialPort()
{
    qDebug() << "openSerialPort(): port " << serialPortName;
    m_serial->setPortName(serialPortName);
    m_serial->setBaudRate(QSerialPort::Baud4800);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::TwoStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
       qDebug() << "openSerialPort(): Open success";
    } else {
       qDebug() << "openSerialPort(): Open Error";
    }
}

//*---- Close serial port
void MainWindow::closeSerialPort()
{
    qDebug() << "closeSerialPort()";

    if (m_serial->isOpen())
        m_serial->close();
}

//*---- Follows the hooks used by the CAT library, these hooks are used to signal the library an external program is using it
//*---- However the entries are not used as a callback to avoid flow and object architecture model conflicts
 
void MainWindow::CATchangeFreq () {
}
void MainWindow::CATchangeStatus() {
}
void MainWindow::CATchangeMode() {
    qDebug() << "changeMode()" << cat->MODE ;
    fchangeMode=true;
}
void MainWindow::CATgetRX() {
}
void MainWindow::CATgetTX() {
}
//*--- Callback entry (not used)
void MainWindow::CATCallBack() {
}


//*---- method to write a single character (not used)
void MainWindow::writeChar(byte d) 

{

     qDebug() << "writeChar() " << d;
}
//*--- write data back to the controller program after processing the CAT command
void MainWindow::writeData(const QByteArray &data)
{
    m_serial->write(data,1);
}

//*--- Read a CAT request, format frames and process them, a response is given according to the command
//*--- process changes in operational parameters as requested by the command

void MainWindow::readData()
{
    char buffer[18];
    byte BCDbuf[16];
    int maxFrame=4;

    BCDbuf[0]=0x00;
    BCDbuf[1]=0x00;
    BCDbuf[2]=0x00;
    BCDbuf[3]=0x00;
    BCDbuf[4]=0x00;
    BCDbuf[5]=0x00;
    BCDbuf[6]=0x00;
    BCDbuf[7]=0x00;

//*--- read all pending chanracters

    const QByteArray data = m_serial->readAll();

//*--- process into a buffer

    for (int m = 0; m < data.size(); m++) {
        cat->rxBuffer[cat->n]=data.at(m);
        cat->n++;
    }

//*--- five characters arrived? Hay que mejorar el procesamiento asumiento que haya mas de 5 caracteres

    while (cat->n>=5) {

       cat->hex2str(&buffer[0],&cat->rxBuffer[0],cat->n);
       cat->processCAT(&cat->rxBuffer[0]);

       if (cat->n > 5) {
          int p=5;
          for (int k=cat->n-5;k>0;k--) {
              cat->rxBuffer[p-5]=cat->rxBuffer[p];
              p++;
          }
       }
       cat->n=cat->n-5;

//*--- Has a frequency change been detected?

       if (cat->fchangeFreq==true) {
          qDebug() << "readData(): changeFreq " << cat->SetFrequency;
          cat->fchangeFreq=false;
          ui->spinFreq->setValue(cat->SetFrequency);
       }

//*--- Has a  mode change been detected?

       if (cat->fchangeMode==true) {
          cat->fchangeMode=false;

          qDebug() << "readData(): fchangeModeDetected" << cat->MODE;
          switch(cat->MODE) {
             case MLSB : {untoggleOtherModButtonsThan(ui->toggleLSB); break;}
             case MUSB : {untoggleOtherModButtonsThan(ui->toggleUSB); break;}
             case MCW  : {untoggleOtherModButtonsThan(ui->toggleCW); break;}
             case MCWR : {untoggleOtherModButtonsThan(ui->toggleCWR); break;}
             case MAM  : {untoggleOtherModButtonsThan(ui->toggleAM); break;}
             case MFM  : {untoggleOtherModButtonsThan(ui->toggleNFM); break;}
             case MWFM : {untoggleOtherModButtonsThan(ui->toggleWFM); break;}
             case MDIG : {untoggleOtherModButtonsThan(ui->toggleDSP); break;}
             case MPKT : {untoggleOtherModButtonsThan(ui->togglePKT); break;}
          }
       }


//*--- signal at the GUI a CAT interaction has been made, make the indicator last for 200 mSecs

       ui->labelCAT->setStyleSheet("QLabel { background-color : cyan; }");
       TCAT=20;

//*--- Write the CAT response back to the contoller program
       if (cat->bufLen!=0) {
          cat->hex2str(&buffer[0],&cat->bufChar[0],cat->bufLen);
          m_serial->write((char*)&cat->bufChar[0],cat->bufLen);
          cat->bufLen=0;
       }

       maxFrame--;
       if (maxFrame==0) { 
          return;  //If processed one command don't get stuck here
       }

    }
}
//*----- handle serial port errors
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}
//*---------------------------------------------------------------------------------------------------------------------
//*                                    Operational Management thru GUI actions
//*---------------------------------------------------------------------------------------------------------------------
//*---------------------------------------------------------------------------------------------------------------------
//* on_toggleRun_toggled
//* Manage the Power button, turns the transceiver on or off
//* When turned on starts all relevant background processes and setup the GUI to enable the usage
//* enable the waterfall, turns the RTL-SDR flow of samples  and start listeining to CAT commands
//*---------------------------------------------------------------------------------------------------------------------
void MainWindow::on_toggleRun_toggled(bool checked)
{
    if(checked)
    {

        ui->spinCenter->setEnabled(false);
        ui->spinOffset->setEnabled(false);
        ui->comboDirectSamp->setEnabled(false);

//*--- start the waterfall

        ui->widgetFFT->sampleRate=ui->comboSampRate->currentText().toInt();
        ui->comboSampRate->setEnabled(false);

//*--- start the FIFO to communicate with CSDR the current shift

        fifoPipePath = QString("/tmp/qtcsdr_shift_pipe_")+QString::number(rand());
        mkfifo(fifoPipePath.toStdString().c_str(), 0600);
        fifoPipe=open(fifoPipePath.toStdString().c_str(), O_RDWR);
        setShift();

//*--- Start DSP processors

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

//*--- Start listening for CAT commands on serial port or internal pipe and init CAT system

        this->openSerialPort();
        cat->SetFrequency=ui->spinFreq->value();

//*--- Set the operation frequency and set the dial accordingly

        on_spinFreq_valueChanged(ui->spinFreq->value());
        on_lcdNumberPanel_valueChanged(ui->spinFreq->value());
        on_comboDirectSamp_currentIndexChanged(0);

//*--- set the bandwidth of the filter based on the mode

        updateFilterBw();

//*--- GUI activation

        ui->labelCAT->setHidden(false);
        ui->labelPWR->setHidden(false);
        ui->labelPTT->setHidden(false);
        ui->labelVFO->setHidden(false);
        ui->labelMODE->setHidden(false);
        ui->labelMETER->setHidden(false);
        ui->progressBarMeter->setHidden(false);

        ui->labelCAT->setStyleSheet("QLabel { background-color : #0000FF; }");
        ui->labelPWR->setStyleSheet("QLabel { background-color : #32CD32; }");
        ui->labelPTT->setStyleSheet("QLabel { background-color : #800000; }");

        ui->dial->setEnabled(true);

    }
    else
    {

        ui->spinCenter->setEnabled(true);
        ui->spinOffset->setEnabled(true);
        ui->comboDirectSamp->setEnabled(true);
        ui->comboSampRate->setEnabled(true);

//*--- stop pipe

        unlink(fifoPipePath.toStdString().c_str());

//*--- kill all background processes

        if(procDemod.pid()!=0)    kill(procDemod.pid(), SIGTERM);
        if(procDistrib.pid()!=0)  kill(procDistrib.pid(), SIGTERM);
        if(procIQServer.pid()!=0) kill(procIQServer.pid(), SIGTERM);
        if(procFFT.pid()!=0)      kill(procFFT.pid(), SIGTERM);

//*--- close CAT commands

        this-> closeSerialPort();

//*--- clean up buffers

        procFFT.readAll();
        FFTDataBuffer.clear();
        ui->dial->setEnabled(false);

//*--- set GUI into idle mode (should be the same than at the start)

        ui->labelVFO->setHidden(true);
        ui->labelMODE->setHidden(true);
        ui->labelMETER->setHidden(true);
        ui->progressBarMeter->setHidden(true);

        ui->labelCAT->setStyleSheet("QLabel { background-color : blue; }");
        ui->labelPWR->setStyleSheet("QLabel { background-color : green; }");
        ui->labelPTT->setStyleSheet("QLabel { background-color : #800000; }");

    }
}
//*---------------------------------------------------------------------------------------------------------------------
//* on_togglexxx_toggled
//* Event handlers for all the mode related buttons
//*----- Manage changes in mode, basically turn the current processor off and start the new one
//*---------------------------------------------------------------------------------------------------------------------

void MainWindow::on_toggleWFM_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleWFM); }
void MainWindow::on_toggleNFM_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleNFM); }
void MainWindow::on_toggleAM_toggled(bool checked)  { untoggleOtherModButtonsThan(ui->toggleAM); }
void MainWindow::on_toggleUSB_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleUSB); }
void MainWindow::on_toggleLSB_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleLSB); }
void MainWindow::on_toggleCW_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleCW); }
void MainWindow::on_toggleCWR_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleCWR); }
void MainWindow::on_toggleDSP_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleDSP); }
void MainWindow::on_togglePKT_toggled(bool checked) { untoggleOtherModButtonsThan(ui->togglePKT); }

//*---------------------------------------------------------------------------------------------------------------------
//* untoggleOtherModButtonsThan
//*---- invoked when a mode change is requested in order to untoggle all modes except the modified one
//*---- Once performed the new modulator DSP processor is selected and executed
//*---------------------------------------------------------------------------------------------------------------------
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
        ui->dial->setEnabled(true);
    }

    updateFilterBw();

    if (ui->toggleLSB->isChecked()) {cat->MODE=MLSB;ui->labelMODE->setText("LSB");dialStep=STEP100HZ;}
    if (ui->toggleUSB->isChecked()) {cat->MODE=MUSB;ui->labelMODE->setText("USB");dialStep=STEP100HZ;}
    if (ui->toggleCW->isChecked())  {cat->MODE=MCW;ui->labelMODE->setText("CW");dialStep=STEP100HZ;}
    if (ui->toggleCWR->isChecked()) {cat->MODE=MCWR;ui->labelMODE->setText("CWR");dialStep=STEP100HZ;}
    if (ui->toggleAM->isChecked())  {cat->MODE=MAM;ui->labelMODE->setText("AM");dialStep=STEP10KHZ;}
    if (ui->toggleWFM->isChecked()) {cat->MODE=MWFM;ui->labelMODE->setText("WFM");dialStep=STEP100KHZ;}
    if (ui->toggleNFM->isChecked()) {cat->MODE=MFM;ui->labelMODE->setText("FM");dialStep=STEP10KHZ;}
    if (ui->toggleDSP->isChecked()) {cat->MODE=MDIG;ui->labelMODE->setText("DSP");dialStep=STEP100HZ;}
    if (ui->togglePKT->isChecked()) {cat->MODE=MPKT;ui->labelMODE->setText("PKT");dialStep=STEP100HZ;}

}
//*------------------------------------------------------------------------------------------------------
//* on_shiftChanged
//* the offset between the RTL-SDR dongle and the current frequency has changed, adjust accordingly
//*------------------------------------------------------------------------------------------------------
void MainWindow::on_shiftChanged(int newOffset)
{
    ui->spinOffset->setValue(newOffset);
}

//*------------------------------------------------------------------------------------------------------
//* on_toggleTransmit_toggled
//* event to handle the request to turn the transmitter on, can be triggered thru the GUI or thru
//* other external events such as CAT or Keyer.
//*------------------------------------------------------------------------------------------------------
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
//*---------------------------------------------------------------------------------------------------
//* on_lcdNumberPanel_valueChanged
//* set the value of the lcd panel
//*--------------------------------------------------------------------------------------------------
void MainWindow::on_lcdNumberPanel_valueChanged(int val)
{
    ui->lcdNumberPanel->setSmallDecimalPoint(true);
    ui->lcdNumberPanel->display(float(val/1000));  //* Intervention to update LCD

}
//*---------------------------------------------------------------------------------------------------
//* on_spinFreq_valueChanged
//* manage request for frequency changes coming from the dial, CAT, GUI Waterfall or spin
//*---------------------------------------------------------------------------------------------------
void MainWindow::on_spinFreq_valueChanged(int val)
{
    qDebug() << "on_spinFreq_valueChanged() " << val;

    int LO=ui->spinCenter->value();
    int SR=ui->comboSampRate->currentText().toInt();

    if (val > (LO+(SR/2))) {   //* Frequency higher than LO+SR/2 out of margin, correct LO
       LO=LO+(SR/4);
       ui->spinCenter->setValue(LO);
    }

    if (val < (LO-(SR/2))) {
       LO=LO-(SR/4);
       ui->spinCenter->setValue(LO);
    }

    ui->spinOffset->setValue(ui->spinFreq->value()-ui->spinCenter->value());
    ui->lcdNumberPanel->display(float(ui->spinFreq->value()/1000));

    sendCommand(RTLTCP_SET_FREQ, ui->spinCenter->value());
    if (cat->SetFrequency != ui->spinFreq->value()) {
        cat->SetFrequency=ui->spinFreq->value();
    }

}
//*---------------------------------------------------------------------------------------------------
//* on_spinOffset_valueChanged
//* manage requests to change the offset
//*---------------------------------------------------------------------------------------------------
void MainWindow::on_spinOffset_valueChanged(int arg1)
{
    qDebug() << "on_spinOffset " << arg1;
    setShift();
    ui->spinFreq->setValue(ui->spinCenter->value()+ui->spinOffset->value());
    ui->lcdNumberPanel->display(float(ui->spinFreq->value())/1000);

    
}
//*----------------------------------------------------------------------------------------------------
//* on_spinCenter_valueChanged
//* manage requests to change the Local Oscillator (LO) frequency
//*----------------------------------------------------------------------------------------------------
void MainWindow::on_spinCenter_valueChanged(int arg1)
{
    qDebug() << "on_spinCenter " << arg1;
    sendCommand(RTLTCP_SET_FREQ, ui->spinCenter->value());
    ui->spinFreq->setValue(ui->spinCenter->value()+ui->spinOffset->value());
    ui->lcdNumberPanel->display(float(ui->spinFreq->value()/1000));
}
//*----------------------------------------------------------------------------------------------------
//* on_comboDirectSamp
//* Change the sampling mode 0=Direct,1=I,2=Q
//*----------------------------------------------------------------------------------------------------
void MainWindow::on_comboDirectSamp_currentIndexChanged(int index)

{
    sendCommand(RTLTCP_SET_DIRECT_SAMPLING,ui->comboDirectSamp->currentIndex());
}
//*-------------------------------------------------------------------------------------------
//*--- on_dial_valueChanged (dial control)
//*--- This is the event handler for the Dial control, called whenever the dial knob is moved
//*--- The actual frequency isn't changed until 3 system timer ticks (aka 300 mSecs) has elapsed
//*--- this is done to prevent to overwhelm the processor with DSP processor updates when
//*--- changing fast between frequencies
//*-------------------------------------------------------------------------------------------
void MainWindow::on_dial_valueChanged(int v) {

    if (v==0 && this->dialAnt==100) {
       this->dialDelta++;
       this->dialAnt=v;
       this->dialChanged=true;
       TDIAL=3;
       return;
    }

    if (this->dialAnt==0 && v==100) {
       this->dialDelta--;

       this->dialAnt=v;
       this->dialChanged=true;
       TDIAL=3;
       return;
    }

    if (v>this->dialAnt) {
      this->dialDelta=this->dialDelta+(v-this->dialAnt);
      this->dialAnt=v;
      this->dialChanged=true;
      TDIAL=3;
      return;
    }
    if (v<this->dialAnt) {
      this->dialDelta=this->dialDelta+(v-this->dialAnt);
      this->dialAnt=v;
      this->dialChanged=true;
      TDIAL=3;
      return;
    }

}
//*--------------------------------------------------------------------------------------------------------------------------------------
//*                                 System management timers
//* There are two timers, one DSP related serves buffer updates and waterfall refreshing (tmr_read_timeout()) while the other is 
//  (handleTimer) is related to usability and GUI management
//*--------------------------------------------------------------------------------------------------------------------------------------

//*-------------------------------------------------------------------------------------------------------------------------------------
//* handleTimer
//* This timer is invoked to maintain a set of GUI and operations related timers, each one independently upon expiration generates
//* actions.
//*-------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::handleTimer() {

//*--- This timer is used to unblink the CAT virtual LED after some period of inactivity

   if (TCAT!=0) {
      TCAT--;
      if(TCAT==0) {
        if(ui->toggleRun->isChecked()) {
          ui->labelCAT->setStyleSheet("QLabel { background-color : #0000FF; }");
        } else {
          ui->labelCAT->setStyleSheet("QLabel { background-color : blue; }");
        }

      }
   }

//*--- This timer is meant to be used to manage the break-in feature

   if (TBRK!=0) {
      TBRK--;
      if(TBRK==0) {

      }
   }

//*--- This is a general purpose second elapsed timer

   if (TSEC!=0) {
      TSEC--;
      if (TSEC==0) {
         TSEC=10;
      }
   }

//*--- This timer is used to apply changes of the dial once no further movements are made
   if (TDIAL!=0) {
      TDIAL--;
      if (TDIAL==0) {
         if (this->dialChanged == true) {
            int d=this->dialDelta*this->dialStep;
            int f=ui->spinFreq->value()+d;
            qDebug() << "handleTimer(): change frequency " << f << d;
            ui->spinFreq->setValue(f);

            //on_spinFreq_valueChanged(f);
         }
         this->dialChanged=false;
         this->dialDelta=0;
      }
   }
}

//*----------------------------------------------------------------------------------------------------------------
//* tmrRead_timeout
//* this timer is used for queue cleanup, waterfall management and other DSP related features
//*----------------------------------------------------------------------------------------------------------------
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
        int SUnit=this->power2S(ui->widgetFFT->signalPower+SMETER_CALLIBRATION);
        cat->METER=SUnit;
        
        ui->progressBarMeter->setStyleSheet("::chunk {"
                    "background-color: "
                    "qlineargradient(x0: 0, x2: 1, "
                    "stop: 0 green, stop: 0.6 green, "
                    "stop: 0.8 orange, "
                    "stop: 1 red"
                    ")}");
        ui->progressBarMeter->setValue(SUnit);
    }


}

//*--------------------------------------------------------------------------------------------------------------------------------------
//*                                 DSP Processing, Queue Management and Device Control
//*--------------------------------------------------------------------------------------------------------------------------------------


//*--------------------------------------------------------------------------------------------------------------------------------------
//* redirectProcessOutput
//* meant to be a general cleanup of standard input and error of all the background processes
//*--------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::redirectProcessOutput(QProcess &proc, bool onlyStdErr)
{
    if(proc.pid()!=0)
    {
        QString temp = ((onlyStdErr)?"":proc.readAllStandardOutput()) + proc.readAllStandardError();
        if(temp.length()) qStdOut << temp;
    }
    qStdOut.flush();
}

//*------------------------------------------------------------------------------------------------------
//* power2S
//* Transform power readings in dBm to S-Units 
//*------------------------------------------------------------------------------------------------------
int  MainWindow::power2S(float s) {

     if (s<=-126) return 0;
     if (s<=-121) return 1;
     if (s<=-115) return 2;
     if (s<=-109) return 3;
     if (s<=-103) return 4;
     if (s<=-97) return 5;
     if (s<=-91) return 6;
     if (s<=-85) return 7;
     if (s<=-79) return 8;
     if (s<=-73) return 9;
     if (s<=-63) return 10;
     if (s<=-53) return 11;
     if (s<=-43) return 12;
     if (s<=-33) return 13;
     if (s<=-23) return 14;

     return 15;
}    
//*--------------------------------------------------------------------------------------------------------------------------------
//* getDemodulatorCommand
//* get the demodulator command processor based on the current mode, performs macro expansion
//*--------------------------------------------------------------------------------------------------------------------------------
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
    if(ui->toggleDSP->isChecked()) myDemodCmd=CMD_MOD_DSP;
    if(ui->togglePKT->isChecked()) myDemodCmd=CMD_MOD_PKT;
   
    myDemodCmd=myDemodCmd
            .replace("%FIFO%", fifoPipePath)
            .replace("%AUDIOPLAYER%", audioPlayerCommand)
            .replace("%SAMP_RATE%",ui->comboSampRate->currentText())
            .replace("%DECIM%", QString::number(ui->comboSampRate->currentText().toInt()/48000))
            .replace("%WFM_DECIM%", QString::number(ui->comboSampRate->currentText().toInt()/240000));
    qDebug() << "myDemodCmd ="<<myDemodCmd;
    return myDemodCmd;
}
//*---------------------------------------------------------------------------------------------------------------
//* getModulatorCommand
//* get the modulator processor command with macro expansion
//*---------------------------------------------------------------------------------------------------------------
QString MainWindow::getModulatorCommand()
{
    QString myModCmd;
    if(ui->toggleWFM->isChecked()) myModCmd=CMD_TX_WFM;
    if(ui->toggleNFM->isChecked()) myModCmd=CMD_TX_NFM;
    if(ui->toggleAM->isChecked())  myModCmd=CMD_TX_AM;
    if(ui->toggleLSB->isChecked()) myModCmd=CMD_TX_LSB;
    if(ui->toggleUSB->isChecked()) myModCmd=CMD_TX_USB;
    if(ui->toggleCW->isChecked()) myModCmd=CMD_TX_CW;
    if(ui->toggleCWR->isChecked()) myModCmd=CMD_TX_CWR;
    if(ui->toggleDSP->isChecked()) myModCmd=CMD_TX_DSP;
    if(ui->togglePKT->isChecked()) myModCmd=CMD_TX_PKT;
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
//*------------------------------------------------------------------------------------------------------------
//* updateFilterBw
//* update filter bandwidth based on the mode upon start or mode change, this is a static setting
//*-------------------------------------------------------------------------------------------------------------
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
    if(ui->toggleDSP->isChecked()) { ui->widgetFFT->filterLowCut=0; ui->widgetFFT->filterHighCut=4000; }
    if(ui->togglePKT->isChecked()) { ui->widgetFFT->filterLowCut=0; ui->widgetFFT->filterHighCut=4000; }
}

//*----------------------------------------------------------------------------------------------------------------------
//* setShift
//* computes shift between local oscillator and operating mode frequency
//*----------------------------------------------------------------------------------------------------------------------
void MainWindow::setShift()
{
    QString shiftString = QString::number(-ui->spinOffset->value()/(float)ui->comboSampRate->currentText().toInt())+"\n";
    write(fifoPipe,shiftString.toStdString().c_str(),shiftString.length());
    ui->widgetFFT->offsetFreq = ui->spinOffset->value();
}

//*-----------------------------------------------------------------------------------------------------------------
//* sendCommand
//* Manage RTL-SDR commands during operation
//* docs: https://github.com/pinkavaj/rtl-sdr/blob/master/src/rtl_tcp.c#L324
//*-----------------------------------------------------------------------------------------------------------------
void MainWindow::sendCommand(unsigned char cmd_num, unsigned value)
{
    unsigned char cmd[5];
    cmd[0] = cmd_num; //set_freq
    cmd[1] = (value>>24)&0xff;
    cmd[2] = (value>>16)&0xff;
    cmd[3] = (value>>8)&0xff;
    cmd[4] = value&0xff;
    procDistrib.write((char*)cmd, 5);
}
