#include <canvas.h>
#include <turtleSim.h>
#include <iostream>
#include <QThread>
#include <canvas.h>
#include <sprite.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <simplecpp.h>
#include <turtle.h>

namespace simplecpp{

Turtle *theSystemTurtleObj;

void turtleSim(const char* name, int w, int h){

    initCanvas(name,w,h);
    theSystemTurtleObj = new Turtle;
}

void check(const char* msg){
    if(!theSystemTurtleObj){
        std::cout << "You need to call turtleSim before calling "<<msg<<".\n";
        exit(1);
    }
}

void closeTurtleSim(){
    closeCanvas();
}

void resetTurtle(){
    theSystemTurtleObj->Sprite::reset(canvas_width()/2,canvas_height()/2);
}

void hide(bool state){
    if(state) theSystemTurtleObj->hide();
    else theSystemTurtleObj->show();

}

void penDown(bool state){check("penDown");theSystemTurtleObj->penDown(state);}
void penUp(bool state){check("penUp");theSystemTurtleObj->penDown(!state);}
void left(double dist){check("left"); theSystemTurtleObj->left(dist);}
void left(int dist){ check("left"); left(float(dist));}
void right(double dist){check("right"); theSystemTurtleObj->right(dist);}
void right(int dist){ check("right");    right(float(dist));}
void forward(double dist){ check("forward");  theSystemTurtleObj->forward(dist);}
void forward(int dist){check("forward");forward(float(dist));}

double sine(double x){return sin(PI*x/180);}
double cosine(double x){return cos(PI*x/180);}
double tangent(double x){return tan(PI*x/180);}
double arcsine(double x){return asin(x)*180/PI;}
double arccosine(double x){return acos(x)*180/PI;}
double arctangent(double x){return atan(x)*180/PI;}
double arctangent2(double y, double x){return atan2(y,x)*180/PI;}
// void wait(unsigned long mSec) { QThread::sleep(mSec);}
}
