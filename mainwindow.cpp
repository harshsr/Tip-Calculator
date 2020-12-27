#include "mainwindow.h"
#include "ui_mainwindow.h"


double billAmount = 0.0;
double tipPercentage = 0.0;
double tipAmount = 0.0;
double totalAmount = 0.0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->BillAmount->setFocus();
}

void MainWindow::on_CalculateButton_pressed()
{
    QString billValue = ui->BillAmount->text();
    billAmount = billValue.toDouble();

    QString tipPerc = ui->TipPecentage->text();
    tipPercentage=tipPerc.toDouble();

    tipAmount=(billAmount*tipPercentage)/100;
    totalAmount=billAmount+tipAmount;
}

void MainWindow::on_CalculateButton_released()
{
    QString finalText = "Tip amount is "+ QString::number( tipAmount) +". \nTotal payable amount "+QString::number(totalAmount) +".";
    ui->FinalDisplayText->setText(finalText);
}

void MainWindow::on_BillAmount_returnPressed()
{
    ui->TipPecentage->setFocus();
}

void MainWindow::on_TipPecentage_returnPressed()
{
    ui->BillAmount->setFocus();
    on_CalculateButton_pressed();
    on_CalculateButton_released();
}


MainWindow::~MainWindow()
{
    delete ui;
}

