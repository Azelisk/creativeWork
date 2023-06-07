#ifndef FIRSTTABLE_H
#define FIRSTTABLE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>


namespace Ui {
class firstTable;
}

class firstTable : public QDialog
{
    Q_OBJECT

public:
    explicit firstTable(QWidget *parent = nullptr);
    ~firstTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::firstTable *ui;
    QSqlDatabase db;
    QSqlQuery *query1;
    QSqlTableModel *model1;
    int row1;
};

#endif // FIRSTTABLE_H
