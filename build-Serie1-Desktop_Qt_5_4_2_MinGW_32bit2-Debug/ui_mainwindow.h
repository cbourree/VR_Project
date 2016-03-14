/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButtonOpenCom;
    QPushButton *pushButtonCloseCom;
    QLineEdit *lineEditTx;
    QLineEdit *lineEditRx;
    QLabel *labelQuelComPort;
    QPushButton *pushButtonTx;
    QComboBox *cb_portSerie;
    QProgressBar *progressBar_1;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QProgressBar *progressBar_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QProgressBar *progressBar_6;
    QProgressBar *progressBar_7;
    QProgressBar *progressBar_8;
    QProgressBar *progressBar_9;
    QProgressBar *progressBar_10;
    QProgressBar *progressBar_11;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
    QLCDNumber *lcdNumber_5;
    QLCDNumber *lcdNumber_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(791, 306);
        MainWindow->setAnimated(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 46, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 46, 13));
        pushButtonOpenCom = new QPushButton(centralWidget);
        pushButtonOpenCom->setObjectName(QStringLiteral("pushButtonOpenCom"));
        pushButtonOpenCom->setGeometry(QRect(30, 150, 75, 23));
        pushButtonCloseCom = new QPushButton(centralWidget);
        pushButtonCloseCom->setObjectName(QStringLiteral("pushButtonCloseCom"));
        pushButtonCloseCom->setEnabled(false);
        pushButtonCloseCom->setGeometry(QRect(30, 180, 75, 23));
        lineEditTx = new QLineEdit(centralWidget);
        lineEditTx->setObjectName(QStringLiteral("lineEditTx"));
        lineEditTx->setGeometry(QRect(40, 50, 113, 20));
        lineEditRx = new QLineEdit(centralWidget);
        lineEditRx->setObjectName(QStringLiteral("lineEditRx"));
        lineEditRx->setGeometry(QRect(40, 20, 601, 20));
        lineEditRx->setReadOnly(true);
        labelQuelComPort = new QLabel(centralWidget);
        labelQuelComPort->setObjectName(QStringLiteral("labelQuelComPort"));
        labelQuelComPort->setGeometry(QRect(115, 182, 211, 21));
        pushButtonTx = new QPushButton(centralWidget);
        pushButtonTx->setObjectName(QStringLiteral("pushButtonTx"));
        pushButtonTx->setGeometry(QRect(170, 50, 75, 23));
        cb_portSerie = new QComboBox(centralWidget);
        cb_portSerie->setObjectName(QStringLiteral("cb_portSerie"));
        cb_portSerie->setGeometry(QRect(110, 150, 221, 22));
        progressBar_1 = new QProgressBar(centralWidget);
        progressBar_1->setObjectName(QStringLiteral("progressBar_1"));
        progressBar_1->setGeometry(QRect(470, 50, 16, 141));
        progressBar_1->setMinimum(0);
        progressBar_1->setMaximum(100);
        progressBar_1->setValue(1);
        progressBar_1->setTextVisible(false);
        progressBar_1->setOrientation(Qt::Vertical);
        progressBar_2 = new QProgressBar(centralWidget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(440, 50, 16, 141));
        progressBar_2->setValue(24);
        progressBar_2->setTextVisible(false);
        progressBar_2->setOrientation(Qt::Vertical);
        progressBar_3 = new QProgressBar(centralWidget);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(410, 50, 16, 141));
        progressBar_3->setValue(24);
        progressBar_3->setTextVisible(false);
        progressBar_3->setOrientation(Qt::Vertical);
        progressBar_4 = new QProgressBar(centralWidget);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setGeometry(QRect(380, 50, 16, 141));
        progressBar_4->setValue(24);
        progressBar_4->setTextVisible(false);
        progressBar_4->setOrientation(Qt::Vertical);
        progressBar_5 = new QProgressBar(centralWidget);
        progressBar_5->setObjectName(QStringLiteral("progressBar_5"));
        progressBar_5->setGeometry(QRect(340, 50, 16, 141));
        progressBar_5->setValue(24);
        progressBar_5->setTextVisible(false);
        progressBar_5->setOrientation(Qt::Vertical);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(460, 200, 31, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 200, 31, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(400, 200, 31, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 200, 31, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(330, 200, 31, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 50, 71, 23));
        progressBar_6 = new QProgressBar(centralWidget);
        progressBar_6->setObjectName(QStringLiteral("progressBar_6"));
        progressBar_6->setGeometry(QRect(560, 50, 16, 141));
        progressBar_6->setMinimum(-18000);
        progressBar_6->setMaximum(25000);
        progressBar_6->setValue(24);
        progressBar_6->setTextVisible(false);
        progressBar_6->setOrientation(Qt::Vertical);
        progressBar_7 = new QProgressBar(centralWidget);
        progressBar_7->setObjectName(QStringLiteral("progressBar_7"));
        progressBar_7->setGeometry(QRect(590, 50, 16, 141));
        progressBar_7->setMinimum(-17000);
        progressBar_7->setMaximum(18000);
        progressBar_7->setValue(24);
        progressBar_7->setTextVisible(false);
        progressBar_7->setOrientation(Qt::Vertical);
        progressBar_8 = new QProgressBar(centralWidget);
        progressBar_8->setObjectName(QStringLiteral("progressBar_8"));
        progressBar_8->setGeometry(QRect(620, 50, 16, 141));
        progressBar_8->setMinimum(-17000);
        progressBar_8->setMaximum(22000);
        progressBar_8->setValue(24);
        progressBar_8->setTextVisible(false);
        progressBar_8->setOrientation(Qt::Vertical);
        progressBar_9 = new QProgressBar(centralWidget);
        progressBar_9->setObjectName(QStringLiteral("progressBar_9"));
        progressBar_9->setGeometry(QRect(660, 50, 16, 141));
        progressBar_9->setMinimum(-35000);
        progressBar_9->setMaximum(40000);
        progressBar_9->setValue(24);
        progressBar_9->setTextVisible(false);
        progressBar_9->setOrientation(Qt::Vertical);
        progressBar_10 = new QProgressBar(centralWidget);
        progressBar_10->setObjectName(QStringLiteral("progressBar_10"));
        progressBar_10->setGeometry(QRect(690, 50, 16, 141));
        progressBar_10->setMinimum(-35000);
        progressBar_10->setMaximum(40000);
        progressBar_10->setValue(24);
        progressBar_10->setTextVisible(false);
        progressBar_10->setOrientation(Qt::Vertical);
        progressBar_11 = new QProgressBar(centralWidget);
        progressBar_11->setObjectName(QStringLiteral("progressBar_11"));
        progressBar_11->setGeometry(QRect(720, 50, 16, 141));
        progressBar_11->setMinimum(-35000);
        progressBar_11->setMaximum(40000);
        progressBar_11->setValue(24);
        progressBar_11->setTextVisible(false);
        progressBar_11->setOrientation(Qt::Vertical);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(560, 200, 16, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(590, 200, 16, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(620, 200, 16, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(660, 200, 16, 16));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(690, 200, 16, 16));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(720, 200, 16, 16));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(520, 220, 51, 23));
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(560, 250, 64, 23));
        lcdNumber_3 = new QLCDNumber(centralWidget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(590, 220, 64, 23));
        lcdNumber_4 = new QLCDNumber(centralWidget);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(640, 250, 64, 23));
        lcdNumber_5 = new QLCDNumber(centralWidget);
        lcdNumber_5->setObjectName(QStringLiteral("lcdNumber_5"));
        lcdNumber_5->setGeometry(QRect(670, 220, 64, 23));
        lcdNumber_6 = new QLCDNumber(centralWidget);
        lcdNumber_6->setObjectName(QStringLiteral("lcdNumber_6"));
        lcdNumber_6->setGeometry(QRect(710, 250, 64, 23));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), lineEditRx, SLOT(clear()));
        QObject::connect(progressBar_6, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(progressBar_7, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(progressBar_8, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));
        QObject::connect(progressBar_9, SIGNAL(valueChanged(int)), lcdNumber_4, SLOT(display(int)));
        QObject::connect(progressBar_10, SIGNAL(valueChanged(int)), lcdNumber_5, SLOT(display(int)));
        QObject::connect(progressBar_11, SIGNAL(valueChanged(int)), lcdNumber_6, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Tx", 0));
        label_2->setText(QApplication::translate("MainWindow", "Rx", 0));
        pushButtonOpenCom->setText(QApplication::translate("MainWindow", "Open", 0));
        pushButtonCloseCom->setText(QApplication::translate("MainWindow", "Close", 0));
        lineEditRx->setText(QString());
        labelQuelComPort->setText(QApplication::translate("MainWindow", "aucun", 0));
        pushButtonTx->setText(QApplication::translate("MainWindow", "Transmit", 0));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Clean", 0));
        label_8->setText(QApplication::translate("MainWindow", "AX", 0));
        label_9->setText(QApplication::translate("MainWindow", "AY", 0));
        label_10->setText(QApplication::translate("MainWindow", "AZ", 0));
        label_11->setText(QApplication::translate("MainWindow", "GX", 0));
        label_12->setText(QApplication::translate("MainWindow", "GY", 0));
        label_13->setText(QApplication::translate("MainWindow", "GZ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
