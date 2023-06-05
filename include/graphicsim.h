#ifndef GRAPHICSIM_H
#define GRAPHICSIM_H

#include <canvas.h>
#include <bits/stdc++.h>

namespace simplecpp{

#include <unistd.h>



#define MouseCode(event) ((event).button())
#define KeyCode(event) ((event).key())

#define MouseCode_LEFT Qt::LeftButton
#define MouseCode_RIGHT Qt::RightButton
#define MouseCode_CENTER Qt::MiddleButton
#define MouseCode_SCROLLDN Qt::ExtraButton4
#define MouseCode_SCROLLUP Qt::ExtraButton5

#define MousePosX(event) ((event).x())
#define MousePosY(event) ((event).y())

#define MouseTime(event) ((event).timestamp())
#define KeyTime(event) ((event).timestamp())




}
#endif // GRAPHICSIM_H
