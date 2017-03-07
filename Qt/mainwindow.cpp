#include "mainwindow.h"
#include "ui_mainwindow.h"

int numberSpaces; /*Variable for number of spaces*/
int ereaseTofP;


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
    ui->spaceBlank_Eval->setVisible(false);
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
    /*To indicate that they are triplets*/
    if (numberSpaces < 2){
        triplets.push_back(atoi(number.c_str())); /*Inserts the  number on the triplet.*/
        QString space= " ";
        ui->lineEdit->insert(space); /*Shows a space on screen.*/
        numberSpaces += 1;
        number.clear(); /*Clear the number*/
    }
    else{
        triplets.push_back(atoi(number.c_str()));
        ui->separatorBar->setEnabled(true);
        number.clear();
    }
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
    polynomial.push_back(triplets); /*Inserts the triplet on the polynomial.*/
    triplets.clear(); /*Clears the triplet.*/
    ui->lineEdit->insert(separator); /*Adds the separator.*/
    numberSpaces = 0;
    ui->separatorBar->setEnabled(false);
}

/*****OPERATIONS BUTTONS*****/

/**
 * Changes the variable operation (string)
 * to set the action to ADDITION.
 *
 * @brief MainWindow::on_addition_pressed
 */
void MainWindow::on_addition_pressed(){
//    polynomial.push_back(triplets); /*Inserts the triplet on the polynomial.*/
//    triplets.clear(); /*Clears the triplet.*/
//    numberSpaces = 0;

    operation = "SUM"; /*Changes operation action message to sum.*/
    ui->result->setEnabled(true);  /*Enables the equal action button.*/
    operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
    clearInput();
    polynomial.clear();         /*Clear the polynomial*/
}

/**
 * Changes the variable operation (string)
 * to set the action to SUSBTRACTION.
 *
 * @brief MainWindow::on_subtraction_pressed
 */
void MainWindow::on_subtraction_pressed(){
//    polynomial.push_back(triplets); /*Inserts the triplet on the polynomial.*/
//    triplets.clear(); /*Clears the triplet.*/
//    numberSpaces = 0;

    operation = "SUBSTRACTION"; /*Changes operation action message to susbtraction.*/
    ui->result->setEnabled(true);  /*Enables the equal action button.*/
    operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
    clearInput();
    polynomial.clear();         /*Clear the polynomial*/
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
    operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
    clearInput();
    polynomial.clear();         /*Clear the polynomial*/
}


void MainWindow::on_evaluate_pressed(){
    clearInput();
    ui->spaceBlank->setVisible(false);
    ui->spaceBlank->setEnabled(false);
    ui->result->setEnabled(true);  /*Enables the equal action button.*/
    ui->spaceBlank_Eval->setEnabled(true);
    ui->spaceBlank_Eval->setVisible(true);
    operation = "EVAL";

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

        operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
        clearInput();
        polynomial.clear();         /*Clear the polynomial*/

        addition(); /*Calls for the adition method.*/
        ui->result->setEnabled(false);  /*Enables the equal action button.*/
    }
    if(operation == "SUBSTRACTION"){
        operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
        clearInput();
        polynomial.clear();         /*Clear the polynomial*/
        substraction(); /*Calls for the substraction method.*/
        ui->result->setEnabled(false);  /*Enables the equal action button.*/
    }
    if(operation == "MULTIPLY"){
        operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
        clearInput();
        polynomial.clear();         /*Clear the polynomial*/
        muplitply(); /*Calls for the multiply method.*/
        ui->result->setEnabled(false);  /*Enables the equal action button.*/
    }
    if(operation == "EVAL"){
        clearInput();     /*Clear the polynomial*/
        evaluation(); /*Calls for the multiply method.*/
        ui->spaceBlank->setVisible(true);
        ui->spaceBlank->setEnabled(true);
        ui->result->setEnabled(false);  /*Enables the equal action button.*/
        ui->spaceBlank_Eval->setEnabled(false);
        ui->spaceBlank_Eval->setVisible(false);
       // operation = "NONE"; /*Sets operation to NONE.*/
    }
}

/*****OPERATIONS BUTTONS*****/


void MainWindow::addition(){
    if((int)operands.size() > 2){
        verifyTriplets(operands[0], operands[1]);
        clearInput();
        verifyTriplets(resultTriplet, operands[2]);
    }
    else{//caso que las operaciones se realicen solo con dos polinomios
        verifyTriplets(operands[0], operands[1]);
    }
}

void MainWindow::substraction(){
    if((int)operands.size() > 2){
        verifyTriplets(operands[0], operands[1]);
        clearInput();
        verifyTriplets(resultTriplet, operands[2]);
    }
    else{//caso que las operaciones se realicen solo con dos polinomios
        verifyTriplets(operands[0], operands[1]);
    }
}

void MainWindow::muplitply(){
    verifyTripletsMulti(operands[0], operands[1]);
    operation = "SUM";
    verifyTriplets(operands[0], operands[1]);
}

void MainWindow::evaluation(){
    vector<int> triplets;
    int result = 0;
    int b = eval[0];
    int c = eval[1];
    for(int i=0; i < (int)polynomial.size(); i++){
       triplets = polynomial[i];
       result += (triplets[0]) * pow(b, triplets[1]) * pow(c,triplets[2]);
    }
    //se limpia el vector polinomio para ser usado por otra operacion
    //se limpia el vector eval que contiene los valores de 'x' ^ 'y'
    polynomial.clear();
    eval.clear();

    //mostrar el resultado en pantalla
    ui->lineEdit->insert(QString::number(result));

}

/*****CALCULATOR ACTIONS*****/
void MainWindow::on_clearCancel_pressed(){
    operation = "NONE";
    triplets.clear();
    polynomial.clear();
    operands.clear();
    eval.clear();
    clearInput();
    numberSpaces = 0;
    ui->spaceBlank->setEnabled(true);
    ui->spaceBlank_Eval->setEnabled(false);
    ui->spaceBlank->setVisible(true);
    ui->spaceBlank_Eval->setVisible(false);
}

void MainWindow::on_clear_pressed(){
    triplets.clear();
    polynomial.clear();
    eval.clear();
    clearInput();
    numberSpaces = 0;
}

void MainWindow::clearInput(){
    ui->lineEdit->clear();
}


//posible, mejor pasar los dos vectores de polinomios
void MainWindow::verifyTriplets(vector<vector<int>> polynomialA, vector<vector<int>> polynomialB){
    vector<int> tripletsA;
    int a;

    if(!resultTriplet.empty()){
        resultTriplet.clear();
    }

    for(int i=0; i<(int)polynomialA.size(); i++){

        //obtiene la primer tripleta del polinomio A
        tripletsA = polynomialA[i];
        int b = tripletsA[1];
        int c = tripletsA[2];
        int j = 0;

        while(true){
            //si no encuentra valores identicos, agrega la tripleta al vector resultado
            if(j >= (int)polynomialB.size()){
                resultTriplet.push_back(tripletsA);
                break;
            }
            //compara los valores de 'b' y 'c' con los valores de todas las tripletas del polinomio B
            //si encuentra uno con los valores identicos (suma/resta) los valores 'a' de ambas tripletas
            //y se agrega el resultado al vectorRespuesta
            //**borra la tripleta del polinomio B(ya no son necesarias)
            if(polynomialB[j][1] == b && polynomialB[j][2] == c){
                if(operation ==  "SUM"){
                    a = tripletsA[0] + polynomialB[j][0];
                }
                if(operation == "SUBSTRACTION"){
                    a = tripletsA[0] - polynomialB[j][0];
                }
                //a = tripletsA[0] + polynomialB[j][0];
                tripletsA[0] = a;
                resultTriplet.push_back(tripletsA);
                tripletsA.clear();
                polynomialB.erase(polynomialB.begin() + j);
                break;

            }
            else{
                j++;
            }
        }
    }
    //agrega las tripletas del polinomio B que no fueron borradas
    //al vector de resultados
    for(int l = 0; l < (int)polynomialB.size(); l++){
        if(operation == "SUBSTRACTION"){
            polynomialB[l][0] =  polynomialB[l][0] * -1;
        }
        resultTriplet.push_back(polynomialB[l]);
    }

    //muestra el resultado en pantalla
    for(int i = 0; i<(int)resultTriplet.size(); i++){
        if(resultTriplet[i][0] != 0){
            ui->lineEdit->insert(QString::number(resultTriplet[i][0]));
            ui->lineEdit->insert(" ");
            ui->lineEdit->insert(QString::number(resultTriplet[i][1]));
            ui->lineEdit->insert(" ");
            ui->lineEdit->insert(QString::number(resultTriplet[i][2]));
            ui->lineEdit->insert(" | ");
        }
    }
}


void MainWindow::verifyTripletsMulti(vector<vector<int> > polynomialA, vector<vector<int> > polynomialB){
    //vector donde guardara los polinomios generados debido a la multiplicacion
    //vector<vector<vector<int>>> operands_aux;
    //donde se guarda el polinomio que se va formando
    vector<vector<int>> polynomial_aux;
    vector<int> tripletsA;

    operands.clear();


    for(int i=0; i<(int)polynomialA.size(); i++){

        //recorre el polinomioB multiplicando los valores 'a' de cada tripleta
        //sumando los valores 'b' ^ 'c', luego se agrega al polinomio
        for(int j=0; j<(int)polynomialB.size(); j++){

            tripletsA = polynomialA[i];

            int a = tripletsA[0] * polynomialB[j][0];
            int b = tripletsA[1] + polynomialB[j][1];
            int c = tripletsA[2] + polynomialB[j][2];
            tripletsA[0] = a;
            tripletsA[1] = b;
            tripletsA[2] = c;
            polynomial_aux.push_back(tripletsA);
        }
        //se guarda el polinomio en el vector auxiliar
        //se limpia el polinomio para guardar los otros
        operands.push_back(polynomial_aux);
        polynomial_aux.clear();
    }
}


void MainWindow::on_spaceBlank_Eval_pressed(){
    eval.push_back(atoi(number.c_str())); /*Inserts the  number on the triplet.*/
    QString space= " ";
    number.clear();
    ui->lineEdit->insert(space); /*Shows a space on screen.*/
}
