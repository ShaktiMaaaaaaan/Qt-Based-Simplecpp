#ifndef _TEXT_INCLUDED_
#define _TEXT_INCLUDED_

#include <sprite.h>
#include <qfont.h>

namespace simplecpp{
class Text : public Sprite{
protected:
    std::string message;
    double _angle_=0.0;
    double font_size=12;
    std::string font_="Arial";
    QFont::Weight w1 = QFont::Normal;
public:
    Text(double cx, double cy, std::string m, Composite* owner=NULL);
    Text(double cx, double cy, double n, Composite* owner=NULL);
    Text(Composite* owner=NULL);
    //  void init(double cx, double cy, string m);
    void reset(double cx, double cy, std::string m);
    //  void init(double cx, double cy, double m);
    void reset(double cx, double cy, double m);
    void setMessage(std::string s);
    void paint(Pose* p=NULL);
    void rotate(double angle) override;
    void scale(double s);
    void setFont(const std::string& family, int size, QFont::Weight weight);
    int getFontSize();
    std::string getFontFamily();
};
}
#endif
