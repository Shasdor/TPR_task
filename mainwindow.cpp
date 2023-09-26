#include "mainwindow.h"
#include "tsp_method.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <iostream>
#include <QPropertyAnimation>
#include <string>
#include <QDesktopServices>
tsp_method tsp;
QList<QList<QLineEdit*>> lineEditList;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    //centralWidget(setGraphicsEffect(shadow));
    this->setWindowTitle("TPR");
    ui->setupUi(this);
    this->ui->k1_tsp->setValidator(new QIntValidator(0, 9999));
    this->ui->k2_tsp->setValidator(new QIntValidator(0, 9999));
    this->ui->k3_tsp->setValidator(new QIntValidator(0, 9999));
    this->ui->k1_tsp->setValidator(new QIntValidator(0, 9999));
    this->ui->k2_tsp->setValidator(new QIntValidator(0, 9999));
    //his->ui->TSP_frame->hide();
//    this->ui->Header->grabMouse()=this->moveWindow();
    this->ui->k1_frame->hide();
    this->ui->k2_frame->hide();
    this->ui->k3_frame->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menu_button_clicked()
{
    auto width = ui->slide_menu_container->width();
    auto newwidth=0;
    if (width==0)
    {
        newwidth=200;
    }
    else
    {
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
    this->show();
}

void MainWindow::on_close_window_button_clicked()
{
    this->close();
}

void MainWindow::on_change_size_button_clicked()
{
    if(this->isMaximized())
    {
        this->showNormal();
        //change_size_button.setIcon();
    }
    else
    {
        this->showMaximized();
    }
    this->show();
}

void MainWindow::generate_base_tasks()
{
    this->generate_tsp_matrix(tsp.get_city());
    this->do_TSP();
}

void MainWindow::on_TSP_task_button_clicked()
{
    this->ui->Main_Window_frame->hide();
    this->ui->TSP_frame->show();
}


void MainWindow::on_tsp_city_editingFinished()
{
    //tsp.change_city_n(this->ui->tsp_city->text().toInt());
    int change =tsp.get_city()-this->ui->tsp_city->value();
    this->resize_TSP_matrix(change);
}

void MainWindow::generate_tsp_matrix(int city_n){
    lineEditList.clear();
//    this->clear_matrix();
    for (int i=0;i<city_n;i++){
        QList <QLineEdit*> lineEditList2;
        for (int j=0; j<city_n;j++)
        {
            QLineEdit *lineEdit= create_cell_for_TSP(i,j);
            ui->distan_matrix->addWidget(lineEdit,i,j);
            lineEditList2.append(lineEdit);
        }
        lineEditList.append(lineEditList2);
    }
    this->update();
}


void MainWindow::on_TSP_calculate_button_clicked()
{
    vector <vector <int>> distan;
    for (int i=0;i<tsp.get_city();i++){
        vector <int> sub_dist;
        for (int j=0;j<tsp.get_city();j++){
            QLineEdit* lineEdit =lineEditList[i][j];
            sub_dist.push_back(lineEdit->text().toInt());
        }
        distan.push_back(sub_dist);
    }
    tsp.new_distan(distan);
    tsp.do_TSP();
    this->ui->path_text->clear();
    this->ui->path_text->setText(tsp.show_path()+"\n"+tsp.show_path_cost());

}

void MainWindow::on_github_site_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Jasdor/TPR_task"));
}


void MainWindow::on_TSP_deafult_button_clicked()
{
    tsp.return_to_base_param();
    this->do_TSP();
}

void MainWindow::do_TSP()
{
    //this->clear_matrix();
    vector <vector <int>> distan =tsp.get_distan();
    for (int i=0;i< tsp.get_city();i++){
        for (int j=0;j< tsp.get_city();j++){
            QLineEdit* lineEdit =lineEditList[i][j];
            QString text = QString::number(distan[i][j]);
            lineEdit->setText(text);
        }
    }
    this->ui->path_text->clear();
    this->ui->path_text->setText(tsp.show_path()+"\n"+tsp.show_path_cost());
}

//void MainWindow::clear_matrix(){
//    if ( ui->distan_matrix != NULL )
//    {
//        QLayoutItem* item;
//        while ( ( item = ui->distan_matrix->takeAt( 0 ) ) != NULL )
//        {

//            delete item->widget();
//            delete item;
//        }
//    }
//    this->update();
//}

void MainWindow::resize_TSP_matrix(int change){

    if (change>0){
        for (int i=0; i<change; i++){
            for (int j=0;j<(tsp.get_city()-i);j++){

                if ((ui->distan_matrix->itemAtPosition(tsp.get_city()-i-1,j)!=NULL)){
                    QLayoutItem* item;
                    item = ui->distan_matrix->itemAtPosition(tsp.get_city()-i-1,j);
                    delete item->widget();
                }
                if ((ui->distan_matrix->itemAtPosition(j,tsp.get_city()-i-1))!=NULL){
                    QLayoutItem* item;
                    item = ui->distan_matrix->itemAtPosition(j,tsp.get_city()-i-1);
                    delete item->widget();
                }
                lineEditList[j].removeLast();
            }
            lineEditList.removeLast();
        }
    }
    else{
        for (int i=tsp.get_city();i<(tsp.get_city()-change);i++){
            QList <QLineEdit*> lineEditList2;
            for (int j=0; j<tsp.get_city()-change;j++)
            {
                QLineEdit *lineEdit= create_cell_for_TSP(i,j);
                ui->distan_matrix->addWidget(lineEdit,i,j);
                lineEditList2.append(lineEdit);
            }

            lineEditList.append(lineEditList2);
        }
        for (int i=tsp.get_city();i<(tsp.get_city()-change);i++){
            for (int j=0; j<tsp.get_city();j++)
            {
                QLineEdit *lineEdit= this->create_cell_for_TSP(i,j);
                ui->distan_matrix->addWidget(lineEdit,j,i);
                lineEditList[j].append(lineEdit);
            }
        }
    }
    this->update();
    tsp.change_city_n(this->ui->tsp_city->value());
}

QLineEdit* MainWindow::create_cell_for_TSP(int i, int j){
    QLineEdit *lineEdit= new QLineEdit("0",this);
    lineEdit->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    lineEdit->setAlignment(Qt::AlignCenter);
    lineEdit->setValidator(new QIntValidator(0, 9999));
    lineEdit->setMaxLength(5);
    QString name ="TSP_lineEdit_"+QString::number(i)+"_"+QString::number(j);
    lineEdit->setObjectName(name);
    if (i==j)
        lineEdit->setReadOnly(true);
    lineEdit->setMaximumWidth(70);
    lineEdit->setStyleSheet("QLineEdit {border-radius: 5px; background-color: rgb(170,170,170);font-size: 18px; color: rgb(0,0,0);font-weight: bold;}");
    return lineEdit;
}

//void MainWindow::moveWindow(){
//    if (!this->isMaximized()){
//        if (e==Qt::LeftButton){
//            this->move(this->pos()+e->globalpos-this->clickPosition);
//            this->clickPosition = e->globalPos();
//            e->accept();
//        }
//    }


//}

//void MainWindow::mousePressEvent(QMouseEvent* e){
//    this->clickPosition = e->globalPos();


//}


