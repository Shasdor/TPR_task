#include "mainwindow.h"
#include "tsp_method.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <iostream>
#include <QPropertyAnimation>
#include <string>


QList<QList<QLineEdit*>> lineEditList;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



    //this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);


    //centralWidget(setGraphicsEffect(shadow));
    this->setWindowTitle("TPR");


    ui->setupUi(this);
    this->ui->k1_tsp->setValidator(new QIntValidator(0, 9999));
    this->ui->k2_tsp->setValidator(new QIntValidator(0, 9999));
    this->ui->k3_tsp->setValidator(new QIntValidator(0, 9999));
    this->ui->k1_tsp->setValidator(new QIntValidator(0, 9999));
    this->ui->k2_tsp->setValidator(new QIntValidator(0, 9999));



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
    tsp_method tsp;
    vector <vector <int>> distan =tsp.get_distan();
    generate_tsp_matrix(tsp.get_city());
    for (int i=0;i< tsp.get_city();i++){
        for (int j=0;j< tsp.get_city();j++){
            QLineEdit* lineEdit =lineEditList[i][j];
            QString text = QString::number(distan[i][j]);
//            QTextStream output(stdout);
//            output<<lineEdit->text();
            lineEdit->setText(text);
        }
    }
    this->ui->path_text->setText(tsp.show_path()+"\n"+tsp.show_path_cost());

}



void MainWindow::on_TSP_task_button_clicked()
{
    this->ui->TSP_frame->show();

}


void MainWindow::on_tsp_city_editingFinished()
{



}

void MainWindow::generate_tsp_matrix(int city_n){


    for (int i=0;i<city_n;i++){
        QList <QLineEdit*> lineEditList2;
        for (int j=0; j<city_n;j++){

            QLineEdit *lineEdit= new QLineEdit("0",this);
            lineEdit->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
            lineEdit->setAlignment(Qt::AlignLeft);
            lineEdit->setValidator(new QIntValidator(0, 9999));
            lineEdit->setMaxLength(5);
            QString name ="TSP_lineEdit_"+QString::number(i)+"_"+QString::number(j);
            lineEdit->setObjectName(name);
            ui->distan_matrix->addWidget(lineEdit,i,j);
            lineEditList2.append(lineEdit);
        }
        lineEditList.append(lineEditList2);
    }


}


void MainWindow::on_TSP_calculate_button_clicked()
{
    if ( ui->distan_matrix != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->distan_matrix->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
    this->update();

}

