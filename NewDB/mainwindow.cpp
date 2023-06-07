#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listWidget->addItem("Организация приёма");
    ui->listWidget->addItem("Письма");
    ui->listWidget->addItem("Командировки");
    ui->listWidget->addItem("Блокнот");

    // Установка размера шрифта для названий строк
    QFont font = ui->listWidget->font();
    font.setPointSize(18);
    ui->listWidget->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    if(ui->listWidget->currentItem()->text() == "Организация приёма")
    {
        ft = new firstTable(this);
        ft->show();
    }
    if(ui->listWidget->currentItem()->text() == "Письма")
    {
        st = new secondTable(this);
        st->show();
    }
    if(ui->listWidget->currentItem()->text() == "Командировки")
    {
        tt = new thirdTable(this);
        tt->show();
    }
    if(ui->listWidget->currentItem()->text() == "Блокнот")
    {
        fr = new fourthTable(this);
        fr->show();
    }
}
