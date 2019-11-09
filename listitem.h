#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class listitem;
}

class listitem : public QWidget
{
    Q_OBJECT

public:
    explicit listitem(QListWidgetItem* _item,QWidget *parent = nullptr);
    ~listitem();
    void updateButtons();

public slots:
    void moveUp();
    void moveDown();

private:
    Ui::listitem *ui;
    QListWidgetItem* item;
};

#endif // LISTITEM_H
