#include "MainWindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>

QString value = "", total = "";
int fNum, sNum;
bool addBool = false, substractBool = false, multiplyBool = false, divideBool = false;
MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent)
{
    operateur = "+";

    label=new QLabel ("0", this);
    label->setGeometry(QRect(QPoint(75,25),QSize(50,200)));

    clear_button = new QPushButton("C", this);
    clear_button ->setGeometry(QRect(QPoint(125,300),QSize(50,50)));
    connect(clear_button, SIGNAL(released()),this, SLOT(clear()));

    equals_button = new QPushButton("=", this);
    equals_button ->setGeometry(QRect(QPoint(175,300),QSize(50,50)));
    connect(equals_button, SIGNAL(released()),this, SLOT(equals()));

    add_button = new QPushButton("+", this);
    add_button ->setGeometry(QRect(QPoint(225,150),QSize(50,50)));
    connect(add_button, SIGNAL(released()),this, SLOT(add()));

    substract_button = new QPushButton("-", this);
    substract_button ->setGeometry(QRect(QPoint(225,200),QSize(50,50)));
    connect(substract_button, SIGNAL(released()),this, SLOT(substract()));

    multiply_button = new QPushButton("x", this);
    multiply_button ->setGeometry(QRect(QPoint(225,250),QSize(50,50)));
    connect(multiply_button, SIGNAL(released()),this, SLOT(multiply()));

    divide_button = new QPushButton("/", this);
    divide_button ->setGeometry(QRect(QPoint(225,300),QSize(50,50)));
    connect(divide_button, SIGNAL(released()),this, SLOT(divide()));

    zero_button = new QPushButton("0", this);
    zero_button ->setGeometry(QRect(QPoint(75,300),QSize(50,50)));
    connect(zero_button, SIGNAL(released()),this, SLOT(zero()));

    one_button = new QPushButton("1", this);
    one_button ->setGeometry(QRect(QPoint(75,250),QSize(50,50)));
    connect(one_button, SIGNAL(released()),this, SLOT(one()));

    two_button = new QPushButton("2", this);
    two_button ->setGeometry(QRect(QPoint(125,250),QSize(50,50)));
    connect(two_button, SIGNAL(released()),this, SLOT(two()));

    three_button = new QPushButton("3", this);
    three_button ->setGeometry(QRect(QPoint(175,250),QSize(50,50)));
    connect(three_button, SIGNAL(released()),this, SLOT(three()));

    four_button = new QPushButton("4", this);
    four_button ->setGeometry(QRect(QPoint(75,200),QSize(50,50)));
    connect(four_button, SIGNAL(released()),this, SLOT(four()));

    five_button = new QPushButton("5", this);
    five_button ->setGeometry(QRect(QPoint(125,200),QSize(50,50)));
    connect(five_button, SIGNAL(released()),this, SLOT(five()));

    six_button = new QPushButton("6", this);
    six_button ->setGeometry(QRect(QPoint(175,200),QSize(50,50)));
    connect(six_button, SIGNAL(released()),this, SLOT(six()));

    seven_button = new QPushButton("7", this);
    seven_button ->setGeometry(QRect(QPoint(75,150),QSize(50,50)));
    connect(seven_button, SIGNAL(released()),this, SLOT(seven()));

    eight_button = new QPushButton("8", this);
    eight_button ->setGeometry(QRect(QPoint(125,150),QSize(50,50)));
    connect(eight_button, SIGNAL(released()),this, SLOT(eight()));

    nine_button = new QPushButton("9", this);
    nine_button ->setGeometry(QRect(QPoint(175,150),QSize(50,50)));
    connect(nine_button, SIGNAL(released()),this, SLOT(nine()));

    back = new QPushButton("B", this);
    back ->setGeometry(QRect(QPoint(0,150),QSize(50,50)));
    connect(back, SIGNAL(released()),this, SLOT(back_slot()));

}

void MainWindow::back_slot(){
    actual_valeur = (int)(actual_valeur / 10);
    label -> setText(QString::number(actual_valeur));
}


void MainWindow:: clear(){
    result = 0;
    actual_valeur = 0;
    operateur = "+";
    label -> setText(QString::number(result));
    //value = "";
    //label->setText(value);

}

void MainWindow::equals(){
    result = operation(result, actual_valeur, operateur);
    label -> setText(QString::number(result));
    actual_valeur = 0;
    operateur = "+";
     /*sNum = value.toInt();
     if (addBool) {
        total = QString::number(fNum+sNum);
        label ->setText(total);
     }
     if (substractBool){
         total = QString::number(fNum-sNum);
         label ->setText(total);
     }
     if (multiplyBool){
         total = QString::number(fNum*sNum);
         label ->setText(total);
     }
     if (divideBool){
         total = QString::number(fNum/sNum);
         label ->setText(total);
     }
     fNum = 0;
     sNum = 0;*/
}

double MainWindow::operation(double a, double b, QString op){
    double r = 0;

    if(op == "+"){
        r = a + b;
    }else if(op == "-"){
        r = a - b;
    }else if(op == "*"){
        r = a * b;
    }else if(op == "/"){
        r = a / b;
    }

    return r;
}

void MainWindow::add(){
     /*fNum = value.toInt();
     value = "";
     label -> setText (value);
     addBool = true;*/

    result = operation(result, actual_valeur, operateur);
    label -> setText(QString::number(result));
    actual_valeur = 0;

    operateur = "+";
}

void MainWindow::substract(){
    /*fNum = value.toInt();
    value = "";
    label -> setText (value);
    substractBool = true;*/
    result = operation(result, actual_valeur, operateur);
    label -> setText(QString::number(result));
    actual_valeur = 0;
    operateur = "-";
}

void MainWindow::multiply(){
    /*fNum = value.toInt();
    value = "";
    label -> setText (value);
    multiplyBool = true;*/
    result = operation(result, actual_valeur, operateur);
    label -> setText(QString::number(result));
    actual_valeur = 0;
    operateur = "*";
}

void MainWindow::divide(){
    /*fNum = value.toInt();
    value = "";
    label -> setText (value);
    divideBool = true;*/
    result = operation(result, actual_valeur, operateur);
    label -> setText(QString::number(result));
    actual_valeur = 0;
    operateur = "/";
}

void MainWindow::zero(){
    actual_valeur = actual_valeur * 10;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::one(){
    actual_valeur = actual_valeur * 10 + 1;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::two(){
    actual_valeur = actual_valeur * 10 + 2;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::three(){
    actual_valeur = actual_valeur * 10 + 3;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::four(){
    actual_valeur = actual_valeur * 10 + 4;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::five(){
    actual_valeur = actual_valeur * 10 + 5;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::six(){
    actual_valeur = actual_valeur * 10 + 6;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::seven(){
    actual_valeur = actual_valeur * 10 + 7;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::eight(){
    /*value = value + "8";
    label -> setText(value);*/
    actual_valeur = actual_valeur * 10 + 8;
    label -> setText(QString::number(actual_valeur));
}

void MainWindow::nine(){
    //value = value + "9";
    actual_valeur = actual_valeur * 10 + 9;
    label -> setText(QString::number(actual_valeur));
}


MainWindow::~MainWindow()
{
}

