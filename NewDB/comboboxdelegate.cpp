#include "comboboxdelegate.h"
#include <QComboBox>
#include <QLineEdit>

ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget* ComboBoxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QComboBox* editor = new QComboBox(parent);
    editor->addItem("Самолёт");
    editor->addItem("Поезд");
    editor->addItem("Машина");

    if (index.column() == 0) {
        QLineEdit* lineEdit = new QLineEdit(parent);
        lineEdit->setMaxLength(11);
        editor->setLineEdit(lineEdit);
    }

    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox*>(editor);
    if (comboBox) {
        // Получение данных из модели
        QVariant data = index.model()->data(index, Qt::EditRole);
        // Установка выбранного значения в комбо-боксе
        comboBox->setCurrentText(data.toString());
    }
}

void ComboBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    QComboBox* comboBox = qobject_cast<QComboBox*>(editor);
    if (comboBox) {
        QString selectedText = comboBox->currentText();

        if (index.column() == 0) {
            QLineEdit* lineEdit = comboBox->lineEdit();
            if (lineEdit) {
                QString text = lineEdit->text();
                if (text.length() > 11)
                    text = text.left(11);
                selectedText = text;
            }
        }

        model->setData(index, selectedText, Qt::EditRole);
    }
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
