#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <iostream>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground);
    //generate_base_tasks();

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
    auto newwidth=0;
    if (width==0){
        newwidth=200;
    }
    else{
        newwidth=0;
    }
    QPropertyAnimation *animation= new  QPropertyAnimation(ui->slide_menu_container,"maximumWidth",this);
    animation->setDuration(250);
    animation->setStartValue(width);
    animation->setEndValue(newwidth);
    animation->setEasingCurve(QEasingCurve::InOutQuart);
    animation->start();

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

void MainWindow::generate_base_tasks(){
    //this->ui->distan_matrix = new QGridLayout;
    //this->ui->distan_matrix->addWidget( QTextEdit);


}



void MainWindow::on_TSP_task_button_clicked()
{
    this->ui->TSP_frame->show();

}

