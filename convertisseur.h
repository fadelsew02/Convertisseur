#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H

#include <QMainWindow>
#include <QVector>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class Convertisseur; }
QT_END_NAMESPACE

class Convertisseur : public QMainWindow
{
    Q_OBJECT

public:
    Convertisseur(QWidget *parent = nullptr);
    void convertirToSecondLabelDevise(void);
    void convertirToSecondLabelPoids(void);
    void convertirToSecondLabelTemperature(void);
    ~Convertisseur();

private:
    Ui::Convertisseur *ui;
    double taux;
    double valDeviseLabel1, valDeviseLabel2;
    double valTemperatureLabel1, valTemperatureLabel2;
    double valPoidsLabel1, valPoidsLabel2;
    QStringList myStringListDevise;
    QStringList myStringListPoids;
    QStringList myStringListTemperature;
    double tableauDevise[10][10] = {{1.00, 0.92, 109.22, 0.75, 0.99, 1.30, 1.25, 1.35, 7.79, 6.44 },
                              {1.09, 1.00, 118.73, 0.81, 1.06, 1.39, 1.34, 1.45, 8.38, 6.92 },
                              {0.009, 0.008, 1.00, 0.007, 0.009, 0.01, 0.009, 0.01, 0.06, 0.05},
                              {1.34, 1.23, 146.44, 1.00, 1.31, 1.72, 1.66, 1.80, 10.41, 8.60 },
                              {1.01, 0.93, 110.79, 0.76, 1.00, 1.31, 1.26, 1.36, 7.87, 6.49 },
                              {0.77, 0.71, 84.19, 0.58, 0.76, 1.00, 0.96, 1.04, 6.02, 4.97 },
                              {0.80, 0.74, 87.95, 0.60, 0.79, 1.04, 1.00, 1.08, 6.23, 5.14 },
                              {0.74, 0.68, 80.76, 0.55, 0.72, 0.94, 0.90, 1.00, 5.77, 4.76 },
                              {0.13, 0.12, 14.18, 0.10, 0.13, 0.17, 0.16, 0.17, 1.00, 0.82 },
                              {0.16, 0.15, 17.47, 0.12, 0.16, 0.21, 0.20, 0.22, 1.27, 1.00 }};

    double tableauPoids[8][8] = {{1.00, 0.001, 0.00220462, 0.035274, 5, 0.000001, 0.00001, 0.000157 },
                                    {1000, 1.00, 2.20462, 35.274, 5000, 0.001, 0.01, 0.157473 },
                                    {453.592, 0.453592, 1.00, 16, 2267.96, 0.000453592, 0.00453592, 0.0714286},
                                    {28.3495, 0.0283495, 0.0625, 1.00, 141.748, 0.0000283495, 0.000283495, 0.00446429 },
                                    {0.2, 0.0002, 0.000440925, 0.00705479, 1.00, 0.0000002, 0.000002, 0.0000311035 },
                                    {1000000, 1000, 2204.62, 35273.9619, 5000000, 1.00, 10, 157.473 },
                                    {100000, 100, 220.462, 3527.39619, 500000, 0.1, 1.00, 15.7473 },
                                    {6350.29, 6.35029, 14, 224, 31751.5, 0.00635029, 0.0635029, 1.00 }};

    double tableauTemperature[4][4] = {{1.00, 32, 273.15, 491.67 },
                                 {32, 1.00, 241.15, 459.67 },
                                 {273.15, 459.67, 1.00, 0},
                                 {491.15, 459.67, 32, 1.00}};
};
#endif // CONVERTISSEUR_H
