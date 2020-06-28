#include "editablelistitem.h"
#include "ui_listitem.h"

EditableListItem::EditableListItem(QString _id, QString _name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listitem)
{
    ui->setupUi(this);
    id = _id;
    name = _name;
    ui->label->setText(name);

    connect(ui->up, &QAbstractButton::clicked, this, &EditableListItem::upPressed);
    connect(ui->down, &QAbstractButton::clicked, this, &EditableListItem::downPressed);
}

EditableListItem::~EditableListItem()
{
    delete ui;
}

QString EditableListItem::getName() const
{
    return name;
}

QString EditableListItem::getId() const
{
    return id;
}

void EditableListItem::setButtonsEnabled(bool up, bool down){
    ui->up->setEnabled(up);
    ui->down->setEnabled(down);
}
