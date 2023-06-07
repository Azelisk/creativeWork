#include "thirdtable.h"
#include "ui_thirdtable.h"
#include "comboboxdelegate.h"

#include <QDateTime>
#include "calendardelegate.h"
#include "centeredtextdelegate.h"


void fillRandomDbWithData()
{
    QSqlDatabase randomDb = QSqlDatabase::addDatabase("QSQLITE", "RandomDb");
    randomDb.setDatabaseName("/.randomDb.db");
    if (randomDb.open())
    {
        QSqlQuery query(randomDb);
        query.exec("CREATE TABLE RandomTable (Транспорт TEXT, ФИО TEXT, Город TEXT, Дата TEXT, Стоимость INT)");

        // Заполнение таблицы RandomTable данными
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Поезд', 'Иванов И.И.', 'Москва', '2023-12-01', 13207)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Поезд', 'Петров Д.П.', 'Санкт-Петербург', '2025-06-02', 15032)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Самолёт', 'Кутуев К.Л.', 'Казань', '2023-07-01', 8450)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Такси', 'Филин Ф.Ф.', 'Пермь', '2023-06-14', 9650)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Самолёт', 'Смирнов А.А.', 'Владивосток', '2024-10-01', 17460)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Автобус', 'Никитина В.Р.', 'Екатеринбург', '2023-07-22', 10245)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Поезд', 'Иванов И.И.', 'Москва', '2023-08-01', 11407)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Самолёт', 'Петров Д.П.', 'Санкт-Петербург', '2024-01-28', 22150)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Автобус', 'Кутуев К.Л.', 'Самара', '2023-09-01', 5980)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Самолёт', 'Дулова Л.Ф.', 'Сочи', '2024-02-19', 19620)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Поезд', 'Носов Г.Н.', 'Новосибирск', '2023-10-25', 12563)");
        query.exec("INSERT INTO RandomTable (Транспорт, ФИО, Город, Дата, Стоимость) "
                   "VALUES ('Автобус', 'Никитина В.Р.', 'Екатеринбург', '2024-09-22', 10957)");


        randomDb.close();
    }
    else
    {
        qDebug("Failed to open random database");
    }
}

void thirdTable::fillTableWithRandomValues()
{
    fillRandomDbWithData();
    // Открываем другую базу данных с рандомными значениями
    QSqlDatabase randomDb = QSqlDatabase::addDatabase("QSQLITE", "RandomDb");
    randomDb.setDatabaseName("/.randomDb.db");
    if (randomDb.open())
    {
        qDebug("Random database opened");

        // Создаем запрос для выборки случайных записей
        QSqlQuery randomQuery(randomDb);
        randomQuery.prepare("SELECT Транспорт, ФИО, Город, Дата, Стоимость FROM RandomTable ORDER BY RANDOM() LIMIT :limit");
        randomQuery.bindValue(":limit", model3->rowCount()); // Ограничение на количество случайных записей

        if (randomQuery.exec())
        {
            int row = 0;
            while (randomQuery.next() && row < model3->rowCount())
            {
                // Получаем значения из случайных записей
                QString transport = randomQuery.value(0).toString();
                QString fio = randomQuery.value(1).toString();
                QString city = randomQuery.value(2).toString();
                QString date = randomQuery.value(3).toString();
                int cost = randomQuery.value(4).toInt();

                // Заполняем модель таблицы значениями
                model3->setData(model3->index(row, 0), transport);
                model3->setData(model3->index(row, 1), fio);
                model3->setData(model3->index(row, 2), city);
                model3->setData(model3->index(row, 3), date);
                model3->setData(model3->index(row, 4), cost);

                row++;
            }

            model3->submitAll(); // Применяем изменения к базе данных
            model3->select(); // Обновляем модель, чтобы отобразить изменения
        }
        else
        {
            qDebug("Failed to execute random query");
        }

        randomDb.close();
    }
    else
    {
        qDebug("Failed to open random database");
    }
}


thirdTable::thirdTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdTable)
{
    ui->setupUi(this);
    setWindowTitle("Командировки");
    QIcon icon("C:/Users/HP/Desktop/travel.png");
    QPixmap pixmap = icon.pixmap(QSize(120, 120)); // установите нужный размер иконки
    setWindowIcon(QIcon(pixmap));

    ui->pushButton->setStyleSheet("background-color: green; color: white;");
    ui->pushButton_2->setStyleSheet("background-color: red; color: white;");

    db3 = QSqlDatabase::addDatabase("QSQLITE");
    db3.setDatabaseName("/.testDb.db");
    if(db3.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }

    query3 = new QSqlQuery(db3);
    query3->exec("CREATE TABLE Командировкa(Транспорт TEXT, ФИО сотрудника TEXT, Город TEXT, Дата TEXT, Стоимость INT);");

    model3 = new QSqlTableModel(this,db3);
    model3->setTable("Командировкa2");
    model3->select();

    CalendarDelegate* calendarDelegate = new CalendarDelegate(this);
    ui->tableView->setItemDelegateForColumn(3, calendarDelegate);

    ui->tableView->setModel(model3);

    ComboBoxDelegate* comboBoxDelegate = new ComboBoxDelegate(this);
    ui->tableView->setItemDelegateForColumn(0, comboBoxDelegate);


    ui->tableView->setColumnWidth(0, 100);  // Установить ширину столбца 0
    ui->tableView->setColumnWidth(1, 125);  // Установить ширину столбца 1
    ui->tableView->setColumnWidth(2, 113);
    ui->tableView->setColumnWidth(3, 314);  // Установить ширину столбца 2
    ui->tableView->setColumnWidth(4, 110);

    int dateColumn = 3;
    Qt::SortOrder sortOrder = Qt::AscendingOrder;
    model3->setSort(dateColumn, sortOrder);
    model3->select();

    CenteredTextDelegate* centeredTextDelegate = new CenteredTextDelegate(this);
//    ui->tableView->setItemDelegateForColumn(0, centeredTextDelegate);
    ui->tableView->setItemDelegateForColumn(1, centeredTextDelegate);
    ui->tableView->setItemDelegateForColumn(2, centeredTextDelegate);
//    ui->tableView->setItemDelegateForColumn(3, centeredTextDelegate);
    ui->tableView->setItemDelegateForColumn(4, centeredTextDelegate);
}

thirdTable::~thirdTable()
{
    delete ui;
}

void thirdTable::on_pushButton_clicked()
{
    model3->insertRow(model3->rowCount());

    fillTableWithRandomValues();
}


void thirdTable::on_pushButton_2_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    int row = currentIndex.row();

    if (row >= 0) // Проверяем, что выбрана действительная строка
    {
        if (model3->removeRow(row))
        {
            model3->submitAll();
            model3->select();
        }
    }
}


void thirdTable::on_tableView_clicked(const QModelIndex &index)
{
    row3 = index.row();
}

