#include <canvas.h>
#include <turtle.h>
#include <cstring>
#include <cstdlib>
#include <xevent.h>
#include <bits/stdc++.h>
#include <commondefs.h>
#include <line.h>
#include <QPixmap>
#include <simplecpp.h>
#include <QRandomGenerator>
#include <QFile>
#include <QFont>
#include <sprite.h>
#include <QString>
#include <QFontMetrics>
#include <QtCore>
#include <QEvent>
#include <QEventLoop>
#include <QMouseEvent>
#include <QtGui>
#include <QApplication>
#include <QEvent>
#include <QMouseEvent>

namespace simplecpp{

// C++ standard guarantess the order of initialization of static variables in the same file.
// They are initialized in the order they are declared.
// Refer to "Ordered Dynamic Initialization" in https://en.cppreference.com/w/cpp/language/initialization
// Following order is signicant as Qt application must be created before initializing any GUI classes
static int argc = 1;
static char *appName = "Simplecpp";
static QGuiApplication theApp(argc, &appName);
static Canvas theCanvas;
//static Turtle theSystemTurtleObj;

struct LtSprite
{
    bool operator()(const Sprite* s1, const Sprite* s2) const {
        return s1->getZIndex() < s2->getZIndex();
        //    return s1 < s2;
    }
};

std::multiset<Sprite *, LtSprite> spriteSet;
bool globalRepaintFlag = true;
QPixmap Bg(500, 500);
QPixmap tmp(500, 500);
QPixmap *curr=NULL;
QFont font;
QFontMetrics fm(font);
bool flag= false;

static QRect calculateCanvasSize(const unsigned w, const unsigned h) {
    auto rect = theApp.primaryScreen()->availableGeometry();
    auto topLeft = rect.topLeft();
    //auto sz = rect.size() * (2.0 / 3.0);
    auto sz = QPoint(w, h);
    return QRect(topLeft, sz);
}

void initCanvas(const char name[], const unsigned width, const unsigned height){

    auto screenSize=QSize(width, height);
    simplecpp::Bg=simplecpp::Bg.scaled(screenSize);
    simplecpp::tmp=simplecpp::tmp.scaled(screenSize);
    simplecpp::Bg.fill(QColor("white"));
    simplecpp::tmp.fill(QColor("white"));
    curr=&tmp;
    font.setFamily("Arial");
    font.setPointSize(12);
    font.setWeight(QFont::Bold);



    if (!font.exactMatch()) {
        font = QFont("fixed");
    }
    if (!font.exactMatch()) {
        qDebug() << "Cannot load font. You will not be able to use Text.";
    }

    theCanvas.initCanvas(name, width, height);

}

void closeCanvas() {
    spriteSet.clear();    // Delete all elements from set
    Bg = QPixmap();
    tmp = QPixmap();
    curr = NULL;
    font = QFont();
    fm = QFontMetrics(font);

}

double randuv(double u, double v) {
    return u + (v - u) * QRandomGenerator::global()->generateDouble() / (1.0 + RAND_MAX);
}

void abort() {
    std::abort();
}

QColor COLOR(const char *color_string) {
    return QColor(color_string);
}

QColor COLOR(unsigned int red, unsigned int green, unsigned int blue) {
    return QColor(red, green, blue);
}

void wait(float duration){
    QThread::usleep((int)(duration * 1000000));
}

int canvas_width() {
    return theCanvas.width();
}

int canvas_height() {
    return theCanvas.height();
}

void addSprite(Sprite *t){
    if(t){
        spriteSet.insert(t);
    }
}


void repaint() {

    // theCanvas.repaint();

    if(!curr){
        std::cout << "Repaint: You must first call initCanvas before "<<
                     "using any graphics features.\n";
        exit(1);
    }

    if(globalRepaintFlag){

        flag=true;
        QPixmap *temp=curr;
        tmp=Bg;
        curr=&tmp;
        for(auto iter = spriteSet.begin(); iter != spriteSet.end(); iter ++){
            (*iter)->paint();
        }

        theCanvas.repaint();
        curr=temp;
        flag=false;
    }
}

void removeSprite(Sprite *t){

    if(t){
        for(auto iter = spriteSet.begin(); iter != spriteSet.end(); iter ++){
            if((*iter) == t){
                spriteSet.erase(iter);
                break;
            }
        }
    }
    repaint();
}

void c_imprint(Sprite* s) {

    flag = true;
    QPixmap *temp;
    temp=curr;
    curr=&Bg;
    s->paint(nullptr);
    curr=temp;
    flag = false;
}

void imprintLine(short x1, short y1, short x2, short y2, QColor line_color, int line_width){

    QPixmap *temp;
    temp=curr;
    curr=&Bg;

    QPen pen(line_color);
    pen.setWidth(line_width);

    QPainter painter(curr);
    painter.setPen(pen);

    painter.drawLine(x1, y1, x2, y2);

    curr=temp;


    if(!simplecpp::flag){
        repaint();
    }
}

void spriteStatus(){
    std::cout<<"Count: "<<spriteSet.size()<<std::endl;
    for(auto iter = spriteSet.begin(); iter != spriteSet.end(); iter ++){
        std::cout<<"["<<"]-->"<<(*iter)<<std::endl;
    }
}




int textWidth(char op) {
    QString s(op);
    return fm.boundingRect(s).width()*3;
}

int textWidth(std::string text) {
    QString qText = QString::fromStdString(text);
    return fm.boundingRect(qText).width()*3;
}

int textHeight() {
    return fm.height();
}

int textDescent() {
    return fm.descent();
}

void beginFrame(){
    globalRepaintFlag = false;
}

void endFrame(){
    globalRepaintFlag = true;
    repaint();
}

int getClick() {
    return theCanvas.getClick();
}

char charFromEvent(XEvent &event){
    return theCanvas.charFromEvent(event);
}

void nextEvent(XEvent &event){
    theCanvas.nextEvent(event);
}

bool checkEvent(XEvent &event){
    return theCanvas.checkEvent(event);
}

bool mouseDragEvent(XEvent &event){
    return theCanvas.mouseDragEvent(event);
}
bool mouseButtonPressEvent(XEvent &event){
    return theCanvas.mouseButtonPressEvent(event);
}
bool mouseButtonReleaseEvent(XEvent &event){
    return theCanvas.mouseButtonReleaseEvent(event);
}
bool keyPressEvent(XEvent &event){
    return theCanvas.keyPressEvent(event);
}
void echoKey(XEvent &event, Color clr){
    theCanvas.echoKey(event, clr);
}

void drawText(float x, float y, QString text, QColor clr, double angle){
    theCanvas.drawText(x, y, text, clr, angle);
}
void drawText(QPointF position, QString message, QColor clr, double angle){
    theCanvas.drawText(position, message, clr, angle);
}

void drawPoint(XPoint point, Color point_color, int function){
    theCanvas.drawPoint(point, point_color, function);
}


void drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int fill_rule, int function){
    theCanvas.drawPolygon(points, npoints, fill_color, fill, line_width, line_style, cap_style, join_style, fill_rule, function);
}
void drawLine(XPoint start, XPoint end, Color line_color, unsigned int line_width){
    theCanvas.drawLine(start, end, line_color, line_width);
}
void drawEllipse(XPoint centre, int width, int height, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int function){
    theCanvas.drawEllipse(centre, width, height, fill_color, fill, line_width, line_style, cap_style, join_style, function);
}
void drawCircle(XPoint centre, int radius, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int function){
    theCanvas.drawCircle(centre, radius, fill_color, fill, line_width, line_style, cap_style, join_style, function);
}
}   // End of simplecpp namespace





int Canvas::getClick() {
    QPoint point;
    QEventLoop eventLoop;
    connect(this, &Canvas::clicked, &eventLoop, &QEventLoop::quit);
    connect(this, &Canvas::clicked, this, [&point, this](){
        point = this->mapFromGlobal(QCursor::pos());
    });

    eventLoop.exec();
    return point.x() * 65536 + point.y();
}


void Canvas::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        devent.type = QEvent::MouseButtonPress;
        QPoint pos = mapFromGlobal(QCursor::pos());
        devent.xbutton.x = pos.x();
        devent.xbutton.y = pos.y();
        emit clicked();
        emit mouseButtonPressed();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {  // Check whether the left mouse button is pressed
        devent.type = QEvent::MouseMove;
        QPoint pos = mapFromGlobal(QCursor::pos());
        devent.xmotion.x = pos.x();
        devent.xmotion.y = pos.y();
        emit mouseDragged();
    }
}


void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        devent.type =QEvent::MouseButtonRelease;
        emit mouseButtonReleased();
    }
}



void Canvas::keyPressEvent(QKeyEvent *event) {

devent.type = QEvent::KeyPress;

// Check if Shift key is pressed
//bool shiftPressed = event->modifiers() & Qt::ShiftModifier;
// Check if Shift key is pressed
bool shiftPressed = (event->key() == Qt::Key_Shift);


// Check if Caps Lock is enabled
bool capsLockEnabled = (event->modifiers() & Qt::KeypadModifier) && !shiftPressed;

// Get the pressed key as a character
QChar pressedKey = event->text().at(0);

// Convert to uppercase if Shift key is pressed and not Caps Lock
if (shiftPressed && !capsLockEnabled) {
    pressedKey = pressedKey.toUpper();
}

// Convert to lowercase if Caps Lock is enabled and the key is a letter
if (capsLockEnabled && pressedKey.isLetter()) {
    pressedKey = pressedKey.toLower();
}

devent.xkey.key = pressedKey.unicode();

QPoint pos = mapFromGlobal(QCursor::pos());
devent.xkey.x = pos.x();
devent.xkey.y = pos.y();
emit keyPressed(devent.xkey.key);
}



void Canvas::nextEvent(simplecpp::XEvent &event) {

    QEventLoop loop;

    connect(this, &Canvas::clicked, &loop, [&]() {
        loop.exit();
    });

    connect(this, &Canvas::mouseDragged, &loop, [&]() {
        loop.exit();
    });
    connect(this, &Canvas::mouseButtonPressed, &loop, [&]() {
        loop.exit();
    });

    connect(this, &Canvas::mouseButtonReleased, &loop, [&]() {
        loop.exit();
    });
    connect(this, &Canvas::keyPressed, &loop, [&](int k) {
        loop.exit();
    });


    loop.exec();

    event=devent;
}



bool Canvas::checkEvent(simplecpp::XEvent &event) {

    event=devent;
    return  (event.type == QEvent::KeyPress ||
             event.type == QEvent::MouseButtonPress ||
             event.type == QEvent::MouseButtonRelease);
}



bool Canvas::mouseDragEvent(simplecpp::XEvent &event)
{
    return event.type == QEvent::MouseMove;
}

bool Canvas::mouseButtonPressEvent(simplecpp::XEvent &event)
{
    return event.type == QEvent::MouseButtonPress;
}

bool Canvas::mouseButtonReleaseEvent(simplecpp::XEvent &event)
{
    return event.type == QEvent::MouseButtonRelease;
}

bool Canvas::keyPressEvent(simplecpp::XEvent &event) {
    return event.type == QEvent::KeyPress;
}


char Canvas::charFromEvent(simplecpp::XEvent &event) {
    if (event.type == QEvent::KeyPress) {
        return event.xkey.key;
    }
    return '\0';
}

void Canvas::echoKey(simplecpp::XEvent &event, Color clr){

    char c = charFromEvent(event);
    QString character = QString::fromLatin1(&c, 1); // convert char to QString

    // calculate text width
    QFontMetrics fm(simplecpp::font);
    int tw = fm.horizontalAdvance(character);

    // draw text at position
    QPointF position(event.xkey.x + tw/2, event.xkey.y);
    drawText(position, character, clr);

    // move pointer
    QCursor::setPos(mapToGlobal(QPoint(event.xkey.x+tw, event.xkey.y)));
}




void Canvas::repaint() {


    auto fillRegion = QRegion(0, 0, width(), height());

    offScreenBuffer.beginPaint(fillRegion);
    QPaintDevice *device = offScreenBuffer.paintDevice();
    Q_ASSERT(device != nullptr);
    QPainter painter(device);

    painter.drawPixmap(fillRegion.boundingRect(), simplecpp::tmp);
    painter.end();
    offScreenBuffer.endPaint();



    // Update the window
    offScreenBuffer.flush(fillRegion.boundingRect());


    simplecpp::theApp.processEvents();


}


Canvas::Canvas():offScreenBuffer(this) {    
}


void Canvas::initCanvas(const char name[], const unsigned w, const unsigned h){
    auto rectSz = simplecpp::calculateCanvasSize(w, h);

    // Set window size including top left corner position, height, and width
    setGeometry(rectSz);
    setTitle(name);
    // Set screen buffer size to window's size
    // auto screenSize = rectSz.size();


    auto screenSize = QSize(width(), height());

    offScreenBuffer.resize(screenSize);

    // Fill the screen buffer with a background colour
    auto brush = QGuiApplication::palette().brush(QPalette::Window);
    auto fillRegion = QRegion(0, 0, screenSize.width(), screenSize.height());

    offScreenBuffer.beginPaint(fillRegion);
    QPaintDevice *device = offScreenBuffer.paintDevice();
    Q_ASSERT(device != nullptr);
    QPainter painter(device);
    painter.fillRect(fillRegion.boundingRect(), brush);
    painter.end();
    offScreenBuffer.endPaint();

    // start

    // end
    // Show the window

    show();


    // Wait till window is exposed
    while(!isExposed())
    {
        QGuiApplication::processEvents();
        QThread::msleep(100);
    }
}

Canvas::~Canvas() {
    
}


void Canvas::exposeEvent(QExposeEvent *e)
{
    if (isExposed())
        render(e->region());
}

void Canvas::render(const QRegion &dirtyRegion) {
    if (!isExposed())
        return;

    // Flush screen buffer to window to update dirty region
    offScreenBuffer.flush(dirtyRegion.boundingRect());
}





void Canvas::drawPoint(XPoint point, Color point_color, int function){

    auto fillRegion = QRegion(0, 0, width(), height());

    // Get resources
    QPen pen(point_color);
    QPainter painter(simplecpp::curr);
    painter.setPen(pen);

    if (function == GXcopy) {
        painter.setCompositionMode(QPainter::CompositionMode_Source);
    } else {
        // Default composition mode
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    }

    painter.drawPoint(point.x(), point.y());

    painter.end();

    simplecpp::theApp.processEvents();

    if(!simplecpp::flag){
        repaint();
    }

}
void Canvas::drawLine(XPoint start, XPoint end, Color lineColor, unsigned int lineWidth){
    auto fillRegion = QRegion(0, 0, width(), height());

    // Get resources
    QPen pen(lineColor);
    pen.setWidth(lineWidth);

    QPainter painter(simplecpp::curr);
    painter.setPen(pen);

    painter.drawLine(start, end);

    painter.end();


    simplecpp::theApp.processEvents();

    if(!simplecpp::flag){
        repaint();
    }

}


void Canvas::drawPolygon(XPoint *points, int npoints, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int fill_rule, int function){


    auto fillRegion = QRegion(0, 0, width(), height());

    QPainter painter(simplecpp::curr);

    if(fill){
        QPen pen(fill_color);
        pen.setWidth(line_width);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(fill_color);
        painter.setPen(pen);
    }
    else{
        QPen pen(Qt::black);
        pen.setWidth(line_width);
        painter.setPen(pen);
    }

    // Do the drawing
    painter.drawPolygon(points, npoints);

    painter.end();


    simplecpp::theApp.processEvents();

    if(!simplecpp::flag){
        repaint();
    }

}


void Canvas::drawEllipse(XPoint centre, int rx, int ry, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int function){

    auto fillRegion = QRegion(0, 0, width(), height());


    QPainter painter(simplecpp::curr);

    if(fill){
        QPen pen(fill_color);
        pen.setWidth(line_width);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(fill_color);
        painter.setPen(pen);
    }
    else{
        QPen pen(Qt::black);
        pen.setWidth(line_width);
        painter.setPen(pen);
    }

    // Do the drawing
    painter.drawEllipse(centre, rx, ry);

    painter.end();

    simplecpp::theApp.processEvents();

    if(!simplecpp::flag){
        repaint();
    }
}


void Canvas::drawCircle(XPoint centre, int radius, Color fill_color, bool fill, unsigned int line_width, int line_style, int cap_style, int join_style, int function){


    auto fillRegion = QRegion(0, 0, width(), height());

    QPainter painter(simplecpp::curr);

    if(fill){
        QPen pen(fill_color);
        pen.setWidth(line_width);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(fill_color);
        painter.setPen(pen);
    }
    else{
        QPen pen(Qt::black);
        pen.setWidth(line_width);
        painter.setPen(pen);
    }

    // Do the drawing
    painter.drawEllipse(centre, radius, radius);

    painter.end();

    simplecpp::theApp.processEvents();

    if(!simplecpp::flag){
        repaint();
    }
}

void Canvas::drawText(float x, float y, QString text, QColor clr, double angle){
    drawText(QPointF(x, y), text, clr, angle);
}

void Canvas::drawText(QPointF position, QString message, QColor clr, double angle){

    auto fillRegion = QRegion(0, 0, width(), height());

    // Get resources


    QPainter painter(simplecpp::curr);
    painter.setPen(clr);
    painter.setFont(simplecpp::font);

    // Rotate the painter around the text position
    painter.save();
    painter.translate(position);
    painter.rotate(angle);

    painter.drawText(position.x() - painter.fontMetrics().boundingRect(message).width() / 2,
                     position.y() + painter.fontMetrics().ascent() / 2,
                     message);
    // Restore the painter's original state
    painter.restore();

    painter.end();

    simplecpp::theApp.processEvents();

    if(!simplecpp::flag){
        repaint();
    }
}
