#ifndef _TURTLE_INCLUDED_
#define _TURTLE_INCLUDED_

#include <polygon.h>
#include <commondefs.h>
#include <vector>
#include <simplecpp.h>
#include <turtleSim.h>
#include <sprite.h>
#include <QColor>

typedef QPoint XPoint ;
typedef QColor Color;

namespace simplecpp{
class Turtle : public Polygon{

public:
    Turtle(Composite* owner=NULL);
};
}

#endif



