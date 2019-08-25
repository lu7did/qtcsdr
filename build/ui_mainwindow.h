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
    QPushButton *toggleLSB_2;
    QPushButton *toggleLSB_3;
    QLCDNumber *lcdNumber;
    QProgressBar *progressBarMeter;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
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
        toggleAM->setGeometry(QRect(360, 0, 30, 20));
        toggleAM->setFont(font2);
        toggleAM->setCheckable(true);
        label_2 = new QLabel(widgetControls);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 25, 111, 31));
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
        label_3->setGeometry(QRect(0, 10, 111, 31));
        label_3->setFont(font2);
        comboDirectSamp = new QComboBox(widgetControls);
        comboDirectSamp->setObjectName(QStringLiteral("comboDirectSamp"));
        comboDirectSamp->setGeometry(QRect(513, 0, 81, 20));
        comboDirectSamp->setFont(font2);
        toggleTransmit = new QPushButton(widgetControls);
        toggleTransmit->setObjectName(QStringLiteral("toggleTransmit"));
        toggleTransmit->setEnabled(false);
        toggleTransmit->setGeometry(QRect(300, 50, 50, 20));
        toggleTransmit->setFont(font2);
        toggleTransmit->setCheckable(true);
        label_4 = new QLabel(widgetControls);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 39, 121, 31));
        label_4->setFont(font2);
        comboSampRate = new QComboBox(widgetControls);
        comboSampRate->setObjectName(QStringLiteral("comboSampRate"));
        comboSampRate->setGeometry(QRect(60, 60, 100, 20));
        comboSampRate->setFont(font2);
        toggleLSB_2 = new QPushButton(widgetControls);
        toggleLSB_2->setObjectName(QStringLiteral("toggleLSB_2"));
        toggleLSB_2->setGeometry(QRect(450, 0, 30, 20));
        toggleLSB_2->setFont(font2);
        toggleLSB_2->setCheckable(true);
        toggleLSB_3 = new QPushButton(widgetControls);
        toggleLSB_3->setObjectName(QStringLiteral("toggleLSB_3"));
        toggleLSB_3->setGeometry(QRect(480, 0, 30, 20));
        toggleLSB_3->setFont(font2);
        toggleLSB_3->setCheckable(true);
        lcdNumber = new QLCDNumber(widgetControls);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(360, 30, 231, 71));
        progressBarMeter = new QProgressBar(widgetControls);
        progressBarMeter->setObjectName(QStringLiteral("progressBarMeter"));
        progressBarMeter->setGeometry(QRect(360, 110, 231, 15));
        progressBarMeter->setFont(font2);
        progressBarMeter->setValue(24);
        pushButton = new QPushButton(widgetControls);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 130, 40, 20));
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(widgetControls);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 130, 40, 20));
        pushButton_2->setFont(font2);
        pushButton_3 = new QPushButton(widgetControls);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(400, 130, 40, 20));
        pushButton_3->setFont(font2);
        pushButton_4 = new QPushButton(widgetControls);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(450, 130, 40, 20));
        pushButton_4->setFont(font2);
        pushButton_5 = new QPushButton(widgetControls);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(500, 130, 40, 20));
        pushButton_5->setFont(font2);
        pushButton_6 = new QPushButton(widgetControls);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(550, 130, 40, 20));
        pushButton_6->setFont(font2);
        label_5 = new QLabel(widgetControls);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 110, 48, 15));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setWeight(50);
        label_5->setFont(font3);

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
        toggleLSB_2->setText(QApplication::translate("MainWindow", "CW", Q_NULLPTR));
        toggleLSB_3->setText(QApplication::translate("MainWindow", "CWR", Q_NULLPTR));
        progressBarMeter->setFormat(QApplication::translate("MainWindow", "%p", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "A/B", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "A>B", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "A<>B", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Split", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "RIT", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Lock", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Meter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
