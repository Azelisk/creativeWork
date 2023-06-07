#include "checkboxdelegate.h"
#include <QCheckBox>
#include <QColor>
#include <QBrush>
#include <QPainter>

CheckBoxDelegate::CheckBoxDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
}

QWidget *CheckBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    QCheckBox *checkBox = new QCheckBox(parent);
    return checkBox;
}

void CheckBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
    if (checkBox)
        checkBox->setChecked(index.model()->data(index, Qt::EditRole).toBool());
    else
        QStyledItemDelegate::setEditorData(editor, index);
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
    if (checkBox)
    {
        model->setData(index, checkBox->isChecked(), Qt::EditRole);

        // Emit dataChanged signal to trigger the view update
        emit model->dataChanged(index, index, {Qt::BackgroundRole});
    }
    else
    {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);

    editor->setGeometry(option.rect);
}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);

    if (index.column() == 1)
    {
        bool checked = index.model()->data(index, Qt::EditRole).toBool();
        if (checked)
        {
            QColor backgroundColor(Qt::green);
            painter->fillRect(option.rect, backgroundColor);
        }
    }
}
