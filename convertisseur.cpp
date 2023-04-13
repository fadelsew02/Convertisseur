#include "convertisseur.h"
#include "ui_convertisseur.h"

Convertisseur::Convertisseur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Convertisseur), taux(1)
    ,valDeviseLabel1(0),valDeviseLabel2(0)
    ,valTemperatureLabel1(0),valTemperatureLabel2(0)
    ,valPoidsLabel1(0),valPoidsLabel2(0)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked,this,&Convertisseur::convertirToSecondLabelDevise);
    connect(ui->pushButton_2, &QPushButton::clicked,this,&Convertisseur::convertirToSecondLabelPoids);
    connect(ui->pushButton_4, &QPushButton::clicked,this,&Convertisseur::convertirToSecondLabelTemperature);
    myStringListDevise << "USD" << "EUR" << "JPY" << "GBP" << "CHF" << "AUD" << "CAD" << "SGD" << "HKD" << "CNY";
    myStringListPoids << "g" << "kg" << "lb" << "oz" << "ct" << "t" << "q" << "st";
    myStringListTemperature << "celsius" << "fahrenheit" << "kelvin" << "rankine" ;
}

Convertisseur::~Convertisseur()
{
    delete ui;
}

void Convertisseur::convertirToSecondLabelDevise(void){
    int index1;
    int index2;
    QString selected_value1 = ui->comboBoxLabel1->currentText();
    QString selected_value2 = ui->comboBoxLabel2->currentText();

    for(int i=0; i<10; i++){
        if(selected_value1 == myStringListDevise.at(i)){
            index1 = i;
            break;
        }
    }

    for(int i=0; i<10; i++){
        if(selected_value2 == myStringListDevise.at(i)){
            index2 = i;
            break;
        }
    }

    taux = tableauDevise[index1][index2];

    valDeviseLabel1 = ui->doubleSpinBoxDevise->value();
    valDeviseLabel2 = valDeviseLabel1*taux;
    ui->doubleSpinBox_2->setValue(valDeviseLabel2);
}

void Convertisseur::convertirToSecondLabelPoids(void){

    int index1;
    int index2;
    QString selected_value1 = ui->comboBoxLabel3->currentText();
    QString selected_value2 = ui->comboBoxLabel4->currentText();

    for(int i=0; i<8; i++){
        if(selected_value1 == myStringListPoids.at(i)){
            index1 = i;
            break;
        }
    }

    for(int i=0; i<8; i++){
        if(selected_value2 == myStringListPoids.at(i)){
            index2 = i;
            break;
        }
    }

    taux = tableauPoids[index1][index2];
    valPoidsLabel1 = ui->doubleSpinBox_3Poids->value();
    valPoidsLabel2 = valPoidsLabel1*taux;
    ui->doubleSpinBox_4->setValue(valPoidsLabel2);
}

void Convertisseur::convertirToSecondLabelTemperature(void){

    int index1;
    int index2;
    QString selected_value1 = ui->comboBoxLabel7->currentText();
    QString selected_value2 = ui->comboBoxLabel8->currentText();

    for(int i=0; i<4; i++){
        if(selected_value1 == myStringListTemperature.at(i)){
            index1 = i;
            break;
        }
    }

    for(int i=0; i<4; i++){
        if(selected_value2 == myStringListTemperature.at(i)){
            index2 = i;
            break;
        }
    }

    taux = tableauTemperature[index1][index2];

    if(index1 == 0 && index2 == 0){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 0 && index2 == 1){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1*1.8+taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 0 && index2 == 2){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1+taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 0 && index2 == 3){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1*1.8+taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 1 && index2 == 0){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1*0.56-taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 1 && index2 == 1){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 1 && index2 == 2){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1*0.56 - taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 1 && index2 == 3){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1+taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 2 && index2 == 0){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1-taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 2 && index2 == 1){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1*1.8 - 459.67;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 2 && index2 == 2){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 2 && index2 == 3){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1*1.8;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 3 && index2 == 0){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1 * 0.56 - taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 3 && index2 == 1){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1 - taux;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 3 && index2 == 2){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1 * 0.56 - 32;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }else if(index1 == 3 && index2 == 3){
        valTemperatureLabel1 = ui->doubleSpinBox_7Temperature->value();
        valTemperatureLabel2 = valTemperatureLabel1;
        ui->doubleSpinBox_8->setValue(valTemperatureLabel2);
    }
}



