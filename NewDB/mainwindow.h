#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "firsttable.h"
#include "secondtable.h"
#include "thirdtable.h"
#include "fourthtable.h"

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
    void on_pushButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    firstTable *ft;
    secondTable *st;
    thirdTable *tt;
    fourthTable *fr;
};
#endif // MAINWINDOW_H
