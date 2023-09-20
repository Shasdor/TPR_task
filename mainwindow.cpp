#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <iostream>
#include <QPropertyAnimation>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground);

    //centralWidget(setGraphicsEffect(shadow));
    setWindowTitle("TPR");

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_menu_button_clicked()
{
    auto width = ui->slide_menu_container->width();
    std::cout<<width;
    auto newwidth=0;
    if (width==0){
        newwidth=200;
    }
    else{
        newwidth=0;
    }
    cout<<newwidth<<endl;
    QPropertyAnimation *animation= new  QPropertyAnimation(ui->slide_menu_container,"maximumWidth",this);
    animation->setDuration(250);
    animation->setStartValue(width);
    animation->setEndValue(newwidth);
    animation->setEasingCurve(QEasingCurve::InOutQuart);
    animation->start();
    //this->show();



}

void MainWindow::on_minimize_window_button_clicked()
{
    this->showMinimized();
}

void MainWindow::on_close_window_button_clicked()
{
    this->close();
}


void MainWindow::on_change_size_button_clicked()
{
    if(this->isMaximized()){
        this->showNormal();
        //change_size_button.setIcon();
    }
    else{
        this->showMaximized();
    }

}





