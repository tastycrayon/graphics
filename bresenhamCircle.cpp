#include <iostream>
#include <graphics.h>
using namespace std;

class BresenhamCircle {
 private:
  int xc, yc;
  int x0, y0;
  int xPlot, yPlot;
  int radius;
  int decisionParameter;

 public:
  void startDrawing() {
    while (this->x0 <= this->y0) {
      if (this->decisionParameter <= 0) {
        this->x0++;
        this->decisionParameter += 4 * this->x0 + 6;
      } else {
        this->x0++;
        this->y0--;
        this->decisionParameter += 4 * (this->x0 - this->y0) + 10;
      }
      this->drawPixel(this->x0, this->y0);    // 1
      this->drawPixel(this->y0, this->x0);    // 2
      this->drawPixel(this->y0, -this->x0);   // 3
      this->drawPixel(this->x0, -this->y0);   // 4
      this->drawPixel(-this->x0, -this->y0);  // 5
      this->drawPixel(-this->y0, -this->x0);  // 6
      this->drawPixel(-this->y0, this->x0);   // 7
      this->drawPixel(-this->x0, this->y0);   // 8
    }
  }

  void drawPixel(int x, int y) {
    putpixel(this->xPlot + x, this->yPlot + y, BLACK);
  }

  BresenhamCircle(int x = 0, int y = 0, int radius = 220) {
    this->radius = radius;

    this->x0 = 0;
    this->y0 = this->radius;

    this->xc = getmaxx() / 2;
    this->yc = getmaxy() / 2;

    this->xPlot = this->xc + x;
    this->yPlot = this->yc - y;

    this->decisionParameter = 3 - 2 * this->radius;
  };
  ;
  ~BresenhamCircle(){};
};

int main(int argc, char const *argv[]) {
  int gd = DETECT, gm;
  char pathDriver[] = "";
  initgraph(&gd, &gm, pathDriver);

  floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
  // axis
  setcolor(RED);
  line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
  line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
  // circle
  BresenhamCircle *circle = new BresenhamCircle(30, 30, 150);
  circle->startDrawing();

  getch();
  closegraph();
  return 0;
}