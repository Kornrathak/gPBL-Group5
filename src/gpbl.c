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
		case 100: createTree(12, 14, 2);break;
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
