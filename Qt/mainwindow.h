#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>


using namespace std;

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
    /*
     * Number Button
     */
    void on_num0_pressed();
    void on_num1_pressed();
    void on_num2_pressed();
    void on_num3_pressed();
    void on_num4_pressed();
    void on_num5_pressed();
    void on_num6_pressed();
    void on_num7_pressed();
    void on_num8_pressed();
    void on_num9_pressed();

    /*
     * Operations Button
     */
    void on_addition_pressed();
    void on_subtraction_pressed();
    void on_multiplication_pressed();
    void on_result_pressed();


    /*
     * Other Button
     */
    void on_evaluate_pressed();
    void on_clearCancel_pressed();
    void on_clear_pressed();
    void on_spaceBlank_pressed();
    void on_separatorBar_pressed();



    void on_negative_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
