#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool bCalculationOk;

private slots:

    void on_CalculateButton_pressed();

    void on_CalculateButton_released();

    void on_BillAmount_returnPressed();

    void on_TipPecentage_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
