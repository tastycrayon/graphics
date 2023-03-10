#include <conio.h>
#include <graphics.h>

#include <iostream>
using namespace std;

class Shape {
private:
  int centerX = 0, centerY = 0, width = 0, radius;

public:
  void startDrawing() {
    this->outerFrame();
    this->innerCircle();
    this->innerLines();
  }
  void innerLines() {
    setlinestyle(SOLID_LINE, 0, 10);
    int topStart = this->width * 80 / 100; // 80%
    int topEnd = this->width * 10 / 100;   // 10%
    line(this->centerX, this->centerY - topStart, this->centerX,
         this->centerY + topEnd);

    int lineDistance = topEnd;
    int line2Width = this->width * 80 / 100;
    line(this->centerX - line2Width, this->centerY + topEnd,
         this->centerX + line2Width, this->centerY + topEnd);
    lineDistance += 30;
    int line3Width = this->width * 60 / 100;
    line(this->centerX - line3Width, this->centerY + lineDistance,
         this->centerX + line3Width, this->centerY + lineDistance);
    lineDistance += 30;
    int line4Width = this->width * 40 / 100;
    line(this->centerX - line4Width, this->centerY + lineDistance,
         this->centerX + line4Width, this->centerY + lineDistance);
    setlinestyle(SOLID_LINE, 0, 1);
  }
  void innerCircle() {
    this->radius = this->width - (this->width * 10 / 100);
    circle(this->centerX, this->centerY, this->radius);
  }
  void outerFrame() {
    rectangle(this->centerX - this->width, this->centerY - this->width,
              this->centerX + this->width, this->centerY + this->width);
  }

  Shape(int xc, int yc, int w) {
    this->centerX = xc;
    this->centerY = yc;
    this->width = w;
  };
  ~Shape(){};
};

int main() {
  int gd = DETECT, gm;
  char pathDriver[] = "";
  initgraph(&gd, &gm, pathDriver);
  floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
  setcolor(BLACK);

  // Shape start
  int centerX = getmaxx() / 2;
  int centerY = getmaxy() / 2;

  Shape *myShape = new Shape(centerX, centerY, 150);
  myShape->startDrawing();
  // Shape end

  getch();
  closegraph();
  return 0;
}