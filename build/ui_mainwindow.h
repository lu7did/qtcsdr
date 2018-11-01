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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
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
        label->setGeometry(QRect(0, 0, 111, 31));
        toggleAM = new QPushButton(widgetControls);
        toggleAM->setObjectName(QStringLiteral("toggleAM"));
        toggleAM->setGeometry(QRect(420, 0, 61, 31));
        toggleAM->setCheckable(true);
        label_2 = new QLabel(widgetControls);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 80, 111, 31));
        spinFreq = new QSpinBox(widgetControls);
        spinFreq->setObjectName(QStringLiteral("spinFreq"));
        spinFreq->setGeometry(QRect(120, 0, 171, 31));
        spinFreq->setMaximum(1999999999);
        spinFreq->setSingleStep(1000);
        spinFreq->setValue(89500000);
        spinOffset = new QSpinBox(widgetControls);
        spinOffset->setObjectName(QStringLiteral("spinOffset"));
        spinOffset->setGeometry(QRect(120, 80, 171, 31));
        spinOffset->setMinimum(-1200000);
        spinOffset->setMaximum(1200000);
        spinOffset->setSingleStep(100);
        spinOffset->setValue(200000);
        toggleWFM = new QPushButton(widgetControls);
        toggleWFM->setObjectName(QStringLiteral("toggleWFM"));
        toggleWFM->setGeometry(QRect(300, 0, 61, 31));
        toggleWFM->setCheckable(true);
        toggleWFM->setChecked(true);
        toggleUSB = new QPushButton(widgetControls);
        toggleUSB->setObjectName(QStringLiteral("toggleUSB"));
        toggleUSB->setGeometry(QRect(480, 0, 61, 31));
        toggleUSB->setCheckable(true);
        toggleLSB = new QPushButton(widgetControls);
        toggleLSB->setObjectName(QStringLiteral("toggleLSB"));
        toggleLSB->setGeometry(QRect(540, 0, 61, 31));
        toggleLSB->setCheckable(true);
        toggleRun = new QPushButton(widgetControls);
        toggleRun->setObjectName(QStringLiteral("toggleRun"));
        toggleRun->setGeometry(QRect(300, 80, 141, 71));
        toggleRun->setCheckable(true);
        toggleNFM = new QPushButton(widgetControls);
        toggleNFM->setObjectName(QStringLiteral("toggleNFM"));
        toggleNFM->setGeometry(QRect(360, 0, 61, 31));
        toggleNFM->setCheckable(true);
        spinCenter = new QSpinBox(widgetControls);
        spinCenter->setObjectName(QStringLiteral("spinCenter"));
        spinCenter->setGeometry(QRect(120, 40, 171, 31));
        spinCenter->setMaximum(1999999999);
        spinCenter->setSingleStep(1000);
        spinCenter->setValue(89300000);
        label_3 = new QLabel(widgetControls);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 40, 111, 31));
        comboDirectSamp = new QComboBox(widgetControls);
        comboDirectSamp->setObjectName(QStringLiteral("comboDirectSamp"));
        comboDirectSamp->setGeometry(QRect(300, 42, 301, 31));
        toggleTransmit = new QPushButton(widgetControls);
        toggleTransmit->setObjectName(QStringLiteral("toggleTransmit"));
        toggleTransmit->setEnabled(false);
        toggleTransmit->setGeometry(QRect(450, 80, 151, 71));
        toggleTransmit->setCheckable(true);
        label_4 = new QLabel(widgetControls);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 120, 121, 31));
        comboSampRate = new QComboBox(widgetControls);
        comboSampRate->setObjectName(QStringLiteral("comboSampRate"));
        comboSampRate->setGeometry(QRect(120, 120, 171, 31));

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
        toggleRun->setText(QApplication::translate("MainWindow", "Receive", Q_NULLPTR));
        toggleNFM->setText(QApplication::translate("MainWindow", "NFM", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Center:", Q_NULLPTR));
        comboDirectSamp->clear();
        comboDirectSamp->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Quadrature sampling", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Direct sampling (I branch)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Direct sampling (Q branch)", Q_NULLPTR)
        );
        toggleTransmit->setText(QApplication::translate("MainWindow", "Transmit", Q_NULLPTR));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
