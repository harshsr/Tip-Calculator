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

bool MainWindow::on_CalculateButton_pressed()
{

    bool billOK = false;        //to check if toDouble worked. If not we prompt the user to enter valid input
    bool tipOk = false;         //to check if toDouble worked. If not we prompt the user to enter valid input


    QString billValue = ui->BillAmount->text();
    billAmount = billValue.toDouble(&billOK);

    QString tipPerc = ui->TipPecentage->text();
    tipPercentage=tipPerc.toDouble(&tipOk);

    if (billOK&&tipOk)
    {
        tipAmount=(billAmount*tipPercentage)/100;
        totalAmount=billAmount+tipAmount;
        return true;
    }

    return false;
}

void MainWindow::on_CalculateButton_released(bool calculationOK)
{
    if(calculationOK)
    {
        QString finalText = "Tip amount is "+ QString::number( tipAmount) +". \nTotal payable amount "+QString::number(totalAmount) +".";
        ui->FinalDisplayText->setText(finalText);
    }
    else
    {
        QString finalText = "Invalid Input. Please Try Again.";
        ui->FinalDisplayText->setText(finalText);
    }
}

void MainWindow::on_BillAmount_returnPressed()
{
    ui->TipPecentage->setFocus();
}

void MainWindow::on_TipPecentage_returnPressed()
{
    ui->BillAmount->setFocus();

    on_CalculateButton_released(on_CalculateButton_pressed());
}


MainWindow::~MainWindow()
{
    delete ui;
}

