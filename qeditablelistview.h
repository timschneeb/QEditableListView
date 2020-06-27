/*
    MIT License

    Copyright (c) 2020 Tim Schneeberger (ThePBone)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef QEDITABLELISTVIEW_H
#define QEDITABLELISTVIEW_H

#include <QStyledItemDelegate>
#include <QListWidget>
#include "editablelistitem.h"

class QEditableListView : public QListWidget
{
    Q_OBJECT
public:
    QEditableListView(QWidget* parent = nullptr);

    void appendItem(QString id, QString name);
    void removeItem(QString id);

    QString getIdByIndex(int index);
    QString getNameByIndex(int index);

signals:
    void itemOrderChanged();

private:
    QList<EditableListItem*> listitems;

    class EListView : public QStyledItemDelegate  {
    public:
        EListView(QObject *parent=0) : QStyledItemDelegate (parent){}

        QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const{
            return QSize(100, 29);
        }
    };
    void populateItems();
    EditableListItem *buildItem(QString id, QString name);
};

#endif // QEDITABLELISTVIEW_H
