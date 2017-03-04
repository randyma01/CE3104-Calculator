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
    operation = "ADDITION"; /*Changes operation action message to sum.*/
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
    if (operation == "ADDITION"){
       // polynomial.clear(); /*Clears the polynomial vector.*/
        //operation = "NONE"; /*Sets operation to NONE.*/
        operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
        clearInput();
        polynomial.clear();         /*Clear the polynomial*/

        addition(); /*Calls for the adition method.*/
    }
    if(operation == "SUBSTRACTION"){
        operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
        clearInput();
        polynomial.clear();         /*Clear the polynomial*/

        substraction(); /*Calls for the substraction method.*/

        //operation = "NONE"; /*Sets operation to NONE.*/
    }
    if(operation == "MULTIPLY"){
        operands.push_back(polynomial); /*Inserts the polynomial on the operands.*/
        clearInput();
        polynomial.clear();         /*Clear the polynomial*/
        muplitply(); /*Calls for the multiply method.*/
       // operation = "NONE"; /*Sets operation to NONE.*/
    }
}

/*****OPERATIONS BUTTONS*****/


void MainWindow::addition(){
    //caso que las operaciones se realicen solo con dos polinomios
    verifyTriplets(operands[0], operands[1]);
//    //recorre el vector que contiene los polinomios a sumar
//    //en caso que se puedan realizar operaciones con mas de dos polinomios
//    while((int)operands.size() != 0){
//        verifyTripletsSum(operands[0], operands[1]);
//        operands.erase(0);
//        operands.erase(0);
//        if((int)operands.size() == 1){
//            cout << "termino la operacion";
//        }
//    }
}

void MainWindow::substraction(){
    //caso que las operaciones se realicen solo con dos polinomios
    verifyTriplets(operands[0], operands[1]);
}

void MainWindow::muplitply(){
    verifyTripletsMulti(operands[0], operands[1]);
}

/*****CALCULATOR ACTIONS*****/
void MainWindow::on_clearCancel_pressed()
{

}

void MainWindow::on_clear_pressed(){

}

void MainWindow::clearInput(){
    ui->lineEdit->clear();
}


//posible, mejor pasar los dos vectores de polinomios
void MainWindow::verifyTriplets(vector<vector<int>> polynomialA, vector<vector<int>> polynomialB){
    vector<int> tripletsA;
    int a;

    for(int i=0; i<(int)polynomialA.size(); i++){

        //obtiene la primer tripleta del polinomio A
        tripletsA = polynomialA[i];
        int b = tripletsA[1];
        int c = tripletsA[2];
        int j = 0;

        while(true){
            //si no encuentra valores identicos, agrega la tripleta al vector resultado
            if(j > (int)polynomialB.size()){
                resultTriplet.push_back(tripletsA);
                break;
            }
            //compara los valores de 'b' y 'c' con los valores de todas las tripletas del polinomio B
            //si encuentra uno con los valores identicos (suma/resta) los valores 'a' de ambas tripletas
            //y se agrega el resultado al vectorRespuesta
            //**borra la tripleta del polinomio B(ya no son necesarias)
            if(polynomialB[j][1] == b && polynomialB[j][2] == c){
                if(operation ==  "ADDITION"){
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
        resultTriplet.push_back(polynomialB[l]);
    }

    cout << "ternima la funcion verif" << endl;
    cout << "resultado de la suma: \n" ;
    for(int i = 0; i<(int)resultTriplet.size(); i++){
        if(resultTriplet[i][0] != 0){
            cout << resultTriplet[i][0] << "x^" << resultTriplet[i][1] << "y^" << resultTriplet[i][2] << " ";

        }
    }
}


void MainWindow::verifyTripletsMulti(vector<vector<int> > polynomialA, vector<vector<int> > polynomialB){
    //vector donde guardara los polinomios generados debido a la multiplicacion
    vector<vector<vector<int>>> operands_aux;
    //donde se guarda el polinomio que se va formando
    vector<vector<int>> polynomial_aux;
    vector<int> tripletsA;


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
        operands_aux.push_back(polynomial_aux);
        polynomial_aux.clear();
    }
    cout << "termino de multiplicar" << endl;

    for(int i = 0; i < (int)operands_aux.size(); i++){
        for(int j=0; j < (int)operands_aux[i].size(); j++){
            cout << operands_aux[i][j][0] << operands_aux[i][j][1] << operands_aux[i][j][2] << " | ";
        }
    }

//    //cuando termina
//    //se pasa la operacion suma para simplificar el resultado
//    //en caso que el polinomioA sea mayor a 2 tripletas
//    //verificar y pasar todos los polinomios
//    operation = "ADDITION";
//    verifyTriplets(operands_aux[0], operands_aux[1]);

//    //caso de que el polinomioA sea de 3 tripletas
//    //se generan tres polinomios
//    //caso de que sean mas, se requiere de un ciclo
//    if((int)operands_aux.size() > 2){
//        verifyTriplets(resultTriplet, operands_aux[2]);
//    }
}
