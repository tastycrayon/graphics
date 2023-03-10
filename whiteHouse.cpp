#include <conio.h>
#include <graphics.h>
#include <iostream>
using namespace std;

class Shape {
private:
  int centerX = 0, centerY = 0, width = 0, radius, spacing = 0;

public:
  void startDrawing() {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    this->drawRoof();
    this->drawBar();
  }
  void drawBar() {
    int barWidth = this->width - 30, barDepth = 25;
    bar(this->centerX - barWidth, this->centerY + spacing,
        this->centerX + barWidth, this->centerY + spacing + barDepth);
    // 3 bar
    int lastHeight = this->centerY + spacing + barDepth;
    int barLength = barWidth;
    bar(this->centerX - barDepth / 2, lastHeight + spacing,
        this->centerX + barDepth / 2, lastHeight + spacing + barLength);
    int distance = spacing * 7;
    bar(this->centerX - barDepth / 2 - distance, lastHeight + spacing,
        this->centerX + barDepth / 2 - distance,
        lastHeight + spacing + barLength);
    bar(this->centerX - barDepth / 2 + distance, lastHeight + spacing,
        this->centerX + barDepth / 2 + distance,
        lastHeight + spacing + barLength);
    lastHeight = lastHeight + spacing + barLength;
    // bottom 2 bar
    bar(this->centerX - barWidth, lastHeight + spacing,
        this->centerX + barWidth, lastHeight + spacing + barDepth);
    lastHeight = lastHeight + spacing + barDepth;
    bar(this->centerX - this->width, lastHeight + spacing,
        this->centerX + this->width, lastHeight + spacing + barDepth);
  }
  void drawRoof() {
    int triangleHeight = this->width / 2;
    int triangleWidth = this->width;
    int points[] = {
        this->centerX,
        centerY - triangleHeight,
        this->centerX + triangleWidth,
        this->centerY,
        this->centerX - triangleWidth,
        this->centerY,
        this->centerX,
        centerY - triangleHeight,
    };
    drawpoly(4, points);
    floodfill(this->centerX, centerY - triangleHeight + 5, BLACK);
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