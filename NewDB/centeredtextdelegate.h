#ifndef CENTEREDTEXTDELEGATE_H
#define CENTEREDTEXTDELEGATE_H

#include <QStyledItemDelegate>

class CenteredTextDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CenteredTextDelegate(QObject* parent = nullptr);

    // Переопределенный метод отрисовки ячейки
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

    // Переопределенный метод для задания размера ячейки
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};

#endif // CENTEREDTEXTDELEGATE_H
