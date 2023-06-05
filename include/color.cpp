
#include <color.h>
#include<simplecpp.h>

namespace simplecpp{
COLR::COLR() {
    init();
}

void COLR::init() {
    clr.insert("white", QColor(255, 255, 255));
    clr.insert("red", QColor(255, 0, 0));
    clr.insert("green", QColor(0, 255, 0));
    clr.insert("blue", QColor(0, 0, 255));
    clr.insert("black", QColor(0, 0, 0));
    clr.insert("yellow", QColor(255, 255, 0));
    clr.insert("gray", QColor(128, 128, 128));
    clr.insert("orange", QColor(255, 69, 0));
}

QColor COLR::getColor(QString c) {
    it = clr.find(c);
    if (it != clr.end()) {
        return it.value();
    } else {
        return QColor(1, 0, 0);
    }
}
}



