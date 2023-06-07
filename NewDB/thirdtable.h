#ifndef THIRDTABLE_H
#define THIRDTABLE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class thirdTable;
}

class thirdTable : public QDialog
{
    Q_OBJECT

public:
    explicit thirdTable(QWidget *parent = nullptr);
    ~thirdTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void fillTableWithRandomValues();

private:
    Ui::thirdTable *ui;
    QSqlDatabase db3;
    QSqlQuery *query3;
    QSqlTableModel *model3;
    int row3;
};

#endif // THIRDTABLE_H
