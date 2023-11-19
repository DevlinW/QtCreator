#include "desktopmainwindow.h"
#include "ui_desktopmainwindow.h"
#include <QMessageBox>
#include "sortdialog.h"
#include "ui_sortdialog.h"
#include "finddialog.h"
#include "ui_finddialog.h"
#include "additemdialog.h"
#include "ui_additemdialog.h"

DesktopMainWindow::DesktopMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DesktopMainWindow)
{
    ui->setupUi(this);

    QStringList tableHeader;
    tableHeader << "Name" << "Phone Number" << "Email";
    ui->tableWidget->setColumnCount(tableHeader.count());
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setStyleSheet("selection-background-color: rgb(133, 199, 0);");

    addItemToTableWidget("Andi", "0818123456789", "andi@yahoo.com");
    addItemToTableWidget("Budi", "0818000000123", "budi@yahoo.com");
    addItemToTableWidget("Candy", "0818123456789", "candy@yahoo.com");
    addItemToTableWidget("Denise", "0818000000123", "denise@yahoo.com");
}

DesktopMainWindow::~DesktopMainWindow()
{
    delete ui;
}

void DesktopMainWindow::addItemToTableWidget(const QString &name, const QString &telp, const QString &email)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(telp));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(email));
}

void DesktopMainWindow::on_actionExit_triggered()
{
    close();
}

void DesktopMainWindow::on_action_Find_triggered()
{
    FindDialog d;
    d.ui->checkBoxMatchCase->setChecked(true);
    if (d.exec()==QDialog::Accepted)
    {
        qDebug() << "Find: " << d.ui->lineEditSearch->text();
    }
}

void DesktopMainWindow::on_action_About_triggered()
{
    QMessageBox::information(this, "About",
                             "Desktop Sample Application\n"
                             "(c) Copyright by Steff 2023");
}

void DesktopMainWindow::on_action_Sort_triggered()
{
    SortDialog d;
    if (d.exec()==QDialog::Accepted)
    {
        qDebug() << "Sort Accepted: " <<
            d.ui->comboBoxPrinaryColumn->currentText() <<
            "Order: " << d.ui->comboBoxPrimaryOrder->currentText();
        int nSortOrder = d.ui->comboBoxPrimaryOrder->currentIndex();
        ui->tableWidget->sortByColumn(d.ui->comboBoxPrinaryColumn->currentIndex(),
                                      Qt::SortOrder(nSortOrder));
    }
}

void DesktopMainWindow::on_actionAdd_Item_triggered()
{
    AddItemDialog d;
    if (d.exec()==QDialog::Accepted)
    {
//        qDebug() << "Item: " << d.ui->lineEditName->text()
//                 <<" " << d.ui->lineEditPhone->text()
//                 <<" " << d.ui->lineEditEmail->text();
        addItemToTableWidget(d.ui->lineEditName->text(),
                             d.ui->lineEditPhone->text(),
                             d.ui->lineEditEmail->text());
    }
}


void DesktopMainWindow::on_actionDelete_triggered()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void DesktopMainWindow::on_tableWidget_cellChanged(int row, int column)
{
    QString str = ui->tableWidget->item(row, column)->text();
    qDebug() << "Cell Changes: " << row << "," << column << ": " << str;
}

