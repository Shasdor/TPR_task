#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
# include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void generate_base_tasks();
    void generate_tsp_matrix(int city_n);


private slots:
    void on_menu_button_clicked();

    void on_minimize_window_button_clicked();

    void on_close_window_button_clicked();

    void on_change_size_button_clicked();

    void on_TSP_task_button_clicked();

    void on_tsp_city_editingFinished();

    void on_TSP_calculate_button_clicked();

    void on_github_site_clicked();

    void on_TSP_deafult_button_clicked();

    void do_TSP();
//    void clear_matrix();
    void resize_TSP_matrix(int);
    QLineEdit* create_cell_for_TSP(int,int);
//    void moveWindow(QMouseEvent*);
//   void mousePressEvent(QMouseEvent*);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
