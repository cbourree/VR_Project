#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QThread>

#include <QtSerialPort/QtSerialPort>
#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void receptionCmd();
    void sendRequest();


private:
    Ui::MainWindow *ui;

    QSerialPortInfo Info;
    QSerialPort ComPort;
    QByteArray Data;


    QByteArray commande;
    QString portChoisi;

    QTimer *timer;
    QString cmdToSend;
    QString cmdReception;
    QByteArray request;

private slots:
    void readData();
    void on_pb_Connecter_clicked();
};

#endif // MAINWINDOW_H
