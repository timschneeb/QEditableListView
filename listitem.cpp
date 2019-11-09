#include "listitem.h"
#include "ui_listitem.h"

listitem::listitem(QListWidgetItem* _item,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listitem)
{
    ui->setupUi(this);
    item = _item;
    updateButtons();
    connect(ui->up,SIGNAL(clicked()),this,SLOT(moveUp()));
    connect(ui->down,SIGNAL(clicked()),this,SLOT(moveDown()));
}

listitem::~listitem()
{
    delete ui;
}

void listitem::updateButtons(){
    /*if(item->listWidget()->row(item) == 0)
        ui->up->setEnabled(false);
    else
        ui->up->setEnabled(true);

   if(item->listWidget()->row(item) == item->listWidget()->count()-1)
       ui->down->setEnabled(false);
   else
       ui->down->setEnabled(true);*/
}

void listitem::moveUp(){
    QListWidgetItem *current = item;

    int currentRow = item->listWidget()->row(current);
    int nextRow = currentRow + 1;
    QListWidgetItem* itemOne = item->listWidget()->item( currentRow );
    QListWidgetItem* itemTwo = item->listWidget()->item( nextRow );

    item->listWidget()->takeItem( currentRow + 1);
    item->listWidget()->takeItem( nextRow + 2 );

    item->listWidget()->insertItem( currentRow, itemTwo );
    item->listWidget()->insertItem( nextRow, itemOne );



    /*for(int i=0;i<item->listWidget()->count();i++){
        listitem* li = static_cast<listitem*>(item->listWidget()->itemWidget(item->listWidget()->item(i)));
        li->updateButtons();
    }*/
}
void listitem::moveDown(){

    for(int i=0;i<item->listWidget()->count();i++){
        listitem* li = static_cast<listitem*>(item->listWidget()->itemWidget(item->listWidget()->item(i)));
        li->updateButtons();
    }
}
