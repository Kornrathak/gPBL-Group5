#include "gpbl.h"
#include <stdio.h>
// #include <math.h>
#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    POSITION *triangle = (POSITION *)malloc(sizeof(POSITION));
    POSITION *circle = (POSITION *)malloc(sizeof(POSITION));
    POSITION *square = (POSITION *)malloc(sizeof(POSITION));
    POSITION *trapeziod = (POSITION *)malloc(sizeof(POSITION));
    POSITION *parallelogram = (POSITION *)malloc(sizeof(POSITION));
    POSITION *rectangle = (POSITION *)malloc(sizeof(POSITION));
    POSITION *smalltriangle = (POSITION *)malloc(sizeof(POSITION));
    POSITION *smallcircle = (POSITION *)malloc(sizeof(POSITION));
    POSITION *smallsquare = (POSITION *)malloc(sizeof(POSITION));
    POSITION *smalltrapeziod = (POSITION *)malloc(sizeof(POSITION));
    POSITION *smallparallelogram = (POSITION *)malloc(sizeof(POSITION));
    POSITION *smallrectangle = (POSITION *)malloc(sizeof(POSITION));
    

    POSITION *start = (POSITION *)malloc(sizeof(POSITION));
    POSITION *timer = (POSITION *)malloc(sizeof(POSITION));

    int ch;
    int cnt = 0; // Timer

    timer->x = 2;
    timer->y = 1;

    initscr();
    noecho();
    cbreak();
    start_color();
    curs_set(0);
    timeout(1000); // 1000msec

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
//    init_pair(8, COLOR_VIOLET, COLOR_BLACK);
    
    ch = getch();
    setWindow(start);
    initShapes(triangle, circle, square, trapeziod, parallelogram, rectangle, smalltriangle, smallcircle, smallsquare, smalltrapeziod, smallparallelogram, smallrectangle);
    
    int result;

    while (ch != 'q'){
	result = TIMER - cnt;
        mvprintw(timer->y, timer->x, "Time: %3d sec", result);
	switch(result){
		case 115:
		  createTrapeziod(trapeziod, 22, 29, 4);
		  break;
		case 110:
		  createTrapeziod(trapeziod, 22, 29, 7);
		  createTriangle(triangle, 60, 16, 1);
		  break;
	        case 105:
		  createTriangle(triangle, 60, 16, 7);
		  createRectangle(rectangle, 97, 20, 5);
		  break;
	        case 100:
		  createRectangle(rectangle, 97, 20, 7);
		  createParallelogram(parallelogram, 94, 16, 7);
		  createCircle(circle, 74, 7, 3);
		  break;
         	case 95:
	         createCircle(circle, 74, 7, 7);
          	 createParallelogram(parallelogram, 122, 30, 6);
         	 break;
	        case 90:
		 createParallelogram(parallelogram, 122, 30, 7);
		 createSquare(square, 38, 20,2);
		 break;
		case 85:
		 createSquare(square, 38, 20,7);
		 createTriangle(triangle, 37, 16, 7);
		 break;
	}
        refresh();
        cnt++;
	
        if ((TIMER - cnt) == 0) {
            break;
        }

        ch = getch();
    }

    endwin();
    return 0;
}
