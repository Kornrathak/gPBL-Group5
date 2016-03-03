#ifndef GPBL_H_
#define GPBL_H_
#define TIMER 45 // Time limit: 2 minutes
#define ROW_GAME 19
#define MAX_OBJECT 9
#define POINT_SHOW_X 30
#define POINT_SHOW_Y 1

struct position{
  int x, y;
};
typedef struct position POSITION;

void setWindow(POSITION *start);
void initShapes(POSITION *triangle, POSITION *circle, POSITION *square, POSITION *trapeziod, POSITION *parallelogram, POSITION *rectangle, POSITION *smalltriangle, POSITION *smallcircle, POSITION *smallsquare, POSITION *smalltrapeziod, POSITION *smallparallelogram, POSITION *smallrectangle );
void createTree(int x, int y, int z);
void createSquare(POSITION *square, int x, int y, int z);
void createCircle(POSITION *circle, int x, int y, int z);
void createTriangle(POSITION *triangle, int x, int y, int z);
void createTrapeziod(POSITION *trapeziod, int x, int y, int z);
void createParallelogram(POSITION *parallelogram, int x, int y, int z);
void createRectangle(POSITION *rectangle, int x, int y, int z);
void createSquareDoor(int x, int y, int z);
void createSmallSquare(POSITION *smallsquare, int x, int y, int z);
void createSmallTriangle(POSITION *smalltriangle, int x, int y, int z);
void createSmallCircle(POSITION *smallcircle, int x, int y, int z);
void createSmallTrapeziod(POSITION *smalltrapeziod, int x, int y, int z);
void createSmallParallelogram(POSITION *smallparallelogram, int x, int y, int z);
void createSmallRectangle(POSITION *smallrectangle, int x, int y, int z);
void createBox(int x, int y);
void fillinBox(int number);
int checkHighScore(int score, int selecter, int answer, int count);
void createBus(int t_out, int stop);
int gameover(POSITION *start, int score);
void createTopTree(int x, int y, int z);
void setZero(void); void setOne(void); void setTwo(void); void setThree(void); void setFour(void); void setFive(void); void setSix(void); void setSeven(void);
void setStartDisplay();
#endif
