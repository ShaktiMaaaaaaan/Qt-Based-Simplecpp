#include <simplecpp.h>
#include<bits/stdc++.h>
#include <text.h>
#include <sprite.h>
#include <qfontdatabase.h>

#include<bits/stdc++.h>

int main(){
  initCanvas("Pentagon and Star", 500, 500);
  double pentaV[5][2], starV[5][2];

  for(int i=0; i<5; i++){
    pentaV[i][0] = 100 * cos(2*PI/5*i);
    pentaV[i][1] = 100 * sin(2*PI/5*i);
    starV[i][0] = 100 * cos(4*PI/5*i);
    starV[i][1] = 100 * sin(4*PI/5*i);
  }

  Polygon penta(200,200,pentaV,5);
  Polygon star(200,400,starV,5);

  for(int i=0; i<100; i++){
    penta.left(5);
    star.right(5);
    wait(0.1);
  }

  wait(5);
}

/*
int gridsep=10,xinit=30,yinit=20,npts=50;
int canvS=gridsep*npts;
int len=0,bre=0;
/*
void backG()
{
    double l=2*gridsep;
    //dark theme
    Rectangle R(canvS/2,canvS/2,canvS,canvS);
    R.setFill(true);
    R.setColor(Qt::blue);
    R.imprint();
}
void grid()
{
    Rectangle r1(gridsep,canvS/2,2*gridsep,canvS);
    Rectangle r2(canvS-gridsep,canvS/2,2*gridsep,canvS);
    r1.setFill(true);
    r2.setFill(true);
    r1.setColor(COLOR(50,70,100));
    r2.setColor(COLOR(50,70,100));
    r1.imprint();
    r2.imprint();
    Rectangle r3(canvS/2,gridsep,canvS,2*gridsep);
    Rectangle r4(canvS/2,canvS-gridsep,canvS,2*gridsep);
    r3.setFill(true);
    r4.setFill(true);
    r3.setColor(COLOR(50,70,100));
    r4.setColor(COLOR(50,70,100));
    r3.imprint();
    r4.imprint();
    for(int i=5*gridsep;i<=canvS-2*gridsep;i=i+gridsep)
    {
        Line l1(2*gridsep,i,canvS-2*gridsep,i);
        l1.imprint();
    }
    for(int i=5*gridsep;i<=canvS-2*gridsep;i=i+gridsep)
    {
        Line l1(i,2*gridsep,i,canvS-2*gridsep);
        l1.imprint();
    }
}
Circle foodspawner()
{
    //seeding
    int x=rand()%(canvS-4*gridsep)+2*gridsep;
    int y=rand()%(canvS-4*gridsep)+2*gridsep;
    Circle c(x,y,gridsep*0.5);
    c.setFill(true);
    c.setColor(COLOR("red"));
    return c;
}
struct Snake
{
    vector<Circle> body;
    int length;
    int headindex; //Current head index
    char dir; //direction
    Snake(int l)
    {
        length=l;
        //body=new Circle[l];
        headindex=0;
        for(int i=0;i<length;i++){
            Circle c((xinit+0.5+i)*gridsep, (yinit+0.5)*gridsep, gridsep*0.5);
            body.push_back(c);
            body[i].setFill(true);
            body[i].setColor(COLOR(0,0,255));
        }
        body[headindex].setFill(true);

        dir='a';
    }
    int xsnake()
    {
        return body[headindex].getX();
    }
    int ysnake()
    {
        return body[headindex].getY();
    }
    char rev(char direction)
    {
        if(direction=='a') return 'd';
        if(direction=='d') return 'a';
        if(direction=='w') return 's';
        if(direction=='s') return 'w';
    }
    void move()
    {
        if(body[headindex].getX()>canvS-3*gridsep || body[headindex].getY()>canvS-3*gridsep || body[headindex].getX()<3*gridsep || body[headindex].getY()<3*gridsep) dir=rev(dir);
        move(dir);
    }
    void move(char command)
    {
        if(body[headindex].getX()<canvS || body[headindex].getY()<canvS || body[headindex].getX()>0 || body[headindex].getY()>0){

        if(command != 'w' && command != 'a' && command != 's' && command != 'd')
            command=dir;

        int newhead=(headindex+length-1)%length;
        body[newhead]=body[headindex];
        headindex=newhead;

        if(command == 'a')
        {
         body[headindex].move(-gridsep,0);
        }
        if(command == 'w'){body[headindex].move(0,-gridsep);}
        if(command == 'd'){body[headindex].move(gridsep,0); }
        if(command == 's') body[headindex].move(0,gridsep);

        dir=command;
        }
    else dir=rev(dir);
    }

};
/*Increase length function*/
/*void increaseLength(Snake &s)
{
    Circle c((xinit+0.5+s.length)*gridsep, (yinit+0.5)*gridsep, gridsep*0.5);
    s.body.push_back(c);
    s.body[s.length].setFill(true);
    s.body[s.length].setColor(COLOR("green"));
    s.length=s.length+1;
}
Rectangle obstacleSpawner()
{
    int x=rand()%(canvS-4*gridsep)+2*gridsep;
    int y=rand()%(canvS-4*gridsep)+2*gridsep;
     len=rand()%5*gridsep + 2*gridsep;
     bre=rand()%2*gridsep + 2*gridsep;
    Rectangle r(x,y,len,bre);
    r.setFill(true);
    r.setColor(COLOR(25,25,25));
    return r;
}
int main()
{

    int score = 0;
    int noObs=0;
    double speed=0.1;
    initCanvas("Snake",gridsep*npts,gridsep*npts);
    backG();
    //grid();
    Snake s(4);
    std::srand(time(NULL));
    Circle c=foodspawner();
    vector<Rectangle> r;
    vector<int> lenR;
    vector<int> breR;
    while(1)
    {
        //give input
        XEvent event;
        if(checkEvent(event))
        {
            if(keyPressEvent(event))
            {
                char c=charFromEvent(event);
                s.move(c);

            }
        }
        else s.move();

        //eat the food
        if(abs((s.xsnake()-c.getX()))<gridsep && abs((s.ysnake()-c.getY()))<gridsep)
        {
                score++;
                Text t(4*gridsep,4*gridsep,score);
                t.imprint();
                c.setColor(COLOR(255,255,255));
                c.reset(0,0,0);
                increaseLength(s);
                if(noObs<10)
                {
                    r.push_back(obstacleSpawner());r[0].imprint();
                    lenR.push_back(len);
                    breR.push_back(bre);
                    noObs++;
                }
                Circle c1=foodspawner();
                for(int i=0;i<noObs;i++)
                {
                    if(abs(r[i].getX()-c1.getX())<lenR[i] && abs(r[i].getY()-c1.getY())<breR[i])
                    c1=foodspawner();
                }
                c=c1;
                speed=speed-0.005;
        }

        //DON'T CROSS THE OBSTACLES

        bool crossedObs=false;
        for(int ii=0;ii<noObs;ii++){
        if( abs((s.xsnake()-r[ii].getX()))<lenR[ii]/2.0 && abs((s.ysnake()-r[ii].getY()))<breR[ii]/2.0) {crossedObs=true;break;}}
        if(crossedObs) break;


        //DON'T CROSS YOURSELF
        bool crossedItself=false;
        for(int ii=s.headindex+2;ii<s.length;ii++)
        {
            if(abs((s.xsnake()-s.body[ii].getX()))==0 && abs((s.ysnake()-s.body[ii].getY()))==0) {crossedItself=true;wait(0.05);break;}
        }
        if(crossedItself) break;
        wait(speed);
    }
    return 0;
}*/
/*
int main(){
//Write your code here
initCanvas();
    Text t(50, 50, "Wel");


    t.setFont("OCR A Extended", 10, QFont::Normal);
    t.rotate(45);
    t.scale(4);
    drawPoint(QPoint(300, 300), Qt::red);
    wait(50);

}



 #include <qfontdatabase.h>
int main(){

    QFontDatabase fontDB;
    QStringList fontFamilies = fontDB.families();
    qDebug() << fontFamilies;



    return 0;
}

    /*
#include <text.h>
#include<iostream>
#include <turtleSim.h>
#include <bits/stdc++.h>
#include <turtle.h>
#include <sprite.h>
#include <polygon.h>
#include <canvas.h>
#include<composite.h>
#include <rectangle.h>
#include<ellipse.h>
#include<polygon.h>
#include<text.h>
#include<circle.h>
#include <commondefs.h>
#include <bits/stdc++.h>

using namespace simplecpp;

void tree(int height, float length, float angle, float shrinkage)
  // precondition: turtle is at root, pointing up.
  // post condition: same
{
  if(height == 0) return;
                         // 1.  draw the left branch
  left(angle/2);
  forward(length);
                        // 2.  draw the left (sub)tree.
  right(angle/2);
  tree(height-1, length*shrinkage, angle*shrinkage, shrinkage);

                        // 3.  go back to the root
  left(angle/2);
  forward(-length);
                        // 4.  draw the right branch
  right(angle);
  forward(length);
                        // 5.  draw right (sub)tree.
  left(angle/2);
  tree(height-1,length*shrinkage, angle*shrinkage, shrinkage);
                        // 6.  go back to root
  right(angle/2);
  forward(-length);
                        // 7.  ensure post condition
  left(angle/2);
}

const int gridsep = 20, xinit = 30, yinit = 20, length = 10, npts = 40;

struct Snake{
  Circle body[length];
  int headindex;   // which body element is the head of the snake
  int dx,dy;       // current direction of motion.
  Snake(){         // head at (xinit,yinit) in the coarse grid.
    headindex = 0;
    for(int i=0; i<length; i++)
      body[i].reset((xinit+0.5+i)*gridsep, (yinit+0.5)*gridsep, gridsep*0.5);
    dx = -gridsep; dy = 0;
  }
  void move(char command){
                                  // find direction of motion.
    if(command == 'w')      { dx = -gridsep; dy = 0;}
    else if (command == 'n'){ dx = 0; dy = -gridsep;}
    else if (command == 'e'){ dx = gridsep; dy = 0;}
    else if (command == 's'){ dx = 0; dy = gridsep;}
                           // else old direction, do not change dx, dy.
    int tailindex = (headindex +length - 1) % length;  // current tail
    body[tailindex] = body[headindex];  // current tail now on top of head
    body[tailindex].move(dx, dy);
    headindex = tailindex;              // current tail element becomes head
  }
};


using namespace simplecpp;


main_program{
  initCanvas("Projectile motion", 500,500);

  int start = getClick();

  Circle sp(start /65536, start % 65536, 5);
  sp.penDown();

  double vx=1,vy=-5;

  repeat(100){
    sp.move(vx,vy);
    vy += .1;
    wait(0.1);
  }

  getClick();
}
/*
int main(){
  initCanvas("Draw using the mouse", 800,500);
  const char escapekey = '\33';
  XEvent event;
  int x= getClick();
  std::cout<<x;

  wait(20);
  /*short lastx=0, lasty=0;
  while(1){
    nextEvent(event);
    if(mouseButtonPressEvent(event)){
      lastx = event.xbutton.x; lasty = event.xbutton.y;
    }
    if(mouseDragEvent(event)){
      imprintLine(lastx, lasty, event.xmotion.x, event.xmotion.y);
      lastx = event.xmotion.x; lasty = event.xmotion.y;
    }
    if(keyPressEvent(event)){
      if(charFromEvent(event) == escapekey) break;
    }
  }
  */



/*
int main(){
    initCanvas();

    Circle c(500, 500, 180);

    c.setFill(true, true);
    Circle d(500, 500, 140);
    d.setColor(Qt::yellow, true);
    d.setFill(true, true);
    Circle e(500, 500, 100);
    e.setFill(true, true);
    Circle f(500, 500, 60);
    f.setColor(Qt::yellow, true);
    f.setFill(true, true);
    Circle g(500, 500, 20);
    g.setColor(Qt::red, true);
    g.setFill(true, true);
    wait(20);

}


/*
int main(){
  initCanvas("Snake", gridsep*npts, gridsep*npts);
  Snake s;
  while(true){
    XEvent event;
    if(checkEvent(event) && keyPressEvent(event)){
    char c = charFromEvent(event);
    s.move(c);
    }
    else s.move('\0'); // NULL = continue to move in previous direction.
    wait(0.1);
  }
}

int main(){
  turtleSim();
  left(90);

  tree(5,120,120,0.68);

  wait(5);
}

int main(){
  initCanvas("Pentagon and Star");
  double pentaV[5][2], starV[5][2];

  for(int i=0; i<5; i++){
    pentaV[i][0] = 100 * cos(2*PI/5*i);
    pentaV[i][1] = 100 * sin(2*PI/5*i);
    starV[i][0] = 100 * cos(4*PI/5*i);
    starV[i][1] = 100 * sin(4*PI/5*i);
  }

  simplecpp::Polygon penta(200,200,pentaV,5);

  simplecpp::Polygon star(200,400,starV,5);

  for(int i=0; i<100; i++){
    penta.left(5);
    star.right(5);
    wait(0.1);
  }

  getClick();
}



int main(){


/*
    initCanvas();
    float bFx=150,bFy=100, bLx=400,bLy=100, bWidth=150,bHeight=50;
    simplecpp::Rectangle buttonF(bFx,bFy,bWidth, bHeight), buttonL(bLx,bLy,bWidth,bHeight);

    Text tF(bFx,bFy,"Forward"), tL(bLx,bLy,"Left Turn");
    Turtle t;

    repeat(100){
      int clickPos = getClick();
      int cx = clickPos/65536;
      int cy = clickPos % 65536;

      if(bFx-bWidth/2<= cx && cx<= bFx+bWidth/2 &&
         bFy-bHeight/2 <= cy && cy <= bFy+bHeight/2) t.forward(100);

      if(bLx-bWidth/2<= cx && cx<= bLx+bWidth/2 &&
         bLy-bHeight/2 <= cy && cy <= bLy+bHeight/2) t.left(10);
    }

    initCanvas("Draw using the mouse", 800,500);



    const char escapekey = 'x';
      XEvent event;
      short lastx=0, lasty=0;
      while(1){
        nextEvent(event);
        if(mouseButtonPressEvent(event)){
          lastx = event.xbutton.x; lasty = event.xbutton.y;
        }
        if(mouseDragEvent(event)){
          imprintLine(lastx, lasty, event.xmotion.x, event.xmotion.y);
          lastx = event.xmotion.x; lasty = event.xmotion.y;
        }
        if(keyPressEvent(event)){
          if(charFromEvent(event) == escapekey) break;

    }
      }



    initCanvas("Snake", gridsep*npts, gridsep*npts);

    XEvent event;
    nextEvent(event);
    std::cout<<event.xbutton.x<<" "<<event.xbutton.y;

    echoKey(event, Qt::green);
*/
  /*
    initCanvas("Snake", gridsep*npts, gridsep*npts);
    Snake s;
      while(true){
        XEvent event;

        if(checkEvent(event) && keyPressEvent(event)){
        char c = charFromEvent(event);
        s.move(c);
        }
        else s.move('\0'); // NULL = continue to move in previous direction.
        wait(0.1);
      }




/*
    Text t(50, 50, "Wel");

    QPoint p(500, 500);
    drawPoint(p, Qt::red);
    Circle r1(100, 100, 50);
/*
    int x=getClick();
    std::cout<<x;
    t.rotate(180);
    t.move(100, 100);


    r1.move(300, 300);



     QString s;
     s="Hello";
     //std::cout<<s;


     QPoint points[4] = {
        QPoint(10.0, 80.0),
        QPoint(20.0, 10.0),
        QPoint(80.0, 30.0),
        QPoint(90.0, 70.0)
    };

    drawPolygon(points, 4, Qt::green, true);
    // forward(100);

*/
  /*    Text t(50, 50, "Wel");

      QPoint p(500, 500);
      drawPoint(p, Qt::red);
      Circle r1(100, 100, 50);

      int x=getClick();
      std::cout<<x;
      t.rotate(180);
      t.move(100, 100);


      r1.move(300, 300);

    wait(20);
/*
    drawEllipse(QPoint(200, 200), 80, 60, Qt::green, true);


    drawCircle(QPoint(500, 500), 50, Qt::blue, true);

     //drawText(x/65536, x%65536, s, Qt::green);

     //drawText(500, 100, s, Qt::blue);
     wait(100);


    return 0;
}
*/

/*

int main(int, char **) {    


    turtleSim();


    left(90);
    tree(5,120,120,0.68);

/*
    //getClick();

    initCanvas("xyz", 300, 500);
    Turtle t;


    char command;
     turtleSim();


   repeat(100){
      std:: cin >> command;
       if (command == 'f') forward(100);
       else if (command == 'r') right(90);
       else if (command == 'l') left(90);
       else std::cout << "Not a proper command, " << command << std::endl;
     }



    turtleSim();
    wait(1);
    forward(100);
    wait(1);
    left(90);
    wait(1);
    forward(200);
    wait(1);
    right(90);
    wait(1);
    forward(100);


    //Turtle t;
   // forward(100);


   turtleSim();
   Turtle t1;



    //closeTurtleSim();


    //polygon

    unsigned nSteps {0};

     QPoint points[4] = {
        QPoint(10.0, 80.0),
        QPoint(20.0, 10.0),
        QPoint(80.0, 30.0),
        QPoint(90.0, 70.0)
    };

    drawPolygon(points, 4, Qt::green, true);
    // forward(100);
    wait(50);

   // drawEllipse(QPoint(200, 200), 80, 60, Qt::green, true);


   // drawCircle(QPoint(200, 200), 50, Qt::blue, true);



    std::cout << "Enter number of steps: ";
    std::cin >> nSteps;

    for(auto stepIdx {0u}; stepIdx < nSteps; stepIdx ++) {
        auto action = rand() % 5;

        switch (action)
        {
        case 0:
            left(90);            
            break;
        case 1:
            right(90);
            break;
        default:
            forward(20);
            break;
        }
        wait(50);   // Wait for 50 milliseconds
    }




    wait(50);
    return 0;
}




const double RADIUS = 50;
class Wheel : public Composite{
  Circle *rim;
  Line *spoke[10];
public:
  Wheel(double x, double y, Composite* owner=NULL) : Composite(x,y,owner){
    rim = new Circle(0,0,RADIUS,this);
    for(int i=0; i<10; i++){
      spoke[i] = new Line(0, 0, RADIUS*cos(i*PI/5), RADIUS*sin(i*PI/5), this);
    }
  }
};


*/
/*
int main(){
  turtleSim();
  int i = 1;
  repeat(10){
    forward(i*10); right(90);
    forward(i*10); right(90);    i = i + 1;
  }
  wait(5);
}

*/


/*
int main(){

    initCanvas();
    Turtle t1, t2, t3;
    t2.left(120);
    t3.left(240);
    repeat(8){
        t1.forward(100);
        t2.forward(100);
        t3.forward(100);
        t1.left(360/8);
        t2.left(360/8);
        t3.left(360/8);
    }
    wait(50);
}

*/
/*
int main(){
  initCanvas("Pentagon and Star");
  double pentaV[5][2], starV[5][2];

  for(int i=0; i<5; i++){
    pentaV[i][0] = 100 * cos(2*PI/5*i);
    pentaV[i][1] = 100 * sin(2*PI/5*i);
    starV[i][0] = 100 * cos(4*PI/5*i);
    starV[i][1] = 100 * sin(4*PI/5*i);
  }

  simplecpp::Polygon penta(200,200,pentaV,5);
  simplecpp::Polygon star(200,400,starV,5);

  for(int i=0; i<100; i++){
    penta.left(5);
    star.right(5);
    wait(100);
  }

  //getClick();
}
*/
