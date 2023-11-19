#ifndef DESKTOPMAINWINDOW_H
#define DESKTOPMAINWINDOW_H

#include <QMainWindow>
#include <mdbrole.hxx>

QT_BEGIN_NAMESPACE
namespace Ui { class DesktopMainWindow; }
QT_END_NAMESPACE

class DesktopMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DesktopMainWindow(QWidget *parent = nullptr);
    ~DesktopMainWindow();
private:
    void addItemToTableWidget(const QString& name, const QString& telp,
                              const QString& email);

private slots:
    void on_actionExit_triggered();
    void on_action_Find_triggered();
    void on_action_About_triggered();
    void on_action_Sort_triggered();
    void on_actionAdd_Item_triggered();

    void on_actionDelete_triggered();

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::DesktopMainWindow *ui;
};
#endif // DESKTOPMAINWINDOW_H
