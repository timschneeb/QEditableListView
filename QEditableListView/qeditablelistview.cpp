#include "editablelistitem.h"
#include "qeditablelistview.h"

QEditableListView::QEditableListView(QWidget* parent) : QListWidget(parent)
{
    this->setItemDelegate(new EListView());
}

void QEditableListView::appendItem(QString id, QString name){
    listitems.append(buildItem(id, name));
    populateItems();
}
void QEditableListView::removeItem(QString id){
    for(auto item : listitems)
        if(item->getId() == id)
            listitems.removeOne(item);

    populateItems();
}

QString QEditableListView::getIdByIndex(int index){
    EditableListItem* t = static_cast<EditableListItem*>(itemWidget(item(index)));
    if(t != nullptr){
        return t->getId();
    }
    return "";
}
QString QEditableListView::getNameByIndex(int index){
    EditableListItem* t = static_cast<EditableListItem*>(itemWidget(item(index)));
    if(t != nullptr){
        return t->getName();
    }
    return "";
}
EditableListItem* QEditableListView::buildItem(QString id, QString name){
    EditableListItem* li = new EditableListItem(id, name);
    connect(li, &EditableListItem::upPressed, [=]{
        int curr_index = this->currentRow();

        for(int i = 0; i < count(); i++){
            EditableListItem* t = static_cast<EditableListItem*>(itemWidget(item(i)));
            if(t != nullptr){
                if(t->getId() == li->getId()){
                    curr_index = i;
                    break;
                }
            }
        }

        if ( curr_index < 1 || curr_index >= listitems.size() )
            return;

        qSwap(listitems[curr_index],listitems[curr_index-1]);

        populateItems();
        setCurrentRow(curr_index-1);

        emit itemOrderChanged();
    });
    connect(li, &EditableListItem::downPressed, [=]{
        int curr_index = this->currentRow();

        for(int i = 0; i < count(); i++){
            EditableListItem* t = static_cast<EditableListItem*>(itemWidget(item(i)));
            if(t != nullptr){
                if(t->getId() == li->getId()){
                    curr_index = i;
                    break;
                }
            }
        }

        if ( curr_index < 0 || curr_index >= listitems.size() - 1 )
            return;

        qSwap(listitems[curr_index],listitems[curr_index+1]);

        populateItems();
        setCurrentRow(curr_index+1);

        emit itemOrderChanged();
    });
    return li;
}

void QEditableListView::populateItems(){
    this->clear();
    for(auto item : listitems){
        QListWidgetItem* newItem = new QListWidgetItem();
        this->addItem(newItem);

        auto view = buildItem(item->getId(), item->getName());
        if(item == listitems.first())
            view->setButtonsEnabled(false, true);
        else if(item == listitems.last())
            view->setButtonsEnabled(true, false);
        this->setItemWidget(newItem, view);
    }
}
