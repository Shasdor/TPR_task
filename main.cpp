#include "mainwindow.h"
//#include "tsp_method.h"

#include <QApplication>
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
