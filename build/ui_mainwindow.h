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
    QLabel *label_5;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QPushButton *pushButtonBandVF;
    QPushButton *pushButtonBandLF;
    QPushButton *pushButtonBand160;
    QPushButton *pushButtonBand80;
    QPushButton *pushButtonBand40;
    QPushButton *pushButtonBand30;
    QPushButton *pushButtonBand20;
    QPushButton *pushButtonBand17;
    QPushButton *pushButtonBand15;
    QPushButton *pushButtonBand12;
    QPushButton *pushButtonBand10;
    QPushButton *pushButtonBand6;
    QPushButton *pushButtonBandFM;
    QPushButton *pushButtonBandAir;
    QPushButton *pushButtonBand2;
    QPushButton *pushButtonBand70;
    QPushButton *pushButtonBand012;
    QPushButton *pushButtonBandFree;
    QPushButton *toggleDSP;

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
        toggleAM->setGeometry(QRect(360, 0, 30, 20));
        toggleAM->setFont(font2);
        toggleAM->setCheckable(true);
        label_2 = new QLabel(widgetControls);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 33, 111, 31));
        label_2->setFont(font2);
        spinFreq = new QSpinBox(widgetControls);
        spinFreq->setObjectName(QStringLiteral("spinFreq"));
        spinFreq->setGeometry(QRect(60, 0, 100, 20));
        spinFreq->setFont(font2);
        spinFreq->setMaximum(1999999999);
        spinFreq->setSingleStep(1000);
        spinFreq->setValue(89500000);
        spinOffset = new QSpinBox(widgetControls);
        spinOffset->setObjectName(QStringLiteral("spinOffset"));
        spinOffset->setGeometry(QRect(60, 40, 100, 20));
        spinOffset->setFont(font2);
        spinOffset->setMinimum(-1200000);
        spinOffset->setMaximum(1200000);
        spinOffset->setSingleStep(100);
        spinOffset->setValue(200000);
        toggleWFM = new QPushButton(widgetControls);
        toggleWFM->setObjectName(QStringLiteral("toggleWFM"));
        toggleWFM->setGeometry(QRect(300, 0, 30, 20));
        toggleWFM->setFont(font2);
        toggleWFM->setCheckable(true);
        toggleWFM->setChecked(false);
        toggleUSB = new QPushButton(widgetControls);
        toggleUSB->setObjectName(QStringLiteral("toggleUSB"));
        toggleUSB->setGeometry(QRect(390, 0, 30, 20));
        toggleUSB->setFont(font2);
        toggleUSB->setCheckable(true);
        toggleUSB->setChecked(true);
        toggleLSB = new QPushButton(widgetControls);
        toggleLSB->setObjectName(QStringLiteral("toggleLSB"));
        toggleLSB->setGeometry(QRect(420, 0, 30, 20));
        toggleLSB->setFont(font2);
        toggleLSB->setCheckable(true);
        toggleRun = new QPushButton(widgetControls);
        toggleRun->setObjectName(QStringLiteral("toggleRun"));
        toggleRun->setGeometry(QRect(300, 30, 50, 20));
        toggleRun->setFont(font2);
        toggleRun->setCheckable(true);
        toggleNFM = new QPushButton(widgetControls);
        toggleNFM->setObjectName(QStringLiteral("toggleNFM"));
        toggleNFM->setGeometry(QRect(330, 0, 30, 20));
        toggleNFM->setFont(font2);
        toggleNFM->setCheckable(true);
        spinCenter = new QSpinBox(widgetControls);
        spinCenter->setObjectName(QStringLiteral("spinCenter"));
        spinCenter->setGeometry(QRect(60, 20, 100, 20));
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
        comboDirectSamp->setGeometry(QRect(60, 80, 100, 20));
        comboDirectSamp->setFont(font2);
        toggleTransmit = new QPushButton(widgetControls);
        toggleTransmit->setObjectName(QStringLiteral("toggleTransmit"));
        toggleTransmit->setEnabled(false);
        toggleTransmit->setGeometry(QRect(300, 50, 50, 20));
        toggleTransmit->setFont(font2);
        toggleTransmit->setCheckable(true);
        label_4 = new QLabel(widgetControls);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 55, 121, 31));
        label_4->setFont(font2);
        comboSampRate = new QComboBox(widgetControls);
        comboSampRate->setObjectName(QStringLiteral("comboSampRate"));
        comboSampRate->setGeometry(QRect(60, 60, 100, 20));
        comboSampRate->setFont(font2);
        toggleCW = new QPushButton(widgetControls);
        toggleCW->setObjectName(QStringLiteral("toggleCW"));
        toggleCW->setGeometry(QRect(450, 0, 30, 20));
        toggleCW->setFont(font2);
        toggleCW->setCheckable(true);
        toggleCWR = new QPushButton(widgetControls);
        toggleCWR->setObjectName(QStringLiteral("toggleCWR"));
        toggleCWR->setGeometry(QRect(480, 0, 30, 20));
        toggleCWR->setFont(font2);
        toggleCWR->setCheckable(true);
        lcdNumberPanel = new QLCDNumber(widgetControls);
        lcdNumberPanel->setObjectName(QStringLiteral("lcdNumberPanel"));
        lcdNumberPanel->setGeometry(QRect(360, 30, 231, 71));
        lcdNumberPanel->setSmallDecimalPoint(true);
        lcdNumberPanel->setDigitCount(7);
        progressBarMeter = new QProgressBar(widgetControls);
        progressBarMeter->setObjectName(QStringLiteral("progressBarMeter"));
        progressBarMeter->setGeometry(QRect(360, 110, 231, 15));
        progressBarMeter->setFont(font2);
        progressBarMeter->setValue(24);
        progressBarMeter->setTextVisible(false);
        pushButtonAB = new QPushButton(widgetControls);
        pushButtonAB->setObjectName(QStringLiteral("pushButtonAB"));
        pushButtonAB->setGeometry(QRect(300, 130, 40, 20));
        pushButtonAB->setFont(font2);
        pushButtonA2B = new QPushButton(widgetControls);
        pushButtonA2B->setObjectName(QStringLiteral("pushButtonA2B"));
        pushButtonA2B->setGeometry(QRect(350, 130, 40, 20));
        pushButtonA2B->setFont(font2);
        pushButtonABS = new QPushButton(widgetControls);
        pushButtonABS->setObjectName(QStringLiteral("pushButtonABS"));
        pushButtonABS->setGeometry(QRect(400, 130, 40, 20));
        pushButtonABS->setFont(font2);
        pushButtonSplit = new QPushButton(widgetControls);
        pushButtonSplit->setObjectName(QStringLiteral("pushButtonSplit"));
        pushButtonSplit->setGeometry(QRect(450, 130, 40, 20));
        pushButtonSplit->setFont(font2);
        pushButtonRIT = new QPushButton(widgetControls);
        pushButtonRIT->setObjectName(QStringLiteral("pushButtonRIT"));
        pushButtonRIT->setGeometry(QRect(500, 130, 40, 20));
        pushButtonRIT->setFont(font2);
        pushButtonLock = new QPushButton(widgetControls);
        pushButtonLock->setObjectName(QStringLiteral("pushButtonLock"));
        pushButtonLock->setGeometry(QRect(550, 130, 40, 20));
        pushButtonLock->setFont(font2);
        label_5 = new QLabel(widgetControls);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 110, 48, 15));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setWeight(50);
        label_5->setFont(font3);
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
        pushButtonBandVF = new QPushButton(widgetControls);
        pushButtonBandVF->setObjectName(QStringLiteral("pushButtonBandVF"));
        pushButtonBandVF->setGeometry(QRect(10, 110, 30, 20));
        pushButtonBandVF->setFont(font2);
        pushButtonBandLF = new QPushButton(widgetControls);
        pushButtonBandLF->setObjectName(QStringLiteral("pushButtonBandLF"));
        pushButtonBandLF->setGeometry(QRect(40, 110, 30, 20));
        pushButtonBandLF->setFont(font2);
        pushButtonBand160 = new QPushButton(widgetControls);
        pushButtonBand160->setObjectName(QStringLiteral("pushButtonBand160"));
        pushButtonBand160->setGeometry(QRect(70, 110, 30, 20));
        pushButtonBand160->setFont(font2);
        pushButtonBand80 = new QPushButton(widgetControls);
        pushButtonBand80->setObjectName(QStringLiteral("pushButtonBand80"));
        pushButtonBand80->setGeometry(QRect(100, 110, 30, 20));
        pushButtonBand80->setFont(font2);
        pushButtonBand40 = new QPushButton(widgetControls);
        pushButtonBand40->setObjectName(QStringLiteral("pushButtonBand40"));
        pushButtonBand40->setGeometry(QRect(130, 110, 30, 20));
        pushButtonBand40->setFont(font2);
        pushButtonBand30 = new QPushButton(widgetControls);
        pushButtonBand30->setObjectName(QStringLiteral("pushButtonBand30"));
        pushButtonBand30->setGeometry(QRect(160, 110, 30, 20));
        pushButtonBand30->setFont(font2);
        pushButtonBand20 = new QPushButton(widgetControls);
        pushButtonBand20->setObjectName(QStringLiteral("pushButtonBand20"));
        pushButtonBand20->setGeometry(QRect(190, 110, 30, 20));
        pushButtonBand20->setFont(font2);
        pushButtonBand17 = new QPushButton(widgetControls);
        pushButtonBand17->setObjectName(QStringLiteral("pushButtonBand17"));
        pushButtonBand17->setGeometry(QRect(220, 110, 30, 20));
        pushButtonBand17->setFont(font2);
        pushButtonBand15 = new QPushButton(widgetControls);
        pushButtonBand15->setObjectName(QStringLiteral("pushButtonBand15"));
        pushButtonBand15->setGeometry(QRect(250, 110, 30, 20));
        pushButtonBand15->setFont(font2);
        pushButtonBand12 = new QPushButton(widgetControls);
        pushButtonBand12->setObjectName(QStringLiteral("pushButtonBand12"));
        pushButtonBand12->setGeometry(QRect(10, 130, 30, 20));
        pushButtonBand12->setFont(font2);
        pushButtonBand10 = new QPushButton(widgetControls);
        pushButtonBand10->setObjectName(QStringLiteral("pushButtonBand10"));
        pushButtonBand10->setGeometry(QRect(40, 130, 30, 20));
        pushButtonBand10->setFont(font2);
        pushButtonBand6 = new QPushButton(widgetControls);
        pushButtonBand6->setObjectName(QStringLiteral("pushButtonBand6"));
        pushButtonBand6->setGeometry(QRect(70, 130, 30, 20));
        pushButtonBand6->setFont(font2);
        pushButtonBandFM = new QPushButton(widgetControls);
        pushButtonBandFM->setObjectName(QStringLiteral("pushButtonBandFM"));
        pushButtonBandFM->setGeometry(QRect(100, 130, 30, 20));
        pushButtonBandFM->setFont(font2);
        pushButtonBandAir = new QPushButton(widgetControls);
        pushButtonBandAir->setObjectName(QStringLiteral("pushButtonBandAir"));
        pushButtonBandAir->setGeometry(QRect(130, 130, 30, 20));
        pushButtonBandAir->setFont(font2);
        pushButtonBand2 = new QPushButton(widgetControls);
        pushButtonBand2->setObjectName(QStringLiteral("pushButtonBand2"));
        pushButtonBand2->setGeometry(QRect(160, 130, 30, 20));
        pushButtonBand2->setFont(font2);
        pushButtonBand70 = new QPushButton(widgetControls);
        pushButtonBand70->setObjectName(QStringLiteral("pushButtonBand70"));
        pushButtonBand70->setGeometry(QRect(190, 130, 30, 20));
        pushButtonBand70->setFont(font2);
        pushButtonBand012 = new QPushButton(widgetControls);
        pushButtonBand012->setObjectName(QStringLiteral("pushButtonBand012"));
        pushButtonBand012->setGeometry(QRect(220, 130, 30, 20));
        pushButtonBand012->setFont(font2);
        pushButtonBandFree = new QPushButton(widgetControls);
        pushButtonBandFree->setObjectName(QStringLiteral("pushButtonBandFree"));
        pushButtonBandFree->setGeometry(QRect(250, 130, 30, 20));
        pushButtonBandFree->setFont(font2);
        toggleDSP = new QPushButton(widgetControls);
        toggleDSP->setObjectName(QStringLiteral("toggleDSP"));
        toggleDSP->setGeometry(QRect(510, 0, 30, 20));
        toggleDSP->setFont(font2);
        toggleDSP->setCheckable(true);

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
        label_5->setText(QApplication::translate("MainWindow", "Meter", Q_NULLPTR));
        pushButtonBandVF->setText(QApplication::translate("MainWindow", "VF", Q_NULLPTR));
        pushButtonBandLF->setText(QApplication::translate("MainWindow", "LF", Q_NULLPTR));
        pushButtonBand160->setText(QApplication::translate("MainWindow", "160", Q_NULLPTR));
        pushButtonBand80->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        pushButtonBand40->setText(QApplication::translate("MainWindow", "40", Q_NULLPTR));
        pushButtonBand30->setText(QApplication::translate("MainWindow", "30", Q_NULLPTR));
        pushButtonBand20->setText(QApplication::translate("MainWindow", "20", Q_NULLPTR));
        pushButtonBand17->setText(QApplication::translate("MainWindow", "17", Q_NULLPTR));
        pushButtonBand15->setText(QApplication::translate("MainWindow", "15", Q_NULLPTR));
        pushButtonBand12->setText(QApplication::translate("MainWindow", "12", Q_NULLPTR));
        pushButtonBand10->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        pushButtonBand6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        pushButtonBandFM->setText(QApplication::translate("MainWindow", "FM", Q_NULLPTR));
        pushButtonBandAir->setText(QApplication::translate("MainWindow", "Air", Q_NULLPTR));
        pushButtonBand2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButtonBand70->setText(QApplication::translate("MainWindow", "70", Q_NULLPTR));
        pushButtonBand012->setText(QApplication::translate("MainWindow", "1.2", Q_NULLPTR));
        pushButtonBandFree->setText(QApplication::translate("MainWindow", "Free", Q_NULLPTR));
        toggleDSP->setText(QApplication::translate("MainWindow", "DSP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
