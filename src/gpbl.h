#ifndef GPBL_H_
#define GPBL_H_
#define TIMER 120 // Time limit: 2 minutes

struct position{
  int x, y;
};
typedef struct position POSITION;

void setWindow(POSITION *start);
void initShapes(POSITION *triangle, POSITION *circle, POSITION *square, POSITION *trapeziod, POSITION *parallelogram, POSITION *rectangle, POSITION *smalltriangle, POSITION *smallcircle, POSITION *smallsquare, POSITION *smalltrapeziod, POSITION *smallparallelogram, POSITION *smallrectangle );
void createTree(int x, int y, int z);
#endif
