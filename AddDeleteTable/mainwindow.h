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

private slots:
    void on_actionAdd_triggered();
    void on_actionDelete_triggered();

private:
     Ui::MainWindow *ui;
    void addItem (const QString& kode,
                 const QString& nama,
                 const QString& harga,
                 const QString& jumlah);

};
#endif // MAINWINDOW_H
