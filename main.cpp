#include "qeditablelistview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QEditableListView w;
    w.appendItem("a","Compressor");
    w.appendItem("b","Bass");
    w.appendItem("c","Clarity");
    w.appendItem("d","Master Gain");
    w.appendItem("e","Reverb");
    w.show();

    QApplication::setPalette(w.style()->standardPalette());

    return a.exec();
}
