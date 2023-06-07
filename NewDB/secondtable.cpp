#include "secondtable.h"
#include "ui_secondtable.h"
#include <QDateTime>
#include "calendardelegate.h"
#include "centeredtextdelegate.h"

secondTable::secondTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondTable)
{
    ui->setupUi(this);
    setWindowTitle("Письма");
    setWindowIcon(QIcon("C:/Users/HP/Desktop/later.png"));

    ui->pushButton->setStyleSheet("background-color: green; color: white;");
    ui->pushButton_2->setStyleSheet("background-color: red; color: white;");

    db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("/.testDb.db");
    if(db2.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }

    query2 = new QSqlQuery(db2);
    query2->exec("CREATE TABLE Письма(От_кого TEXT, Цель TEXT, Дата TEXT);");

    model2 = new QSqlTableModel(this,db2);
    model2->setTable("Письма");
    model2->select();

    ui->tableView->setModel(model2);

    int dateColumn = 2;
    Qt::SortOrder sortOrder = Qt::AscendingOrder;
    model2->setSort(dateColumn, sortOrder);
    model2->select();

    // Создание делегата с виджетом календаря
    CalendarDelegate* calendarDelegate = new CalendarDelegate(this);
    ui->tableView->setItemDelegateForColumn(2, calendarDelegate);

    // Установка ширины столбцов таблицы
    ui->tableView->setColumnWidth(0, 129);  // Установить ширину столбца 0
    ui->tableView->setColumnWidth(1, 185);  // Установить ширину столбца 1
    ui->tableView->setColumnWidth(2, 314);  // Установить ширину столбца 2

    // Создание делегата для столбцов, где нужно выровнять текст по центру
    CenteredTextDelegate* centeredTextDelegate = new CenteredTextDelegate(this);
    ui->tableView->setItemDelegateForColumn(0, centeredTextDelegate);
    ui->tableView->setItemDelegateForColumn(1, centeredTextDelegate);
}

secondTable::~secondTable()
{
    delete ui;
}

void secondTable::on_pushButton_clicked()
{
    model2->insertRow(model2->rowCount());
    // Получаем доступ к вертикальному заголовку таблицы
    QHeaderView* verticalHeader = ui->tableView->verticalHeader();

    // Устанавливаем желаемую высоту строк
    int rowHeight = 145; // Новая высота строк
    verticalHeader->setDefaultSectionSize(rowHeight);
}


void secondTable::on_pushButton_2_clicked()
{
    if (model2->removeRow(row2))
    {
        model2->submitAll();
        model2->select();
    }
}


void secondTable::on_tableView_clicked(const QModelIndex &index)
{
    row2 = index.row();
}
