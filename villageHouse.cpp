#include <conio.h>
#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;
#define PI 3.14159265
class Shape {
public:
  int centerX = 0, centerY = 0, width = 0, radius, spacing = 0, lastHeight;
  void startDrawing() {
    setcolor(BLACK);
    this->drawRoof();
    this->drawWall();
    this->drawDoor();
    this->drawSun();
  }
  void drawSun() {
    int triangleHeight = this->width / 2, triangleWidth = this->width, r = 30;
    circle(this->centerX + 100, this->centerY - triangleHeight - 70, r);
    int space = r + 5;
    int circleCenterX = this->centerX + 100;
    int circleCenterY = this->centerY - triangleHeight - 70;
    int length = 20, interval = 15;
    for (int i = 0; i < 360; i += interval) {
      line(circleCenterX + this->rSin(space, i),
           circleCenterY + this->rCos(space, i),
           circleCenterX + this->rSin(space + length, i),
           circleCenterY + this->rCos(space + length, i));
      i += interval;
      line(circleCenterX + this->rSin(space, i),
           circleCenterY + this->rCos(space, i),
           circleCenterX + this->rSin(space + length + 20, i),
           circleCenterY + this->rCos(space + length + 20, i));
    }
  }
  int rCos(int r, int a) { return round((float)r * cos(a * PI / 180.0)); }
  int rSin(int r, int a) { return round((float)r * sin(a * PI / 180.0)); }
  void drawDoor() {
    int doorHeight = (this->width - 20) * 2 / 3, doorWidth = 20;
    rectangle(this->centerX - doorWidth, lastHeight - doorHeight,
              this->centerX + doorWidth, lastHeight);
    int windowHeight = doorHeight - 10, windowWidth = 25;
    int mid =
        abs(((this->centerX - doorWidth) - this->centerX - (this->width - 20)) /
            2) -
        10;
    circle(this->centerX - doorWidth - mid, lastHeight - windowHeight,
           windowWidth);
    circle(this->centerX + doorWidth + mid, lastHeight - windowHeight,
           windowWidth);
  }
  void drawWall() {
    int houseWidth = this->width - 20, houseHeight = houseWidth;
    rectangle(this->centerX - houseWidth, lastHeight,
              this->centerX + houseHeight, lastHeight + houseHeight);
    lastHeight = lastHeight + houseHeight;
  }
  void drawRoof() {
    int triangleHeight = this->width / 2, triangleWidth = this->width;
    int points[] = {this->centerX,
                    centerY - triangleHeight,
                    this->centerX + triangleWidth,
                    this->centerY,
                    this->centerX - triangleWidth,
                    this->centerY,
                    this->centerX,
                    centerY - triangleHeight};
    drawpoly(4, points);
    floodfill(this->centerX, centerY - triangleHeight + 5, BLACK);
    lastHeight = this->centerY;
  }
  Shape(int xc, int yc, int w) {
    this->centerX = xc;
    this->centerY = yc;
    this->width = w;
    this->spacing = 10;
  };
  ~Shape(){};
};
int main() {
  int gd = DETECT, gm;
  char pathDriver[] = "";
  initgraph(&gd, &gm, pathDriver);
  floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
  int centerX = getmaxx() / 2, centerY = getmaxy() / 2; // Shape start
  Shape *myShape = new Shape(centerX, centerY, 150);
  myShape->startDrawing(); // Shape end
  getch();
  closegraph();
  return 0;
}