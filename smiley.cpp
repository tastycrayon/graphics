#include <conio.h>
#include <graphics.h>

#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;
class Smiley {
private:
  int centerX = 0, centerY = 0, radius = 0;

public:
  void startDrawing() {
    this->faceShape();
    this->drawEye();
    this->drawMouth();
    this->drawEar();
  }
  void faceShape() {
    setcolor(YELLOW);
    circle(this->centerX, this->centerY, this->radius);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(this->centerX + 10, this->centerY + 10, YELLOW);
  }
  void drawEye() {
    int distance = this->radius / 4;
    setcolor(BLACK);
    setfillstyle(1, BLACK);

    ellipse(this->centerX + distance, this->centerY - distance, 0, 360, 10, 25);
    fillellipse(this->centerX + distance, this->centerY - distance, 10, 25);

    ellipse(this->centerX - distance, this->centerY - distance, 0, 360, 10, 25);
    fillellipse(this->centerX - distance, this->centerY - distance, 10, 25);
  }
  void drawMouth() {
    int distance = this->radius / 2.2;
    int degree = 270;
    int width = 40;
    setlinestyle(SOLID_LINE, 0, 5);
    arc(this->centerX, this->centerY - 20, degree - width, degree + width,
        distance);
    setlinestyle(SOLID_LINE, 0, 1);
  }

  void drawEar() {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, BLACK);

    // small
    setcolor(YELLOW);
    int points2[] = {this->centerX + this->rSin(this->radius, 220),
                     this->centerY + this->rCos(this->radius, 220),
                     this->centerX + this->rSin(this->radius, 210),
                     this->centerY + this->rCos(this->radius, 210),
                     this->centerX + this->rSin(this->radius + 25, 215),
                     this->centerY + this->rCos(this->radius + 25, 215),
                     this->centerX + this->rSin(this->radius, 220),
                     this->centerY + this->rCos(this->radius, 220)};
    drawpoly(4, points2);
    floodfill(points2[2] - 2, points2[3], YELLOW);

    // large
    setfillstyle(SOLID_FILL, YELLOW);
    int points[] = {this->centerX + this->rSin(this->radius, 230),
                    this->centerY + this->rCos(this->radius, 230),
                    this->centerX + this->rSin(this->radius, 200),
                    this->centerY + this->rCos(this->radius, 200),
                    this->centerX + this->rSin(this->radius + 75, 215),
                    this->centerY + this->rCos(this->radius + 75, 215),
                    this->centerX + this->rSin(this->radius, 230),
                    this->centerY + this->rCos(this->radius, 230)};
    drawpoly(4, points);
    floodfill(this->centerX + this->rSin(this->radius, 225) - 2,
              this->centerY + this->rCos(this->radius, 225), YELLOW);

    // small
    setfillstyle(SOLID_FILL, BLACK);
    int points3[] = {this->centerX + this->rSin(this->radius, 140),
                     this->centerY + this->rCos(this->radius, 140),
                     this->centerX + this->rSin(this->radius, 150),
                     this->centerY + this->rCos(this->radius, 150),
                     this->centerX + this->rSin(this->radius + 25, 145),
                     this->centerY + this->rCos(this->radius + 25, 145),
                     this->centerX + this->rSin(this->radius, 140),
                     this->centerY + this->rCos(this->radius, 140)};
    drawpoly(4, points3);
    floodfill(points3[2] + 2, points3[3], YELLOW);
    // large
    setfillstyle(SOLID_FILL, YELLOW);
    int points1[] = {this->centerX + this->rSin(this->radius, 130),
                     this->centerY + this->rCos(this->radius, 130),
                     this->centerX + this->rSin(this->radius, 160),
                     this->centerY + this->rCos(this->radius, 160),
                     this->centerX + this->rSin(this->radius + 75, 145),
                     this->centerY + this->rCos(this->radius + 75, 145),
                     this->centerX + this->rSin(this->radius, 130),
                     this->centerY + this->rCos(this->radius, 130)};
    drawpoly(4, points1);
    floodfill(this->centerX + this->rSin(this->radius, 155) + 2,
              this->centerY + this->rCos(this->radius, 155), YELLOW);
  }

  int rCos(int r, int angle) {
    float result = (float)r * cos(angle * PI / 180.0);
    return round(result);
  }
  int rSin(int r, int angle) {
    float result = (float)r * sin(angle * PI / 180.0);
    return round(result);
  }
  Smiley(int xc, int yc, int r) {
    this->centerX = xc;
    this->centerY = yc;
    this->radius = r;
  };
  ~Smiley(){};
};

int main() {
  int gd = DETECT, gm;
  char pathDriver[] = "";
  initgraph(&gd, &gm, pathDriver);
  floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
  //   axis
  setcolor(RED);
  // line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
  // line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());

  // smiley start
  int centerX = getmaxx() / 2;
  int centerY = getmaxy() / 2;

  Smiley *mySmiley = new Smiley(centerX, centerY, 150);
  mySmiley->startDrawing();
  // smiley end

  getch();
  closegraph();
  return 0;
}