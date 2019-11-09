#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listitem.h"

class MyDelegate : public QStyledItemDelegate  {
public:
    MyDelegate(QObject *parent=0) : QStyledItemDelegate (parent){}

    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const{
        return QSize(100, 29);
    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i=0;i<ui->listWidget->count();i++){
        listitem *li = new listitem(ui->listWidget->item(i));
        ui->listWidget->setItemWidget(ui->listWidget->item(i),li);
    }

    ui->listWidget->setItemDelegate(new MyDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}
