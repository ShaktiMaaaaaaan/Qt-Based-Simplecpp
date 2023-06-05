#ifndef XEVENT_H
#define XEVENT_H



namespace simplecpp{
class XEvent{
public:

    int type;

    struct xkey{
        int x;
        int y;
        char key;
    }xkey;

    struct xbutton{
        int x;
        int y;
    }xbutton;

    struct xmotion{
        int x;
        int y;
    }xmotion;

    XEvent();

};
}

#endif // XEVENT_H

