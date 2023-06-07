// secondtable.h

#ifndef SECONDTABLE_H
#define SECONDTABLE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>

namespace Ui {
class secondTable;
}

class secondTable : public QDialog
{
    Q_OBJECT

public:
    explicit secondTable(QWidget *parent = nullptr);
    ~secondTable();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void handleCheckBoxClicked();
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::secondTable *ui;
    QSqlDatabase db2;
    QSqlTableModel *model2;
    QSqlQuery *query2;
    int row2;
};

#endif // SECONDTABLE_H
