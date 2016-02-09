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
    if(ComPort.bytesAvailable() > 83)
    {
        Data = ComPort.readLine(85);
        cmdReception = Data.data();
        ui->lineEditRx->clear();
        qDebug() << cmdReception;
        ui->lineEditRx->setText(Data.data());

        doigt1 = (QString(cmdReception[1]).toFloat()) + (QString(cmdReception[3]).toFloat()*0.1) + (QString(cmdReception[4]).toFloat()*0.01);
        doigt1 = 100-((doigt1-2.21)*100)/1.64;

        doigt2 = (QString(cmdReception[7]).toFloat()) + (QString(cmdReception[9]).toFloat()*0.1) + (QString(cmdReception[10]).toFloat()*0.01);
        doigt2 = 100-((doigt2-2.21)*100)/1.64;

        doigt3 = (QString(cmdReception[13]).toFloat()) + (QString(cmdReception[15]).toFloat()*0.1) + (QString(cmdReception[16]).toFloat()*0.01);
        doigt3 = 100-((doigt3-2.21)*100)/1.64;

        doigt4 = (QString(cmdReception[19]).toFloat()) + (QString(cmdReception[21]).toFloat()*0.1) + (QString(cmdReception[22]).toFloat()*0.01);
        doigt4 = 100-((doigt4-2.21)*100)/1.64;


        AX = (QString(cmdReception[27]).toInt() * 10000) + (QString(cmdReception[28]).toInt()*1000) + (QString(cmdReception[29]).toInt()*100) + (QString(cmdReception[30]).toInt()*10) + (QString(cmdReception[31]).toInt());
        AX = (QString(cmdReception[26]) == "-") ? -AX : AX;

        AY = (QString(cmdReception[37]).toInt() * 10000) + (QString(cmdReception[38]).toInt()*1000) + (QString(cmdReception[39]).toInt()*100) + (QString(cmdReception[40]).toInt()*10) + (QString(cmdReception[41]).toInt());
        AY = (QString(cmdReception[36]) == "-") ? -AY : AY;

        AZ = (QString(cmdReception[47]).toInt() * 10000) + (QString(cmdReception[48]).toInt()*1000) + (QString(cmdReception[49]).toInt()*100) + (QString(cmdReception[50]).toInt()*10) + (QString(cmdReception[51]).toInt());
        AZ = (QString(cmdReception[46]) == "-") ? -AZ : AZ;

        GX = (QString(cmdReception[57]).toInt() * 10000) + (QString(cmdReception[58]).toInt()*1000) + (QString(cmdReception[59]).toInt()*100) + (QString(cmdReception[60]).toInt()*10) + (QString(cmdReception[61]).toInt());
        GX = (QString(cmdReception[56]) == "-") ? -GX : GX;

        GY = (QString(cmdReception[67]).toInt() * 10000) + (QString(cmdReception[68]).toInt()*1000) + (QString(cmdReception[69]).toInt()*100) + (QString(cmdReception[70]).toInt()*10) + (QString(cmdReception[71]).toInt());
        GY = (QString(cmdReception[66]) == "-") ? -GY : GY;

        GZ = (QString(cmdReception[77]).toInt() * 10000) + (QString(cmdReception[78]).toInt()*1000) + (QString(cmdReception[79]).toInt()*100) + (QString(cmdReception[80]).toInt()*10) + (QString(cmdReception[81]).toInt());
        GZ = (QString(cmdReception[76]) == "-") ? -GZ : GZ;

        ui->lineEditTx->setText(QString(cmdReception[26]));
        ui->progressBar_1->setValue(doigt1);
        ui->progressBar_2->setValue(doigt2);
        ui->progressBar_3->setValue(doigt3);
        ui->progressBar_4->setValue(doigt4);

        ui->progressBar_6->setValue(AX);
        ui->progressBar_7->setValue(AY);
        ui->progressBar_8->setValue(AZ);
        ui->progressBar_9->setValue(GX);
        ui->progressBar_10->setValue(GY);
        ui->progressBar_11->setValue(GZ);
    }
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
