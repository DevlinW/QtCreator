#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_hitung_clicked()
{
    if (ui->tambahRadioButton->isChecked()){
        float x = ui->x->text().toFloat();
        float y = ui->y->text().toFloat();
        float z = x+y;

        ui->z->setNum(z);
    }

    if (ui->kurangRadioButton->isChecked()){
        float x = ui->x->text().toFloat();
        float y = ui->y->text().toFloat();
        float z = x-y;

        ui->z->setNum(z);
    }

    if (ui->kaliRadioButton->isChecked()){
        float x = ui->x->text().toFloat();
        float y = ui->y->text().toFloat();
        float z = x*y;

        ui->z->setNum(z);
    }

    if (ui->bagiRadioButton->isChecked()){
        float x = ui->x->text().toFloat();
        float y = ui->y->text().toFloat();
        float z = x/y;

        ui->z->setNum(z);
    }
}

