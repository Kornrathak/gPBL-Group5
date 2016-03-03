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
    POSITION *highscore = (POSITION *)malloc(sizeof(POSITION));

    int ch;
    int cnt = 0;    // Timer

    timer->x = 2;
    timer->y = 1;
    highscore->x = 2;
    highscore->y = 2;

    initscr();
    noecho();
    cbreak();
    start_color();
    keypad(stdscr, true);
    curs_set(0);
    timeout(1); // 1000msec

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);
    init_pair(9, COLOR_BLACK, COLOR_BLACK);

    ch = getch();
    setWindow(start);
    initShapes(triangle, circle, square, trapeziod, parallelogram, rectangle, smalltriangle, smallcircle, smallsquare, smalltrapeziod, smallparallelogram, smallrectangle);

    int result;     // result = TIMER-cnt
    int score = 0;  // High Score
    int t_out = 0;
    int number = 0;
    int small_coordinate[8] = {
        12,
        25,
        38,
        51,
        64,
        77,
        90,
        103
    };
    // 0:trap 1:tri 2:rect 3:cir 4:paral 5:squ 6:toptree(term1)
    int timelimit[MAX_OBJECT][3] = {
        {TIMER-4, TIMER-10, 3},
        {TIMER-10, TIMER-15, 0},
        {TIMER-15, TIMER-20, 4},
        {TIMER-20, TIMER-25, 2},
        {TIMER-25, TIMER-30, 5},
        {TIMER-30, TIMER-35, 1},
        {TIMER-35, TIMER-40, 6}
    };
    int step = 0;
    int choise = 0;

    //system("(sh supermariobros.sh)&");

    while (ch != 'q'){
        t_out++;
        if (t_out % 1000 == 0) {
            cnt++;
        }

        result = TIMER - cnt;
        //mvprintw(4, 2, "Time Start: %3d, Time End: %3d, Answer: %d, value of choise: %d", timelimit[step][0], timelimit[step][1], timelimit[step][2], choise);
        if (ch == KEY_RIGHT && number < 7) {
            number++;
            //mvprintw(3, 2, "input: %5s", "RIGHT");
            attron(COLOR_PAIR(8));
            mvprintw(43, small_coordinate[number]+1, "***");
            attroff(COLOR_PAIR(8));
            attron(COLOR_PAIR(9));
            mvprintw(43, small_coordinate[number-1]+1, "   ");
            attroff(COLOR_PAIR(9));
        }
        else if (ch == KEY_LEFT && number > 0) {
            number--;
            //mvprintw(3, 2, "input: %5s", "LEFT");
            attron(COLOR_PAIR(8));
            mvprintw(43, small_coordinate[number]+1, "***");
            attroff(COLOR_PAIR(8));
            attron(COLOR_PAIR(9));
            mvprintw(43, small_coordinate[number+1]+1, "   ");
            attroff(COLOR_PAIR(9));
        }
        else if(ch == KEY_ENTER || ch == KEY_DOWN){
            if(result < timelimit[step][0] && result > timelimit[step][1] && choise == 0){
                score = checkHighScore(score, number, timelimit[step][2]);
                choise++;
            }
        }
        if(timelimit[step][1] == result && choise == 1){
            choise--;
        }

        if(timelimit[step][1] == result){
            step++;
        }


        //fillinBox(number);
        mvprintw(timer->y, timer->x, "Time: %3d sec.", result);
        mvprintw(highscore->y, highscore->x, "High Score: %2d point.", score);
        createBus(t_out, timelimit[MAX_OBJECT-1][1]);

        switch(result){ // TIMER = 45 
            case TIMER-5:
                createTrapeziod(trapeziod, 22, 29, 4);
                break;
            case TIMER-10:
                createTrapeziod(trapeziod, 22, 29, 7);
                createTriangle(triangle, 60, 16, 1);
                break;
            case TIMER-15:
                createTriangle(triangle, 60, 16, 7);
                createRectangle(rectangle, 97, 20, 5);
                break;
            case TIMER-20:
                createRectangle(rectangle, 97, 20, 7);
                createParallelogram(parallelogram, 94, 16, 7);
                createCircle(circle, 74, 7, 3);
                break;
            case TIMER-25:
                createCircle(circle, 74, 7, 7);
                createParallelogram(parallelogram, 122, 30, 6);
                break;
            case TIMER-30:
                createParallelogram(parallelogram, 122, 30, 7);
                createSquare(square, 38, 20,2);
                break;
            case TIMER-35:
                createSquare(square, 38, 20,7);
                createTriangle(triangle, 37, 16, 7);
                createSquareDoor(40, 21, 7);
                createTopTree(12, 14, 4);
                break;
            case TIMER-40:
                createTopTree(12, 14, 7);
                break;
        }

        refresh();

        if(result == 0) {
            gameover(start, score);
            break;
        }

        ch = getch();
    }

    endwin();
    //system("sudo killall beep");
    return 0;
}
