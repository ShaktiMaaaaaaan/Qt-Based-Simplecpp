#include <sstream>
#include<text.h>
#include <canvas.cpp>

namespace simplecpp{
Text::Text(double cx, double cy, std::string m, Composite* owner)
    : Sprite(cx, cy, owner){
    reset(cx, cy, m);
}

Text::Text(double cx, double cy, double m, Composite* owner)
    : Sprite(cx, cy, owner){
    reset(cx, cy, m);
}

Text::Text(Composite* owner)
    : Sprite(owner){
    reset(0,0,"");
}

// void Text::init(double cx, double cy, string m){
//   reset(cx,cy,m);
// }
// void Text::init(double cx, double cy, double m){
//   reset(cx,cy,m);
// }

void Text::reset(double cx, double cy, std::string m){
    pose = Pose(cx,cy);
    message = m;
    show();
}

void Text::reset(double cx, double cy, double m){
    std::ostringstream message;
    message << m;
    reset(cx, cy, message.str());
}

void Text::paint(Pose *p){
    if(visible){
        XPoint xp = (p ? Pose(*p,pose) : pose).prod(Position(0,0));
        QPointF position(xp.x(), xp.y());
        QString messageQString = QString::fromStdString(message);

        drawText(position, messageQString, color, _angle_);
    }
}

void Text::setMessage(std::string s){
    message = s;
    repaint();
}



void Text::rotate(double angle){
    _angle_ +=angle;
    Sprite::rotate(angle);
}

void Text::scale(double factor) {
    Sprite::scale(factor);
    font_size *=factor;
    setFont(font_, font_size, w1);
    Sprite::scale(factor);
  //  repaint();
}

void Text::setFont(const std::string& family, int size, QFont::Weight weight) {
    font_ = family;
    font_size = size;
    w1=weight;
    font.setFamily(QString::fromStdString(family));
    font.setPointSize(size);
    font.setWeight(weight);
}

int Text::getFontSize() {
    return font_size;
}
std::string Text::getFontFamily(){
    return font_;
}
}
