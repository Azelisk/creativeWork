#include "calendardelegate.h"
#include <QCalendarWidget>

CalendarDelegate::CalendarDelegate(QObject* parent) : QStyledItemDelegate(parent)
{
}

QWidget* CalendarDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index);

    // Создаем виджет календаря
    QCalendarWidget* calendarWidget = new QCalendarWidget(parent);

    // Устанавливаем позицию виджета календаря рядом с ячейкой
    QPoint pos = option.rect.bottomRight();
    calendarWidget->move(pos);

    return calendarWidget;
}



void CalendarDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    QCalendarWidget* calendarWidget = qobject_cast<QCalendarWidget*>(editor);
    if (calendarWidget)
    {
        // Получаем значение из модели (в нашем случае из столбца Дата)
        QVariant value = index.model()->data(index, Qt::EditRole);
        QDate date = value.toDate();

        // Устанавливаем выбранную дату в календарь
        calendarWidget->setSelectedDate(date);
    }
    else
    {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void CalendarDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    QCalendarWidget* calendarWidget = qobject_cast<QCalendarWidget*>(editor);
    if (calendarWidget)
    {
        // Получаем выбранную дату из календаря
        QDate selectedDate = calendarWidget->selectedDate();

        // Устанавливаем значение в модель (в нашем случае в столбец Дата)
        model->setData(index, selectedDate, Qt::EditRole);
    }
    else
    {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void CalendarDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index);

    // Устанавливаем позицию и размеры виджета календаря
    editor->setGeometry(option.rect);
}

QSize CalendarDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index);

    // Указываем желаемый размер для ячейки таблицы
    return QSize(190, 70);
}

