#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double a = ui->a_value->text().toDouble();
    double b = ui->b_value->text().toDouble();
    double x = (pow(log10(a), 3) + sin(pow(b, 2)));
    double y = pow(a, 3) / pow(b, x);
    double z = pow(abs(x), 1 / 6) + pow(abs(x) + abs(y), 1 / 3);
    QString x1 = QString::number(x);
    QString y1 = QString::number(y);
    QString z1 = QString::number(z);
    ui->X_value->setText(x1);
    ui->Y_value->setText(y1);
    ui->Z_value->setText(z1);
}


void MainWindow::on_pushButton_2_clicked()
{
    double x = ui->x_value->text().toDouble();
    if (x < 0){
        ui->Y_value_2->setText("0");
    }
    else if (0 <= x < 1){
        QString y2 = QString::number(pow(x, 1/2));
        ui->Y_value_2->setText(y2);
    }
    else{
        QString y2 = QString::number(x * x);
        ui->Y_value_2->setText(y2);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    double x = ui->X_value_2->text().toDouble();
    double m = ui->m_value->text().toDouble();
    double counter = 0;
    for (int i = 1; i < 2 * m + 1; i += 2){
        counter += (i * pow(x, -2));
    }
    QString s = QString::number(counter);
    ui->S_value->setText(s);
}

