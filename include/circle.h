#ifndef _POINT_INCLUDED_
#define _POINT_INCLUDED_

#include <sprite.h>
#include <vector>
#include <circle.h>
#include <vector>
#include <canvas.h>
#include <sprite.h>
#include <turtle.h>
#include <simplecpp.h>
#include <cstring>
#include <cstdlib>
#include <bits/stdc++.h>
#include <commondefs.h>
#include <line.h>
#include <QPixmap>
#include <sprite.h>

#include <QtGui>
#include <QDebug>

typedef QPoint XPoint ;
typedef QColor Color;

namespace simplecpp{
class Circle : public Sprite{
protected:
    double radius;
public:

    float x,y;
    int num_seg;

    Circle(Composite* owner = NULL);
    Circle(const double x, const double y, const double radius=10,
           Composite* owner=NULL);
    double getRadius();
    void init(const double x, const double y, const double radius=10,
              bool repaintP=true);
    void reset(const double x, const double y, const double radius=10,
               bool repaintP=true);
    virtual void paint(Pose *p=NULL);
    virtual Sprite * clone();
    void scale(double s, bool repaintP=true);
};
}
#endif
