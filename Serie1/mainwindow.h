#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QtGlobal>
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
    void on_pushButtonOpenCom_clicked();
    void on_pushButtonCloseCom_clicked();
    void on_pushButtonTx_clicked();
    void readData();

    void on_progressBar_1_valueChanged(int value);

    void on_progressBar_2_valueChanged(int value);

    void on_progressBar_3_valueChanged(int value);

    void on_progressBar_4_valueChanged(int value);

    void on_progressBar_5_valueChanged(int value);

    void on_cb_portSerie_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSerialPortInfo Info;
    QSerialPort ComPort;
    QByteArray Data;

    QString portChoisi;
    QString cmdReception;

    float doigt1;
    float doigt2;
    float doigt3;
    float doigt4;
    float doigt5;
};

#endif // MAINWINDOW_H
