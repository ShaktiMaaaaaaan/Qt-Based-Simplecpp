#ifndef _TURTLESIM_INCLUDED
#define _TURTLESIM_INCLUDED

#ifndef PI
#define PI 3.14159265358979323846
#endif

#include<simplecpp.h>
#include <turtle.h>

namespace simplecpp{
void turtleSim(const char* name="Turtle Simulator", int w=800, int h=600);
void closeTurtleSim();
void resetTurtle();

double sine(double x);
double cosine(double x);
double tangent(double x);
double arcsine(double x);
double arccosine(double x);
double arctangent(double x);
double arctangent2(double y, double x);
// void wait(unsigned long mSec);

void left(double dist);
void right(double dist);
void forward(double dist);
void left(int dist);
void right(int dist);
void forward(int dist);
void penDown(bool state=true);
void penUp(bool state=true);
void hide(bool state=true);
}
#endif
