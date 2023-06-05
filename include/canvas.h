#ifndef _CANVAS_INCLUDED
#define _CANVAS_INCLUDED

#include <memory>
#include <algorithm>
/*
 * #include <QtGui>
#include <QDebug>
#include <QPixmap>
#include <QRandomGenerator>
#include <QString>
#include <QFontMetrics>
#include <QtCore>
#include <QEvent>
#include <QEventLoop>
#include <QMouseEvent>
#include <QtGui>
#include <QObject>
#include <QWindow>
#include <qfontdatabase.h>
#include <QCursor>
#include <QGuiApplication>
#include <QCoreApplication>
#include <QBackingStore>
#include <QPainter>
#include <QTextOption>
*/
#include <xevent.h>
#include <bits/stdc++.h>

#define GXcopy 0


typedef QPoint XPoint ;
typedef QColor Color;


namespace simplecpp {
class Sprite;
class Turtle;
class XEvent;

void closeCanvas();
Turtle& theSystemTurtle();
int canvas_width();
int canvas_height();
void addSprite(Sprite *t);
void repaint();
void removeSprite(Sprite *t);
void c_imprint(Sprite* s);
void imprintLine(short x1, short y1, short x2, short y2, QColor lineColor=Qt::black, int lineWidth = 2);
void beginFrame();
void endFrame();
void spriteStatus();
double randuv(double u, double v);
QColor COLOR(const char *color_string);
QColor COLOR(unsigned int red, unsigned int green, unsigned int blue);

void wait(float duration);
void abort();


int textWidth(char op);
int textWidth(std::string text);
int textHeight();
int textDescent();

bool checkEvent(XEvent &event);
bool mouseDragEvent(XEvent &event);
bool mouseButtonPressEvent(XEvent &event);
bool mouseButtonReleaseEvent(XEvent &event);
bool keyPressEvent(XEvent &event);
void nextEvent(XEvent &event);
void echoKey(XEvent &event, Color clr);

char charFromEvent(XEvent &event);
int getClick();

void drawPoint(XPoint point, Color point_color, int function=GXcopy);
void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill=true, unsigned int line_width=2, int line_style=1, int cap_style=1, int join_style=1, int fill_rule=1, int function=1);
void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width);
void drawText(float x, float y, QString text, QColor clr, double angle=0.00);
void drawText(QPointF position, QString message, QColor clr, double angle=0.00);
void repaint();
void drawCircle(XPoint centre, int radius, Color fill_color, bool fill=true, unsigned int line_width=2, int line_style=1, int cap_style=1, int join_style=1, int function=1);
void initCanvas(const char window_title[]="Simplecpp Canvas",const unsigned width=800, const unsigned height=600);
void drawEllipse(XPoint centre, int width, int height, Color fill_color, bool fill=true, unsigned int line_width=2, int line_style=1, int cap_style=1, int join_style=1,  int function=1);
}
#endif
