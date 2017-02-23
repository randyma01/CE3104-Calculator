#include "mainwindow.h"
#include "ui_mainwindow.h"


vector<int> triplets;
vector<vector<int>> polynomial;
int var = 0;
string number;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}


/*
 * Insert number
 */
void MainWindow::on_num0_pressed(){
    QString num = "0";
    ui->lineEdit->insert(num);
    number += "0";
}

void MainWindow::on_num1_pressed(){
    QString num = "1";
    ui->lineEdit->insert(num);
    number += "1";
}

void MainWindow::on_num2_pressed(){
    QString num = "2";
    ui->lineEdit->insert(num);
    number += "2";
}

void MainWindow::on_num3_pressed(){
    QString num = "3";
    ui->lineEdit->insert(num);
    number += "3";
}

void MainWindow::on_num4_pressed(){
    QString num = "4";
    ui->lineEdit->insert(num);
    number += "4";
}

void MainWindow::on_num5_pressed(){
    QString num = "5";
    ui->lineEdit->insert(num);
    number += "5";
}

void MainWindow::on_num6_pressed(){
    QString num = "6";
    ui->lineEdit->insert(num);
    number += "6";
}

void MainWindow::on_num7_pressed(){
    QString num = "7";
    ui->lineEdit->insert(num);
    number += "7";
}

void MainWindow::on_num8_pressed(){
    QString num = "8";
    ui->lineEdit->insert(num);
    number += "8";
}

void MainWindow::on_num9_pressed(){
    QString num = "9";
    ui->lineEdit->insert(num);
    number += "9";
}

void MainWindow::on_negative_pressed(){
    QString num = "-";
    ui->lineEdit->insert(num);
    number += "-";
}

void MainWindow::on_spaceBlank_pressed(){
    if (var < 2){
        triplets.push_back(atoi(number.c_str()));
        QString space = " ";
        ui->lineEdit->insert(space);
        var+=1;
        number.clear();
    }
    else{
        triplets.push_back(atoi(number.c_str()));
        ui->separatorBar->setEnabled(true);
        number.clear();
    }
}

void MainWindow::on_separatorBar_pressed(){
    QString separator = " | ";
    polynomial.push_back(triplets);
    ui->lineEdit->insert(separator);
    var = 0;
    ui->separatorBar->setEnabled(false);
    triplets.clear();
}

/*
 * Operations
 *
 */

void MainWindow::on_addition_pressed()
{

}

void MainWindow::on_subtraction_pressed()
{

}

void MainWindow::on_multiplication_pressed()
{

}

void MainWindow::on_result_pressed(){
    //cout << polynomial[0][0] << " " << polynomial[0][1] << " " << polynomial[0][2];
    for(int i = 0; i < (int)polynomial.size(); i++){
        cout << polynomial[i][0] << "x^" << polynomial[i][1] << "y^" << polynomial[i][2] << " ";
    }
}


void MainWindow::on_evaluate_pressed()
{

}

void MainWindow::on_clearCancel_pressed()
{

}

void MainWindow::on_clear_pressed(){

}

