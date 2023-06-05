#ifndef COLR_H
#define COLR_H

#include <simplecpp.h>

#include <QtGui>
#include <QtGui/QColor>
#include <map>

namespace simplecpp{

class COLR {
protected:
    QMap<QString, QColor> clr;
    QMap<QString, QColor>::iterator it;

public:
    COLR();
    void init();
    QColor getColor(QString c);
};
}
#endif // COLR_H
