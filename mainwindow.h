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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//*----------------------------------------------------------------------------
//* Special macro definitions to adapt for previous code on the Arduino board
//*----------------------------------------------------------------------------
typedef unsigned char byte;
typedef bool boolean;

//*--- Function prototypes
void setWord(unsigned char* SysWord,unsigned char  v, bool val);
bool getWord (unsigned char SysWord, unsigned char v);


#include <QMainWindow>
#include <QPushButton>
#include <QProcess>
#include <QTimer>
#include <QTextStream>
#include <QSerialPort>
#include <cmath>
#include <wiringPi.h>
#include <QMessageBox>
#define RTLTCP_SET_FREQ 0x1
#define RTLTCP_SET_DIRECT_SAMPLING 0x9
#define SMETER_CALLIBRATION -20
#define STEP100HZ  100
#define STEP1KHZ   1000
#define STEP10KHZ  10000
#define STEP100KHZ 100000
#define STEP1MHZ   1000000

namespace Ui {


class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int  power2S(float s);
    Ui::MainWindow *ui;


private slots:
    void on_toggleWFM_toggled(bool checked);
    void on_toggleNFM_toggled(bool checked);
    void on_toggleAM_toggled(bool checked);
    void on_toggleUSB_toggled(bool checked);
    void on_toggleLSB_toggled(bool checked);
    void on_toggleCW_toggled(bool checked);
    void on_toggleCWR_toggled(bool checked);
    void on_toggleDSP_toggled(bool checked);
    void on_togglePKT_toggled(bool checked);


    void on_toggleBandVF_toggled(bool checked);
    void on_toggleBandLF_toggled(bool checked);
    void on_toggleBand160_toggled(bool checked);
    void on_toggleBand80_toggled(bool checked);
    void on_toggleBand40_toggled(bool checked);
    void on_toggleBand30_toggled(bool checked);
    void on_toggleBand20_toggled(bool checked);
    void on_toggleBand17_toggled(bool checked);
    void on_toggleBand15_toggled(bool checked);
    void on_toggleBand12_toggled(bool checked);
    void on_toggleBand10_toggled(bool checked);
    void on_toggleBand6_toggled(bool checked);
    void on_toggleBandFM_toggled(bool checked);
    void on_toggleBandAir_toggled(bool checked);
    void on_toggleBand2_toggled(bool checked);
    void on_toggleBand13_toggled(bool checked);
    void on_toggleBand70_toggled(bool checked);
    void on_toggleBand23_toggled(bool checked);



    void on_toggleRun_toggled(bool checked);
    void on_spinFreq_valueChanged(int val);
    void on_lcdNumberPanel_valueChanged(int val);
    void tmrRead_timeout();
    void setShift();
    void on_shiftChanged(int newOffset);

    void on_spinOffset_valueChanged(int arg1);

    void on_spinCenter_valueChanged(int arg1);

    void on_comboDirectSamp_currentIndexChanged(int index);

    void on_toggleTransmit_toggled(bool checked);
    void on_dial_valueChanged(int v);

    void openSerialPort();
    void closeSerialPort();
    //void about();
//*----------------
    void writeData(const QByteArray &data);
    void writeChar(byte d);
    void readData();
    void handleError(QSerialPort::SerialPortError error);
    void handleTimer();

private:
    QList<QPushButton*> modsButtons;
    QList<QPushButton*> bandButtons;

    void untoggleOtherModButtonsThan(QPushButton* pb);
    void untoggleOtherBandButtonsThan(QPushButton* pb);
    void sendCommand(unsigned char cmd_num, unsigned value);
    QString getDemodulatorCommand();
    void redirectProcessOutput(QProcess &proc, bool onlyStdErr = false);
    void updateFilterBw();


    void CATchangeFreq ();
    void CATchangeStatus();
    void CATchangeMode();
    void CATgetRX();
    void CATgetTX();

    void CATCallBack();

    QString  getNextArgAfter(QString what);
    QString  getModulatorCommand();
    QProcess procDemod;
    QProcess procDistrib;
    QProcess procIQServer;
    QProcess procFFT;
    QProcess procTX;
    //QProcess procMtr;
    QProcess procKillTX;
    QString fifoPipePath;
    QMessageBox critical;
    int fifoPipe;
    QTimer tmrRead;
    QTextStream qStdOut;
    QByteArray FFTDataBuffer;

    //QByteArray MTRDataBuffer;

    QString audioPlayerCommand;
    QString audioRecordCommand;
    QString alsaDevice;

    bool fchangeMode=false;
    bool running=true;

    int TSEC=10;
    int TCAT=20;
    int TBRK=30;

    QSerialPort *m_serial = nullptr;
    char* serialPortName=(char*)"/tmp/ttyv1";

    int  dialAnt=0;
    int  dialDelta=0;
    bool dialChanged=false;
    int  TDIAL=10;
    int  dialStep=STEP100HZ;
};

#endif // MAINWINDOW_H
