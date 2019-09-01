/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qmyspectrumwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMySpectrumWidget *widgetFFT;
    QWidget *widgetControls;
    QLabel *label;
    QPushButton *toggleAM;
    QLabel *label_2;
    QSpinBox *spinFreq;
    QSpinBox *spinOffset;
    QPushButton *toggleWFM;
    QPushButton *toggleUSB;
    QPushButton *toggleLSB;
    QPushButton *toggleRun;
    QPushButton *toggleNFM;
    QSpinBox *spinCenter;
    QLabel *label_3;
    QComboBox *comboDirectSamp;
    QPushButton *toggleTransmit;
    QLabel *label_4;
    QComboBox *comboSampRate;
    QPushButton *toggleCW;
    QPushButton *toggleCWR;
    QLCDNumber *lcdNumberPanel;
    QProgressBar *progressBarMeter;
    QPushButton *pushButtonAB;
    QPushButton *pushButtonA2B;
    QPushButton *pushButtonABS;
    QPushButton *pushButtonSplit;
    QPushButton *pushButtonRIT;
    QPushButton *pushButtonLock;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QPushButton *toggleBandVF;
    QPushButton *toggleBandLF;
    QPushButton *toggleBand160;
    QPushButton *toggleBand80;
    QPushButton *toggleBand40;
    QPushButton *toggleBand30;
    QPushButton *toggleBand20;
    QPushButton *toggleBand17;
    QPushButton *toggleBand15;
    QPushButton *toggleBand12;
    QPushButton *toggleBand10;
    QPushButton *toggleBand6;
    QPushButton *toggleBandFM;
    QPushButton *toggleBandAir;
    QPushButton *toggleBand2;
    QPushButton *toggleBand13;
    QPushButton *toggleBand70;
    QPushButton *toggleBand23;
    QPushButton *toggleDSP;
    QLabel *labelCAT;
    QLabel *labelPWR;
    QLabel *labelPTT;
    QLabel *labelVFO;
    QLabel *labelMODE;
    QLabel *labelMETER;
    QPushButton *pushButtonBreak;
    QPushButton *togglePKT;
    QDial *dial;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(621, 391);
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        widgetFFT = new QMySpectrumWidget(centralWidget);
        widgetFFT->setObjectName(QStringLiteral("widgetFFT"));

        verticalLayout->addWidget(widgetFFT);

        widgetControls = new QWidget(centralWidget);
        widgetControls->setObjectName(QStringLiteral("widgetControls"));
        widgetControls->setMinimumSize(QSize(603, 159));
        widgetControls->setMaximumSize(QSize(16777215, 159));
        QFont font1;
        font1.setPointSize(14);
        widgetControls->setFont(font1);
        label = new QLabel(widgetControls);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -4, 111, 31));
        QFont font2;
        font2.setPointSize(8);
        label->setFont(font2);
        toggleAM = new QPushButton(widgetControls);
        toggleAM->setObjectName(QStringLiteral("toggleAM"));
        toggleAM->setGeometry(QRect(360, -1, 30, 20));
        toggleAM->setFont(font2);
        toggleAM->setCheckable(true);
        label_2 = new QLabel(widgetControls);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 33, 111, 31));
        label_2->setFont(font2);
        spinFreq = new QSpinBox(widgetControls);
        spinFreq->setObjectName(QStringLiteral("spinFreq"));
        spinFreq->setGeometry(QRect(64, 0, 100, 20));
        spinFreq->setFont(font2);
        spinFreq->setMaximum(1999999999);
        spinFreq->setSingleStep(1000);
        spinFreq->setValue(89500000);
        spinOffset = new QSpinBox(widgetControls);
        spinOffset->setObjectName(QStringLiteral("spinOffset"));
        spinOffset->setGeometry(QRect(64, 40, 100, 20));
        spinOffset->setFont(font2);
        spinOffset->setMinimum(-1200000);
        spinOffset->setMaximum(1200000);
        spinOffset->setSingleStep(100);
        spinOffset->setValue(200000);
        toggleWFM = new QPushButton(widgetControls);
        toggleWFM->setObjectName(QStringLiteral("toggleWFM"));
        toggleWFM->setGeometry(QRect(300, -1, 30, 20));
        toggleWFM->setFont(font2);
        toggleWFM->setCheckable(true);
        toggleWFM->setChecked(false);
        toggleUSB = new QPushButton(widgetControls);
        toggleUSB->setObjectName(QStringLiteral("toggleUSB"));
        toggleUSB->setGeometry(QRect(390, -1, 30, 20));
        toggleUSB->setFont(font2);
        toggleUSB->setCheckable(true);
        toggleUSB->setChecked(true);
        toggleLSB = new QPushButton(widgetControls);
        toggleLSB->setObjectName(QStringLiteral("toggleLSB"));
        toggleLSB->setGeometry(QRect(420, -1, 30, 20));
        toggleLSB->setFont(font2);
        toggleLSB->setCheckable(true);
        toggleRun = new QPushButton(widgetControls);
        toggleRun->setObjectName(QStringLiteral("toggleRun"));
        toggleRun->setGeometry(QRect(300, 31, 50, 20));
        toggleRun->setFont(font2);
        toggleRun->setCheckable(true);
        toggleNFM = new QPushButton(widgetControls);
        toggleNFM->setObjectName(QStringLiteral("toggleNFM"));
        toggleNFM->setGeometry(QRect(330, -1, 30, 20));
        toggleNFM->setFont(font2);
        toggleNFM->setCheckable(true);
        spinCenter = new QSpinBox(widgetControls);
        spinCenter->setObjectName(QStringLiteral("spinCenter"));
        spinCenter->setGeometry(QRect(64, 20, 100, 20));
        spinCenter->setFont(font2);
        spinCenter->setMaximum(1999999999);
        spinCenter->setSingleStep(1000);
        spinCenter->setValue(89300000);
        label_3 = new QLabel(widgetControls);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 14, 111, 31));
        label_3->setFont(font2);
        comboDirectSamp = new QComboBox(widgetControls);
        comboDirectSamp->setObjectName(QStringLiteral("comboDirectSamp"));
        comboDirectSamp->setGeometry(QRect(64, 80, 100, 20));
        comboDirectSamp->setFont(font2);
        toggleTransmit = new QPushButton(widgetControls);
        toggleTransmit->setObjectName(QStringLiteral("toggleTransmit"));
        toggleTransmit->setEnabled(false);
        toggleTransmit->setGeometry(QRect(300, 51, 50, 20));
        toggleTransmit->setFont(font2);
        toggleTransmit->setCheckable(true);
        label_4 = new QLabel(widgetControls);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 55, 121, 31));
        label_4->setFont(font2);
        comboSampRate = new QComboBox(widgetControls);
        comboSampRate->setObjectName(QStringLiteral("comboSampRate"));
        comboSampRate->setGeometry(QRect(64, 60, 100, 20));
        comboSampRate->setFont(font2);
        toggleCW = new QPushButton(widgetControls);
        toggleCW->setObjectName(QStringLiteral("toggleCW"));
        toggleCW->setGeometry(QRect(450, -1, 30, 20));
        toggleCW->setFont(font2);
        toggleCW->setCheckable(true);
        toggleCWR = new QPushButton(widgetControls);
        toggleCWR->setObjectName(QStringLiteral("toggleCWR"));
        toggleCWR->setGeometry(QRect(480, -1, 30, 20));
        toggleCWR->setFont(font2);
        toggleCWR->setCheckable(true);
        lcdNumberPanel = new QLCDNumber(widgetControls);
        lcdNumberPanel->setObjectName(QStringLiteral("lcdNumberPanel"));
        lcdNumberPanel->setGeometry(QRect(360, 30, 231, 101));
        lcdNumberPanel->setSmallDecimalPoint(true);
        lcdNumberPanel->setDigitCount(7);
        progressBarMeter = new QProgressBar(widgetControls);
        progressBarMeter->setObjectName(QStringLiteral("progressBarMeter"));
        progressBarMeter->setGeometry(QRect(414, 34, 170, 8));
        progressBarMeter->setFont(font2);
        progressBarMeter->setValue(24);
        progressBarMeter->setTextVisible(false);
        pushButtonAB = new QPushButton(widgetControls);
        pushButtonAB->setObjectName(QStringLiteral("pushButtonAB"));
        pushButtonAB->setGeometry(QRect(300, 137, 40, 20));
        pushButtonAB->setFont(font2);
        pushButtonA2B = new QPushButton(widgetControls);
        pushButtonA2B->setObjectName(QStringLiteral("pushButtonA2B"));
        pushButtonA2B->setGeometry(QRect(340, 137, 40, 20));
        pushButtonA2B->setFont(font2);
        pushButtonABS = new QPushButton(widgetControls);
        pushButtonABS->setObjectName(QStringLiteral("pushButtonABS"));
        pushButtonABS->setGeometry(QRect(380, 137, 40, 20));
        pushButtonABS->setFont(font2);
        pushButtonSplit = new QPushButton(widgetControls);
        pushButtonSplit->setObjectName(QStringLiteral("pushButtonSplit"));
        pushButtonSplit->setGeometry(QRect(420, 137, 40, 20));
        pushButtonSplit->setFont(font2);
        pushButtonRIT = new QPushButton(widgetControls);
        pushButtonRIT->setObjectName(QStringLiteral("pushButtonRIT"));
        pushButtonRIT->setGeometry(QRect(460, 137, 40, 20));
        pushButtonRIT->setFont(font2);
        pushButtonLock = new QPushButton(widgetControls);
        pushButtonLock->setObjectName(QStringLiteral("pushButtonLock"));
        pushButtonLock->setGeometry(QRect(500, 137, 40, 20));
        pushButtonLock->setFont(font2);
        verticalSlider = new QSlider(widgetControls);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(173, 40, 20, 60));
        verticalSlider->setValue(10);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider_2 = new QSlider(widgetControls);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(195, 39, 20, 60));
        verticalSlider_2->setValue(99);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_3 = new QSlider(widgetControls);
        verticalSlider_3->setObjectName(QStringLiteral("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(216, 39, 20, 60));
        verticalSlider_3->setValue(75);
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_4 = new QSlider(widgetControls);
        verticalSlider_4->setObjectName(QStringLiteral("verticalSlider_4"));
        verticalSlider_4->setGeometry(QRect(238, 40, 20, 60));
        verticalSlider_4->setValue(25);
        verticalSlider_4->setOrientation(Qt::Vertical);
        verticalSlider_5 = new QSlider(widgetControls);
        verticalSlider_5->setObjectName(QStringLiteral("verticalSlider_5"));
        verticalSlider_5->setGeometry(QRect(260, 40, 20, 60));
        verticalSlider_5->setValue(50);
        verticalSlider_5->setOrientation(Qt::Vertical);
        toggleBandVF = new QPushButton(widgetControls);
        toggleBandVF->setObjectName(QStringLiteral("toggleBandVF"));
        toggleBandVF->setGeometry(QRect(10, 117, 30, 20));
        toggleBandVF->setFont(font2);
        toggleBandVF->setCheckable(true);
        toggleBandLF = new QPushButton(widgetControls);
        toggleBandLF->setObjectName(QStringLiteral("toggleBandLF"));
        toggleBandLF->setGeometry(QRect(40, 117, 30, 20));
        toggleBandLF->setFont(font2);
        toggleBandLF->setCheckable(true);
        toggleBand160 = new QPushButton(widgetControls);
        toggleBand160->setObjectName(QStringLiteral("toggleBand160"));
        toggleBand160->setGeometry(QRect(70, 117, 30, 20));
        toggleBand160->setFont(font2);
        toggleBand160->setCheckable(true);
        toggleBand80 = new QPushButton(widgetControls);
        toggleBand80->setObjectName(QStringLiteral("toggleBand80"));
        toggleBand80->setGeometry(QRect(100, 117, 30, 20));
        toggleBand80->setFont(font2);
        toggleBand80->setCheckable(true);
        toggleBand40 = new QPushButton(widgetControls);
        toggleBand40->setObjectName(QStringLiteral("toggleBand40"));
        toggleBand40->setGeometry(QRect(130, 117, 30, 20));
        toggleBand40->setFont(font2);
        toggleBand40->setCheckable(true);
        toggleBand30 = new QPushButton(widgetControls);
        toggleBand30->setObjectName(QStringLiteral("toggleBand30"));
        toggleBand30->setGeometry(QRect(160, 117, 30, 20));
        toggleBand30->setFont(font2);
        toggleBand30->setCheckable(true);
        toggleBand20 = new QPushButton(widgetControls);
        toggleBand20->setObjectName(QStringLiteral("toggleBand20"));
        toggleBand20->setGeometry(QRect(190, 117, 30, 20));
        toggleBand20->setFont(font2);
        toggleBand20->setCheckable(true);
        toggleBand17 = new QPushButton(widgetControls);
        toggleBand17->setObjectName(QStringLiteral("toggleBand17"));
        toggleBand17->setGeometry(QRect(220, 117, 30, 20));
        toggleBand17->setFont(font2);
        toggleBand17->setCheckable(true);
        toggleBand15 = new QPushButton(widgetControls);
        toggleBand15->setObjectName(QStringLiteral("toggleBand15"));
        toggleBand15->setGeometry(QRect(250, 117, 30, 20));
        toggleBand15->setFont(font2);
        toggleBand15->setCheckable(true);
        toggleBand12 = new QPushButton(widgetControls);
        toggleBand12->setObjectName(QStringLiteral("toggleBand12"));
        toggleBand12->setGeometry(QRect(10, 137, 30, 20));
        toggleBand12->setFont(font2);
        toggleBand12->setCheckable(true);
        toggleBand10 = new QPushButton(widgetControls);
        toggleBand10->setObjectName(QStringLiteral("toggleBand10"));
        toggleBand10->setGeometry(QRect(40, 137, 30, 20));
        toggleBand10->setFont(font2);
        toggleBand10->setCheckable(true);
        toggleBand6 = new QPushButton(widgetControls);
        toggleBand6->setObjectName(QStringLiteral("toggleBand6"));
        toggleBand6->setGeometry(QRect(70, 137, 30, 20));
        toggleBand6->setFont(font2);
        toggleBand6->setCheckable(true);
        toggleBandFM = new QPushButton(widgetControls);
        toggleBandFM->setObjectName(QStringLiteral("toggleBandFM"));
        toggleBandFM->setGeometry(QRect(100, 137, 30, 20));
        toggleBandFM->setFont(font2);
        toggleBandFM->setCheckable(true);
        toggleBandAir = new QPushButton(widgetControls);
        toggleBandAir->setObjectName(QStringLiteral("toggleBandAir"));
        toggleBandAir->setGeometry(QRect(130, 137, 30, 20));
        toggleBandAir->setFont(font2);
        toggleBandAir->setCheckable(true);
        toggleBand2 = new QPushButton(widgetControls);
        toggleBand2->setObjectName(QStringLiteral("toggleBand2"));
        toggleBand2->setGeometry(QRect(160, 137, 30, 20));
        toggleBand2->setFont(font2);
        toggleBand2->setCheckable(true);
        toggleBand13 = new QPushButton(widgetControls);
        toggleBand13->setObjectName(QStringLiteral("toggleBand13"));
        toggleBand13->setGeometry(QRect(190, 137, 30, 20));
        toggleBand13->setFont(font2);
        toggleBand13->setCheckable(true);
        toggleBand70 = new QPushButton(widgetControls);
        toggleBand70->setObjectName(QStringLiteral("toggleBand70"));
        toggleBand70->setGeometry(QRect(220, 137, 30, 20));
        toggleBand70->setFont(font2);
        toggleBand70->setCheckable(true);
        toggleBand23 = new QPushButton(widgetControls);
        toggleBand23->setObjectName(QStringLiteral("toggleBand23"));
        toggleBand23->setGeometry(QRect(250, 137, 30, 20));
        toggleBand23->setFont(font2);
        toggleBand23->setCheckable(true);
        toggleDSP = new QPushButton(widgetControls);
        toggleDSP->setObjectName(QStringLiteral("toggleDSP"));
        toggleDSP->setGeometry(QRect(510, -1, 30, 20));
        toggleDSP->setFont(font2);
        toggleDSP->setCheckable(true);
        labelCAT = new QLabel(widgetControls);
        labelCAT->setObjectName(QStringLiteral("labelCAT"));
        labelCAT->setGeometry(QRect(335, 20, 16, 10));
        labelCAT->setStyleSheet(QStringLiteral(""));
        labelCAT->setFrameShape(QFrame::Box);
        labelPWR = new QLabel(widgetControls);
        labelPWR->setObjectName(QStringLiteral("labelPWR"));
        labelPWR->setGeometry(QRect(301, 20, 16, 10));
        labelPWR->setStyleSheet(QStringLiteral(""));
        labelPWR->setFrameShape(QFrame::Box);
        labelPTT = new QLabel(widgetControls);
        labelPTT->setObjectName(QStringLiteral("labelPTT"));
        labelPTT->setGeometry(QRect(318, 20, 16, 10));
        labelPTT->setStyleSheet(QStringLiteral(""));
        labelPTT->setFrameShape(QFrame::Box);
        labelVFO = new QLabel(widgetControls);
        labelVFO->setObjectName(QStringLiteral("labelVFO"));
        labelVFO->setGeometry(QRect(393, 110, 31, 16));
        QFont font3;
        font3.setPointSize(7);
        font3.setBold(true);
        font3.setWeight(75);
        labelVFO->setFont(font3);
        labelMODE = new QLabel(widgetControls);
        labelMODE->setObjectName(QStringLiteral("labelMODE"));
        labelMODE->setGeometry(QRect(365, 110, 31, 16));
        labelMODE->setFont(font3);
        labelMETER = new QLabel(widgetControls);
        labelMETER->setObjectName(QStringLiteral("labelMETER"));
        labelMETER->setGeometry(QRect(365, 28, 40, 16));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        labelMETER->setFont(font4);
        pushButtonBreak = new QPushButton(widgetControls);
        pushButtonBreak->setObjectName(QStringLiteral("pushButtonBreak"));
        pushButtonBreak->setGeometry(QRect(540, 137, 40, 20));
        pushButtonBreak->setFont(font2);
        togglePKT = new QPushButton(widgetControls);
        togglePKT->setObjectName(QStringLiteral("togglePKT"));
        togglePKT->setGeometry(QRect(540, -1, 30, 20));
        togglePKT->setFont(font2);
        togglePKT->setCheckable(true);
        dial = new QDial(widgetControls);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(295, 72, 60, 60));
        dial->setOrientation(Qt::Horizontal);
        dial->setWrapping(true);
        dial->setNotchesVisible(false);
        label_5 = new QLabel(widgetControls);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(-1, 74, 121, 31));
        label_5->setFont(font2);
        label_4->raise();
        label->raise();
        toggleAM->raise();
        label_2->raise();
        spinFreq->raise();
        spinOffset->raise();
        toggleWFM->raise();
        toggleUSB->raise();
        toggleLSB->raise();
        toggleRun->raise();
        toggleNFM->raise();
        spinCenter->raise();
        label_3->raise();
        comboDirectSamp->raise();
        toggleTransmit->raise();
        comboSampRate->raise();
        toggleCW->raise();
        toggleCWR->raise();
        lcdNumberPanel->raise();
        progressBarMeter->raise();
        pushButtonAB->raise();
        pushButtonA2B->raise();
        pushButtonABS->raise();
        pushButtonSplit->raise();
        pushButtonRIT->raise();
        pushButtonLock->raise();
        verticalSlider->raise();
        verticalSlider_2->raise();
        verticalSlider_3->raise();
        verticalSlider_4->raise();
        verticalSlider_5->raise();
        toggleBandVF->raise();
        toggleBandLF->raise();
        toggleBand160->raise();
        toggleBand80->raise();
        toggleBand40->raise();
        toggleBand30->raise();
        toggleBand20->raise();
        toggleBand17->raise();
        toggleBand15->raise();
        toggleBand12->raise();
        toggleBand10->raise();
        toggleBand6->raise();
        toggleBandFM->raise();
        toggleBandAir->raise();
        toggleBand2->raise();
        toggleBand13->raise();
        toggleBand70->raise();
        toggleBand23->raise();
        toggleDSP->raise();
        labelCAT->raise();
        labelPWR->raise();
        labelPTT->raise();
        labelVFO->raise();
        labelMODE->raise();
        labelMETER->raise();
        pushButtonBreak->raise();
        togglePKT->raise();
        dial->raise();
        label_5->raise();

        verticalLayout->addWidget(widgetControls);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        comboSampRate->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "qtcsdr", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Frequency:", Q_NULLPTR));
        toggleAM->setText(QApplication::translate("MainWindow", "AM", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Offset:", Q_NULLPTR));
        toggleWFM->setText(QApplication::translate("MainWindow", "WFM", Q_NULLPTR));
        toggleUSB->setText(QApplication::translate("MainWindow", "USB", Q_NULLPTR));
        toggleLSB->setText(QApplication::translate("MainWindow", "LSB", Q_NULLPTR));
        toggleRun->setText(QApplication::translate("MainWindow", "Power", Q_NULLPTR));
        toggleNFM->setText(QApplication::translate("MainWindow", "NFM", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Center:", Q_NULLPTR));
        comboDirectSamp->clear();
        comboDirectSamp->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Quadrature sampling", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Direct sampling (I branch)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Direct sampling (Q branch)", Q_NULLPTR)
        );
        toggleTransmit->setText(QApplication::translate("MainWindow", "PTT", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Samp. rate:", Q_NULLPTR));
        comboSampRate->clear();
        comboSampRate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2400000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2048000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1200000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1024000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "960000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "480000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "240000", Q_NULLPTR)
        );
        toggleCW->setText(QApplication::translate("MainWindow", "CW", Q_NULLPTR));
        toggleCWR->setText(QApplication::translate("MainWindow", "CWR", Q_NULLPTR));
        progressBarMeter->setFormat(QApplication::translate("MainWindow", "%p", Q_NULLPTR));
        pushButtonAB->setText(QApplication::translate("MainWindow", "A/B", Q_NULLPTR));
        pushButtonA2B->setText(QApplication::translate("MainWindow", "A>B", Q_NULLPTR));
        pushButtonABS->setText(QApplication::translate("MainWindow", "A<>B", Q_NULLPTR));
        pushButtonSplit->setText(QApplication::translate("MainWindow", "Split", Q_NULLPTR));
        pushButtonRIT->setText(QApplication::translate("MainWindow", "RIT", Q_NULLPTR));
        pushButtonLock->setText(QApplication::translate("MainWindow", "Lock", Q_NULLPTR));
        toggleBandVF->setText(QApplication::translate("MainWindow", "VF", Q_NULLPTR));
        toggleBandLF->setText(QApplication::translate("MainWindow", "LF", Q_NULLPTR));
        toggleBand160->setText(QApplication::translate("MainWindow", "160", Q_NULLPTR));
        toggleBand80->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        toggleBand40->setText(QApplication::translate("MainWindow", "40", Q_NULLPTR));
        toggleBand30->setText(QApplication::translate("MainWindow", "30", Q_NULLPTR));
        toggleBand20->setText(QApplication::translate("MainWindow", "20", Q_NULLPTR));
        toggleBand17->setText(QApplication::translate("MainWindow", "17", Q_NULLPTR));
        toggleBand15->setText(QApplication::translate("MainWindow", "15", Q_NULLPTR));
        toggleBand12->setText(QApplication::translate("MainWindow", "12", Q_NULLPTR));
        toggleBand10->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        toggleBand6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        toggleBandFM->setText(QApplication::translate("MainWindow", "FM", Q_NULLPTR));
        toggleBandAir->setText(QApplication::translate("MainWindow", "Air", Q_NULLPTR));
        toggleBand2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        toggleBand13->setText(QApplication::translate("MainWindow", "1.3", Q_NULLPTR));
        toggleBand70->setText(QApplication::translate("MainWindow", "70", Q_NULLPTR));
        toggleBand23->setText(QApplication::translate("MainWindow", "23", Q_NULLPTR));
        toggleDSP->setText(QApplication::translate("MainWindow", "DSP", Q_NULLPTR));
        labelCAT->setText(QString());
        labelPWR->setText(QString());
        labelPTT->setText(QString());
        labelVFO->setText(QApplication::translate("MainWindow", "VFOA", Q_NULLPTR));
        labelMODE->setText(QApplication::translate("MainWindow", "USB", Q_NULLPTR));
        labelMETER->setText(QApplication::translate("MainWindow", "Meter", Q_NULLPTR));
        pushButtonBreak->setText(QApplication::translate("MainWindow", "Break", Q_NULLPTR));
        togglePKT->setText(QApplication::translate("MainWindow", "PKT", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Samp. type:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
