#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&ComPort, SIGNAL(readyRead()), this, SLOT(readData()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sendRequest()));

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        Info = info;
        ui->cb_portSerie->addItem(Info.portName()+ " " +Info.description());
    }

}

MainWindow::~MainWindow()
{
    ComPort.close();

    delete ui;
   // delete timer;
}

void MainWindow::readData()
{
    Data = ComPort.readAll();
   // ui->label_Mess->setText(ui->label_Mess->text() + Data.data());

}


void MainWindow::receptionCmd()
{

}

void MainWindow::sendRequest()
{
    /*if(ComPort.isOpen())
    {
        commande = "<ASK" + request + ">";
        ComPort.write(commande);
        ui->le_cmdToSend->setText(commande);
    }*/
}

void MainWindow::on_pb_Connecter_clicked()
{
    QSerialPortInfo Info;

     foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts() )
            {
                 qDebug() << "Nom          : " << info.portName();
                 qDebug() << "Description  : " << info.description();
                 qDebug() << "Manufacturier: " << info.manufacturer();
                 Info =  info;
            }
        //ui->labelQuelComPort->setText(Info.portName());
        ComPort.setPortName(Info.portName());
        if(ComPort.open(QIODevice::ReadWrite))
        {
         ComPort.flush();
     ComPort.setBaudRate(QSerialPort::Baud19200, QSerialPort::AllDirections);
         ComPort.setDataBits(QSerialPort::Data8);
         ComPort.setParity(QSerialPort::NoParity);
         ComPort.setFlowControl(QSerialPort::NoFlowControl);
        }
        else
            QMessageBox::critical(this, tr("Error"), ComPort.errorString());

}
