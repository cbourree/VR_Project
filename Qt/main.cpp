#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.width(), w.height());
    w.setWindowTitle("VR_Project by Sebastien and Charles");
    w.show();

    return a.exec();
}
