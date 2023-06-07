#include "fourthtable.h"
#include "ui_fourthtable.h"
#include <QtWidgets>
#include <QtSql>
#include "checkboxdelegate.h"

fourthTable::fourthTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourthTable),
    row4(-1)
{
    ui->setupUi(this);
    setWindowTitle("Блокнот");
    QIcon icon("C:/Users/HP/Desktop/book.png");
    QPixmap pixmap = icon.pixmap(QSize(120, 120)); // установите нужный размер иконки
    setWindowIcon(QIcon(pixmap));


    ui->pushButton->setStyleSheet("background-color: green; color: white;");
    ui->pushButton_2->setStyleSheet("background-color: red; color: white;");

    db4 = QSqlDatabase::addDatabase("QSQLITE");
    db4.setDatabaseName("/.testDb4.db");
    if (db4.open())
        qDebug() << "open";
    else
        qDebug() << "no open";

    query4 = new QSqlQuery(db4);
    query4->exec("CREATE TABLE IF NOT EXISTS Блокнот887(Событие TEXT, Выполнено KEY)");

    model4 = new QSqlTableModel(this, db4);
    model4->setTable("Блокнот887");
    model4->select();

    CheckBoxDelegate *checkBoxDelegate = new CheckBoxDelegate(this);
    ui->tableView->setItemDelegateForColumn(1, checkBoxDelegate);

    ui->tableView->setModel(model4);

    connect(model4, &QSqlTableModel::dataChanged, this, &fourthTable::onDataChanged);

    // Установка ширины столбцов таблицы
    ui->tableView->setColumnWidth(0, 270);  // Установить ширину столбца 0
    ui->tableView->setColumnWidth(1, 100);  // Установить ширину столбца 1
}

fourthTable::~fourthTable()
{
    delete ui;
}

void fourthTable::on_pushButton_clicked()
{
    model4->insertRow(model4->rowCount());
}

void fourthTable::on_pushButton_2_clicked()
{
    if (model4->removeRow(row4)) {
            model4->submitAll();
            model4->select();
        }
}

void fourthTable::on_tableView_clicked(const QModelIndex &index)
{
    row4 = index.row();
}

void fourthTable::onDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    Q_UNUSED(roles);

    if (topLeft.column() == 1)
    {
        for (int row = topLeft.row(); row <= bottomRight.row(); ++row)
        {
            QModelIndex index = model4->index(row, 1);
            QBrush brush(Qt::green);
            model4->setData(index, brush, Qt::BackgroundRole);
        }
    }
}
