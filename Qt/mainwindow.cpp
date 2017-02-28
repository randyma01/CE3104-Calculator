#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * Main constructor.
 *
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->separatorBar->setEnabled(true);
    ui->result->setEnabled(false);
}

/**
 * Destroyer.
 *
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow(){
    delete ui;
}


/**
 *Insert number: 0.
 *
 * @brief MainWindow::on_num0_pressed
 */
void MainWindow::on_num0_pressed(){
    QString num = "0";
    ui->lineEdit->insert(num);
    number += "0";
}

/*****INSERT NUMBERS AND NEGATIVE SIGNS*****/

/**
 *Insert number: 1.
 *
 * @brief MainWindow::on_num1_pressed
 */
void MainWindow::on_num1_pressed(){
    QString num = "1";
    ui->lineEdit->insert(num);
    number += "1";
}

/**
 *Insert number: 2.
 *
 * @brief MainWindow::on_num2_pressed
 */
void MainWindow::on_num2_pressed(){
    QString num = "2";
    ui->lineEdit->insert(num);
    number += "2";
}

/**
 *Insert number:3.
 *
 * @brief MainWindow::on_num3_pressed
 */
void MainWindow::on_num3_pressed(){
    QString num = "3";
    ui->lineEdit->insert(num);
    number += "3";
}

/**
 *Insert number: 4.
 *
 * @brief MainWindow::on_num4_pressed
 */
void MainWindow::on_num4_pressed(){
    QString num = "4";
    ui->lineEdit->insert(num);
    number += "4";
}

/**
 *Insert number: 5.
 *
 * @brief MainWindow::on_num5_pressed
 */
void MainWindow::on_num5_pressed(){
    QString num = "5";
    ui->lineEdit->insert(num);
    number += "5";
}

/**
 *Insert number: 6.
 *
 * @brief MainWindow::on_num6_pressed
 */
void MainWindow::on_num6_pressed(){
    QString num = "6";
    ui->lineEdit->insert(num);
    number += "6";
}

/**
 *Insert number: 7.
 *
 * @brief MainWindow::on_num7_pressed
 */
void MainWindow::on_num7_pressed(){
    QString num = "7";
    ui->lineEdit->insert(num);
    number += "7";
}

/**
 *Insert number: 8.
 *
 * @brief MainWindow::on_num8_pressed
 */
void MainWindow::on_num8_pressed(){
    QString num = "8";
    ui->lineEdit->insert(num);
    number += "8";
}

/**
 *Insert number: 9.
 *
 * @brief MainWindow::on_num9_pressed
 */
void MainWindow::on_num9_pressed(){
    QString num = "9";
    ui->lineEdit->insert(num);
    number += "9";
}

/**
 *Inset sign: - (negative).
 * @brief MainWindow::on_negative_pressed
 */
void MainWindow::on_negative_pressed(){
    QString num = "-";
    ui->lineEdit->insert(num);
    number += "-";
}

/*****INSERT SEPARATOR AND SPACE*****/

/**
 * Insert blank space. Inserts the first triplet
 * (vector<int> of the numbers) on the polynimal
 *  expresion (vector<vector<int>>).
 *
 * @brief MainWindow::on_spaceBlank_pressed
 */
void MainWindow::on_spaceBlank_pressed(){
    QString space= " ";
    ui->lineEdit->insert(space); /*Shows a space on screen.*/
    polynomial.push_back(triplets); /*Inserts the first triplet on the polynomial.*/
    triplets.clear(); /*Clears the first triplet.*/
}

/**
 * Insert char: | (separator bar), on screen.
 * Inserts all numbers (as strings) in the first monomial
 * expresion on the triplets (vector<int>).
 *
 * @brief MainWindow::on_separatorBar_pressed
 */
void MainWindow::on_separatorBar_pressed(){
    QString separator = " | ";
    triplets.push_back(atoi(number.c_str())); /*Inserts the fisrt number on the triplet.*/
    ui->lineEdit->insert(separator); /*Adds the separator.*/
    number.clear(); /*Clears the separator.*/
}

/*****OPERATIONS BUTTONS*****/

/**
 * Changes the variable operation (string)
 * to set the action to ADDITION.
 *
 * @brief MainWindow::on_addition_pressed
 */
void MainWindow::on_addition_pressed(){
    operation = "ADDITION"; /*Changes operation action message to sum.*/
    ui->result->setEnabled(true);  /*Enables the equal action button.*/
}

/**
 * Changes the variable operation (string)
 * to set the action to SUSBTRACTION.
 *
 * @brief MainWindow::on_subtraction_pressed
 */
void MainWindow::on_subtraction_pressed(){
    operation = "SUBSTRACTION"; /*Changes operation action message to susbtraction.*/
    ui->result->setEnabled(true);  /*Enables the equal action button.*/
}

/**
 * Changes the variable operation (string)
 * to set the action to MULTIPLY.
 *
 * @brief MainWindow::on_multiplication_pressed
 */
void MainWindow::on_multiplication_pressed(){
    operation = "MULTIPLY"; /*Changes operation action message to multiply.*/
    ui->result->setEnabled(true);  /*Enables the equal action button.*/
}


void MainWindow::on_evaluate_pressed(){

}

/**
 * Depending on the message value of varible
 * operation (string) calculates the result
 * and print the result on screen. Save the
 * last result on the variable answer (string)
 * and sets the variable operation (string)
 * to NONE.
 * @brief MainWindow::on_result_pressed
 */
void MainWindow::on_result_pressed(){
    if (operation == "SUM"){
        addition(); /*Calls for the adition method.*/
        polynomial.clear(); /*Clears the polynomial vector.*/
        operation = "NONE"; /*Sets operation to NONE.*/
    }else if(operation == "SUSBTRACTION"){
        substraction(); /*Calls for the substraction method.*/
        polynomial.clear(); /*Clears the polynomial vector.*/
        operation = "NONE"; /*Sets operation to NONE.*/
    }else if(operation == "MULTIPLY"){
        muplitply(); /*Calls for the multiply method.*/
        polynomial.clear(); /*Clears the polynomial vector.*/
        operation = "NONE"; /*Sets operation to NONE.*/
    }
}

/*****OPERATIONS BUTTONS*****/

void MainWindow::addition(){
    for(int i=0; i<(int) polynomial.size(); i++){
        for(int j=0; j<(int)polynomial[0].size();j++){
            if( polynomial[i][j] == polynomial[i+1][j+1]){
                resultTriplet[i] = polynomial[i][j] + polynomial[i+1][j+1];
            }
        }
    }
    // ui->lineEdit->insert();
}

void MainWindow::substraction(){

}

void MainWindow::muplitply(){

}

/*****CALCULATOR ACTIONS*****/
void MainWindow::on_clearCancel_pressed()
{

}

void MainWindow::on_clear_pressed(){

}

