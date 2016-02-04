#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QByteArray>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->progressBar_1->setValue(65);
    ui->progressBar_2->setValue(65);
    ui->progressBar_3->setValue(65);
    ui->progressBar_4->setValue(65);
    ui->progressBar_5->setValue(65);


   // connect(&ComPort, SIGNAL(readyRead()), this, SLOT(receptionCmd()));

    connect(&ComPort, SIGNAL(readyRead()), this, SLOT(readData()));

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        Info = info;
        ui->cb_portSerie->addItem(Info.portName()+ " " +Info.description());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOpenCom_clicked()
{
    QSerialPortInfo Info;
    ui->lineEditRx->setText("");

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts() )
        {
             qDebug() << "Nom          : " << info.portName();
             qDebug() << "Description  : " << info.description();
             qDebug() << "Manufacturier: " << info.manufacturer();
             Info =  info;
             //ui->lineEditRx->setText(ui->lineEditRx->text() + Info.portName());
        }
    ui->labelQuelComPort->setText(portChoisi);
    ui->pushButtonCloseCom->setEnabled(true);
    ui->pushButtonOpenCom->setEnabled(false);
    qDebug() << "Port Sélectionné         : " << Info.portName();
    ComPort.setPortName(portChoisi);

    if(ComPort.open(QIODevice::ReadWrite))
    {
        ComPort.flush();
        ComPort.setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
        ComPort.setDataBits(QSerialPort::Data8);
        ComPort.setParity(QSerialPort::NoParity);
        ComPort.setFlowControl(QSerialPort::NoFlowControl);
    }
    else
        QMessageBox::critical(this, tr("Error"), ComPort.errorString());


}

void MainWindow::on_pushButtonCloseCom_clicked()
{
    ComPort.close();
    ui->labelQuelComPort->setText("aucun");
    ui->pushButtonOpenCom->setEnabled(true);
    ui->pushButtonCloseCom->setEnabled(false);
}

void MainWindow::on_pushButtonTx_clicked()
{
     ComPort.write((ui->lineEditTx->text().toLatin1()));
     ui->lineEditRx->setText("");
     QString s = Data.data();
     qDebug() << s.toLatin1();
}

void MainWindow::readData()
{
    Data = ComPort.readAll();
    //ui->lineEditRx->clear();
    ui->lineEditRx->setText(ui->lineEditRx->text() + Data.data());
}


void MainWindow::on_progressBar_1_valueChanged(int value)
{
    ui->label_3->setText(QString::number(value) + "%");
}

void MainWindow::on_progressBar_2_valueChanged(int value)
{
    ui->label_4->setText(QString::number(value) + "%");
}


void MainWindow::on_progressBar_3_valueChanged(int value)
{
    ui->label_5->setText(QString::number(value) + "%");
}

void MainWindow::on_progressBar_4_valueChanged(int value)
{
    ui->label_6->setText(QString::number(value) + "%");
}

void MainWindow::on_progressBar_5_valueChanged(int value)
{
    ui->label_7->setText(QString::number(value) + "%");
}

void MainWindow::on_cb_portSerie_currentTextChanged(const QString &arg1)
{
    QStringList port = arg1.split(" ");
    portChoisi = port[0];
}
