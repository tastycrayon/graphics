#include <conio.h>
#include <graphics.h>

#include <cmath>
#include <iostream>
using namespace std;

class Shape {
private:
  int centerX = 0, centerY = 0, width = 0, radius;

public:
  void startDrawing() {
    floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
    //   axis
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    int headPosition = this->centerY - 50;
    int headStart = this->centerX - this->width;
    int headEnd = this->centerX + this->width;

    line(headStart, headPosition, headEnd, headPosition);
    int depth = 50;
    int topHeadPosition = headPosition - depth;
    line(headStart + depth, topHeadPosition, headEnd - depth, topHeadPosition);

    arc(headStart + depth, headPosition, 90, 180, depth);
    arc(headEnd - depth, headPosition, 0, 90, depth);
    int pipeWidth = depth / 2;
    int pipeLength = depth - depth * 10 / 100;
    floodfill(headStart + 10, headPosition - 2, BLACK);
    // cap
    rectangle(this->centerX - pipeWidth, topHeadPosition - pipeLength,
              this->centerX + pipeWidth, topHeadPosition);
    floodfill(this->centerX + 2, topHeadPosition - 2, BLACK);

    // drops
    int dy = 30;
    int dx = 8;
    for (int i = 0; i < 5; i++) {
      int x = this->centerX, y = this->centerY + dy * i;
      circle(x, y, 10);
      floodfill(x, y + 1, BLACK);
    }
    for (int i = 0; i < 5; i++) {
      int x = this->centerX - 50 - dx * i, y = this->centerY + dy * i;
      circle(x, y, 10);
      floodfill(x, y + 1, BLACK);
    }
    for (int i = 0; i < 5; i++) {
      int x = this->centerX + 50 + dx * i, y = this->centerY + dy * i;
      circle(x, y, 10);
      floodfill(x, y + 1, BLACK);
    }
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