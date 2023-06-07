#ifndef FOURTHTABLE_H
#define FOURTHTABLE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class fourthTable;
}

class fourthTable : public QDialog
{
    Q_OBJECT

public:
    explicit fourthTable(QWidget *parent = nullptr);
    ~fourthTable();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void onDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);

private:
    Ui::fourthTable *ui;
    QSqlDatabase db4;
    QSqlQuery *query4;
    QSqlTableModel *model4;
    int row4;
};

#endif // FOURTHTABLE_H
