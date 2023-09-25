#include "mainwindow.h"
#include "tsp_method.h"

#include <QApplication>
#include <string>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.generate_base_tasks();
    w.show();


    return a.exec();
}
