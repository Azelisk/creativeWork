#include "centeredtextdelegate.h"
#include <QPainter>

CenteredTextDelegate::CenteredTextDelegate(QObject* parent) : QStyledItemDelegate(parent) {}

void CenteredTextDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    // Устанавливаем выравнивание текста в середину ячейки
    Qt::Alignment alignment = Qt::AlignCenter;

    // Получаем текст из модели
    QString text = index.data(Qt::DisplayRole).toString();

    // Рисуем текст в середине ячейки
    painter->drawText(option.rect, alignment, text);
}

QSize CenteredTextDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    // Возвращаем размер ячейки по умолчанию
    return QStyledItemDelegate::sizeHint(option, index);
}
