#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtGui/QPushButton>
//#include <QtGui/QLabel>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h> // Error: <unistd.h> No such file or directory find //
#include <cstdlib>
#include <cstring>


using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    vector<int> triplets; /*Vector for the Triplets*/
    vector<vector<int>> resultTriplet; /*Vector for the resulted operation.*/
    vector<vector<int>> polynomial; /*Vector for the Triplets Vectors*/
    vector<int> eval;
    string number; /*Variable for keeping all the numbers being inserted in the each triplet.*/
    string answers; /*Variable for keeping the last result calculated.*/
    string operation = "NONE"; /*Variable for making the operation.*/

    vector<vector<vector<int>>> operands; /*vector for operands to be used*/

    void clearInput();

    void verifyTriplets(vector<vector<int>> polynomialA, vector<vector<int>> polynomialB);
    void verifyTripletsMulti(vector<vector<int>> polynomialA, vector<vector<int>> polynomialB);

private slots:
    /*
     * Number Button and Negative Sign: insertion.
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
    void on_negative_pressed();


    /*
     * Operations Button
     */
    void on_addition_pressed(); //sum
    void on_subtraction_pressed();//substraction
    void on_multiplication_pressed();//product
    void on_result_pressed();// result

    /*
     * Operations Actions
     */
    void addition();
    void substraction();
    void muplitply();
    void evaluation();

    /*
     * Other Button: Calculator Actions
     */
    void on_evaluate_pressed();//evualtion
    void on_clearCancel_pressed();//cancel
    void on_clear_pressed(); //clear
    void on_spaceBlank_pressed();//space
    void on_separatorBar_pressed();


    void on_spaceBlank_Eval_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
