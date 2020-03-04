#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setObjectName("Learning log");
    a.setApplicationName("Learning log");
    MainWindow w;

    w.show();

    return a.exec();
}
