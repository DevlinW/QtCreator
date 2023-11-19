#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList tableHeader;
    tableHeader << "Kode" << "Nama" << "Harga Satuan" << "Jumlah";
    ui -> tableWidget -> setColumnCount(tableHeader.count());
    ui -> tableWidget -> setHorizontalHeaderLabels(tableHeader);
    ui -> tableWidget -> horizontalHeader() -> setStretchLastSection(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setStyleSheet("selection-background-color: rgb(100,0,150)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItem(const QString& kode,
                         const QString& nama,
                         const QString& harga,
                         const QString& jumlah)
{
    int row = ui -> tableWidget -> rowCount();
    ui -> tableWidget -> setRowCount(row+1);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(kode));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nama));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(harga));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(jumlah));
}


void MainWindow::on_actionAdd_triggered()
{
    Dialog d;
    if (d.exec() == QDialog::Accepted){
        addItem(
            d.ui -> Kode -> text(),
            d.ui -> Nama -> text(),
            d.ui -> Harga -> text(),
            d.ui -> Jumlah -> text());
    }
}


void MainWindow::on_actionDelete_triggered()
{
     ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

