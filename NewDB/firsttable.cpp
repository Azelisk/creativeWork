#include "firsttable.h"
#include "ui_firsttable.h"
#include "comboboxdelegate.h"
#include "centeredtextdelegate.h"

#include <QtWidgets>
#include <QtSql>

firstTable::firstTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstTable)
{
    ui->setupUi(this);
    setWindowTitle("Организация приёма");

    ui->pushButton->setStyleSheet("background-color: green; color: white;");
    ui->pushButton_2->setStyleSheet("background-color: red; color: white;");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/.testDb.db");
    if(db.open())
        qDebug("open");
    else
        qDebug("no open");

    query1 = new QSqlQuery(db);
    query1->exec("CREATE TABLE ОрганизацияПриёма(Номер_телефона INT, Имя TEXT, Компания TEXT, Цель_встречи TEXT);");

    // Определение модели таблицы
    model1 = new QSqlTableModel(this, db);
    model1->setTable("ОрганизацияПриёма");
    model1->select();

    ui->tableView->setModel(model1);

    // Установка ширины столбцов таблицы
    ui->tableView->setColumnWidth(0, 180);  // Установить ширину столбца 0
    ui->tableView->setColumnWidth(1, 180);  // Установить ширину столбца 1
    ui->tableView->setColumnWidth(2, 250);  // Установить ширину столбца 2
    ui->tableView->setColumnWidth(3, 294);  // Установить ширину столбца 3

    // Создание делегата
    ComboBoxDelegate* delegate = new ComboBoxDelegate(this);
    ui->tableView->setItemDelegateForColumn(0, delegate);

    // Создание делегата для столбцов, где нужно выровнять текст по центру
    CenteredTextDelegate* centeredTextDelegate = new CenteredTextDelegate(this);
    //ui->tableView->setItemDelegateForColumn(0, centeredTextDelegate); // Выравнивание текста
    ui->tableView->setItemDelegateForColumn(1, centeredTextDelegate);
    ui->tableView->setItemDelegateForColumn(2, centeredTextDelegate);
    ui->tableView->setItemDelegateForColumn(3, centeredTextDelegate);
}

firstTable::~firstTable()
{
    delete ui;
}

void firstTable::on_pushButton_clicked()
{
    model1->insertRow(model1->rowCount());
}

void firstTable::on_pushButton_2_clicked()
{
    if (model1->removeRow(row1))
    {
        model1->submitAll(); // Применить изменения к базе данных
        model1->select(); // Обновить модель, чтобы отобразить изменения
    }
}

void firstTable::on_tableView_clicked(const QModelIndex &index)
{
    row1 = index.row();
}



