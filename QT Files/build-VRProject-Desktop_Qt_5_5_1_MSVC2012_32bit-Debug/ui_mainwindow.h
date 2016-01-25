/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *le_cmdToSend;
    QLineEdit *le_Reception;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *gb_CommSerie;
    QComboBox *cb_portSerie;
    QPushButton *pb_Connecter;
    QPushButton *pb_Rafraichir;
    QSlider *vs_doigt1;
    QSlider *vs_doigt2;
    QSlider *vs_doigt3;
    QSlider *vs_doigt4;
    QSlider *vs_doigt5;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(420, 226);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        le_cmdToSend = new QLineEdit(centralWidget);
        le_cmdToSend->setObjectName(QStringLiteral("le_cmdToSend"));
        le_cmdToSend->setGeometry(QRect(100, 110, 121, 22));
        le_Reception = new QLineEdit(centralWidget);
        le_Reception->setObjectName(QStringLiteral("le_Reception"));
        le_Reception->setGeometry(QRect(100, 140, 121, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 110, 101, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 140, 101, 21));
        label_8->setFont(font);
        gb_CommSerie = new QGroupBox(centralWidget);
        gb_CommSerie->setObjectName(QStringLiteral("gb_CommSerie"));
        gb_CommSerie->setGeometry(QRect(10, 10, 211, 91));
        cb_portSerie = new QComboBox(gb_CommSerie);
        cb_portSerie->setObjectName(QStringLiteral("cb_portSerie"));
        cb_portSerie->setGeometry(QRect(10, 20, 191, 22));
        pb_Connecter = new QPushButton(gb_CommSerie);
        pb_Connecter->setObjectName(QStringLiteral("pb_Connecter"));
        pb_Connecter->setGeometry(QRect(12, 50, 91, 28));
        pb_Rafraichir = new QPushButton(gb_CommSerie);
        pb_Rafraichir->setObjectName(QStringLiteral("pb_Rafraichir"));
        pb_Rafraichir->setGeometry(QRect(110, 50, 93, 28));
        vs_doigt1 = new QSlider(centralWidget);
        vs_doigt1->setObjectName(QStringLiteral("vs_doigt1"));
        vs_doigt1->setGeometry(QRect(250, 20, 19, 160));
        vs_doigt1->setOrientation(Qt::Vertical);
        vs_doigt2 = new QSlider(centralWidget);
        vs_doigt2->setObjectName(QStringLiteral("vs_doigt2"));
        vs_doigt2->setGeometry(QRect(280, 20, 19, 160));
        vs_doigt2->setOrientation(Qt::Vertical);
        vs_doigt3 = new QSlider(centralWidget);
        vs_doigt3->setObjectName(QStringLiteral("vs_doigt3"));
        vs_doigt3->setGeometry(QRect(310, 20, 19, 160));
        vs_doigt3->setOrientation(Qt::Vertical);
        vs_doigt4 = new QSlider(centralWidget);
        vs_doigt4->setObjectName(QStringLiteral("vs_doigt4"));
        vs_doigt4->setGeometry(QRect(340, 20, 19, 160));
        vs_doigt4->setOrientation(Qt::Vertical);
        vs_doigt5 = new QSlider(centralWidget);
        vs_doigt5->setObjectName(QStringLiteral("vs_doigt5"));
        vs_doigt5->setGeometry(QRect(370, 20, 19, 160));
        vs_doigt5->setOrientation(Qt::Vertical);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_7->setText(QApplication::translate("MainWindow", "Transmission   :", 0));
        label_8->setText(QApplication::translate("MainWindow", "R\303\251ception         : ", 0));
        gb_CommSerie->setTitle(QApplication::translate("MainWindow", "Communication S\303\251rie", 0));
        pb_Connecter->setText(QApplication::translate("MainWindow", "Connecter", 0));
        pb_Rafraichir->setText(QApplication::translate("MainWindow", "Rafraichir", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
