#ifndef _COMMONDEFS_INCLUDED_
#define _COMMONDEFS_INCLUDED_

#include <cmath>
#include <qpoint.h>
#include <vector>
#include <QColor>
#include<bits/stdc++.h>

#define PI M_PI
typedef QPoint XPoint;
typedef QColor Color;

namespace simplecpp {

struct Position{
    double x, y;
    Position();
    Position(double x1, double y1);
    Position operator+(Position p);
    double getX();
    double getY();
    double GetXDistance();
    double GetYDistance();
    void print(char *msg = nullptr);
};

struct RectBox{
    Position top_left;
    Position bottom_right;
    RectBox(){}
    RectBox(Position tl, Position br){
        top_left = tl;
        bottom_right = br;
    }
    bool intersects(RectBox b2){
        return (!((top_left.getX() > b2.bottom_right.getX()) ||
                  (top_left.getY() > b2.bottom_right.getY()) ||
                  (bottom_right.getX() < b2.top_left.getX()) ||
                  (bottom_right.getY() < b2.top_left.getY())));
    }
    RectBox boxUnion(RectBox s){
        RectBox r;
        r.top_left.x = std::min(top_left.x, s.top_left.x);
        r.top_left.y = std::min(top_left.y, s.top_left.y);
        r.bottom_right.x = std::max(bottom_right.x, s.bottom_right.x);
        r.bottom_right.y = std::max(bottom_right.y, s.bottom_right.y);
        return r;
    }
};

//   typedef unsigned long Color;

class Pose{
    double a11,a12,a13,a21,a22,a23;
public:
    Pose();
    Pose(double dx,double dy);
    Pose(double theta);
    Pose(double scale, bool s);
    Pose(const Pose &p, const Pose &q);
    XPoint prod(Position p) const;
    Position prodPosition(Position p);
    void compute_res_vertex(XPoint* xpt, std::vector<Position> vertex, int count) const;
    void compute_res_vertex(XPoint* xpt, Position *vertex, int count) const;
    Position unitX() const;
    Position getOrigin() const;
    Position getAtan2() const;
    double getOrientation() const;
    double X() const;
    double Y() const;
    double getScale() const;
    void setScale(double s);
    void print() const;
};

//   void wait(int seconds);
}

#endif
