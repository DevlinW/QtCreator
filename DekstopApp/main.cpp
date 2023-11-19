#include "desktopmainwindow.h"
#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesktopMainWindow w;
    qDebug() << "SQL Drivers: " << QSqlDatabase::drivers();
    w.show();
    return a.exec();
}
