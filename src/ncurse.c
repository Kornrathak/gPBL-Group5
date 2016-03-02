#include <ncurses.h>
#include <stdlib.h>
#include "gpbl.h"
#include <stdio.h>

// Set Window of Game
void setWindow(POSITION *start){
    start->x = 0;
    start->y = 0;
    int i, j;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 150; j++){
            if(i == 0){
                mvprintw(start->y + i, start->x + j, "_");
            }
            else if(j == 0 || j == 149){
                mvprintw(start->y + i, start->x + j, "|");
            }
        }
    }

    start->x = 0;
    start->y = 5;

    for(i = 0; i < 44; i++){
        for(j = 0; j < 150; j++){
            if((i == 0) && (j != 0 && j != 149)){
                mvprintw(start->y + i, start->x + j, "_");
            }
            else if((i == 33) && (j != 0 && j != 9 && j != 75 && j != 83  && j != 140 && j != 149)){
                mvprintw(start->y + i, start->x + j, "_");
            }
            else if((i == 43) && (j != 0 && j != 9 && j != 140 && j != 149)){
                mvprintw(start->y + i, start->x + j, "_");
            }
            else if(j == 0  || j == 9 || j == 149 || j == 140){
                mvprintw(start->y + i, start->x + j, "|");
            }
            else if(i == 9 && j == 4){
                mvprintw(start->y + i, start->x + j, "H");
            }
            else if(i == 14 && j == 4){
                mvprintw(start->y + i, start->x + j, "O");
            }
            else if(i == 19 && j == 4){
                mvprintw(start->y + i, start->x + j, "M");
            }
            else if(i == 24 && j == 4){
                mvprintw(start->y + i, start->x + j, "E");
            }
            else if(i == 3 && j == 144){
                mvprintw(start->y + i, start->x + j, "P");
            }
            else if(i == 6 && j == 144){
                mvprintw(start->y + i, start->x + j, "L");
            }
            else if(i == 9 && j == 144){
                mvprintw(start->y + i, start->x + j, "A");
            }
            else if(i == 12 && j == 144){
                mvprintw(start->y + i, start->x + j, "Y");
            }
            else if(i == 16 && j == 144){
                mvprintw(start->y + i, start->x + j, "G");
            }
            else if(i == 19 && j == 144){
                mvprintw(start->y + i, start->x + j, "R");
            }
            else if(i == 22 && j == 144){
                mvprintw(start->y + i, start->x + j, "O");
            }
            else if(i == 25 && j == 144){
                mvprintw(start->y + i, start->x + j, "U");
            }
            else if(i == 28 && j == 144){
                mvprintw(start->y + i, start->x + j, "N");
            }
            else if(i == 31 && j == 144){
                mvprintw(start->y + i, start->x + j, "D");
            }
	          else if(i == 8 && (j > 9 && j < 140)){
		            mvprintw(start->y + i, start->x + j, "_");
	          }
            else if((j == 75 || j == 83) && ((i > 8 && i < 20)||(i > 23 && i < 34))){
                mvprintw(start->y + i, start->x + j, "|");
            }
            else if((i == 19 || i == 23) && ((j > 9 && j < 75)||(j > 83 && j < 140))){
                mvprintw(start->y + i, start->x + j, "_");
            }
            /*
            else{
                mvprintw(start->y + i, start->x + j, " ");
            }
            */
        }
    }
}
//Drawing Shapes
void createSquare(POSITION *square, int x, int y, int z){
  square->x = x;
  square->y = y;
  attron(COLOR_PAIR(z));
  mvprintw(square->y, square->x,      "______"); //square
  mvprintw(square->y + 1, square->x,  "|#####|"); //square
  mvprintw(square->y + 2, square->x,  "|#####|"); //square
  mvprintw(square->y + 3, square->x,  "|#####|"); //square
  attroff(COLOR_PAIR(z));
}
void createCircle(POSITION *circle, int x, int y, int z){
  circle->x = x;
  circle->y = y;
  attron(COLOR_PAIR(z));
  mvprintw(circle->y, circle->x+4,      "***"); //circle
  mvprintw(circle->y + 1, circle->x+1,  "*********"); //circle
  mvprintw(circle->y + 2, circle->x,  "***********"); //circle
  mvprintw(circle->y + 3, circle->x,  "***********"); //circle
  mvprintw(circle->y + 4, circle->x+1,  "*********"); //circle
  mvprintw(circle->y + 5, circle->x+4, "***"); //circle
  attroff(COLOR_PAIR(z));
}
void createTriangle(POSITION *triangle, int x, int y, int z){
    triangle->x = x;
    triangle->y = y;
    attron(COLOR_PAIR(z));
    mvprintw(triangle->y, triangle->x+4,      "."); //triangle
    mvprintw(triangle->y + 1, triangle->x+3,  "/#\\"); //triangle
    mvprintw(triangle->y + 2, triangle->x+2,  "/###\\"); //triangle
    mvprintw(triangle->y + 3, triangle->x+1,  "/#####\\"); //triangle
    mvprintw(triangle->y + 4, triangle->x,  "/#######\\"); //triangle
    attroff(COLOR_PAIR(z));
}
void createTrapeziod(POSITION *trapeziod, int x, int y, int z){
    trapeziod->x = x;
    trapeziod->y = y;
    attron(COLOR_PAIR(z));
    mvprintw(trapeziod->y, trapeziod->x+4,   "________");
    mvprintw(trapeziod->y+1, trapeziod->x+3, "/########\\");
    mvprintw(trapeziod->y+2, trapeziod->x+2, "/##########\\");
    mvprintw(trapeziod->y+3, trapeziod->x+1, "/############\\");
    attroff(COLOR_PAIR(z));
}
void createParallelogram(POSITION *parallelogram, int x, int y, int z){
    parallelogram ->x = x;
    parallelogram ->y = y;
    attron(COLOR_PAIR(z));
    mvprintw(parallelogram->y ,parallelogram->x,    "____________");
    mvprintw(parallelogram->y+1 ,parallelogram->x,  "\\###########\\");
    mvprintw(parallelogram->y+2 ,parallelogram->x+1,  "\\###########\\");
    mvprintw(parallelogram->y+3 ,parallelogram->x+2,  "\\###########\\");
    mvprintw(parallelogram->y+4 ,parallelogram->x+3,  "\\###########\\");
  attroff(COLOR_PAIR(z));
}
void createRectangle(POSITION *rectangle, int x, int y, int z){
    rectangle->x = x;
    rectangle->y = y;
    attron(COLOR_PAIR(z));
    mvprintw(rectangle->y, rectangle->x,    ".__________");
    mvprintw(rectangle->y+1, rectangle->x,  "|##########|");
    mvprintw(rectangle->y+2, rectangle->x,  "|##########|");
    mvprintw(rectangle->y+3, rectangle->x,  "|##########|");
  attroff(COLOR_PAIR(z));
}
void createTree(int x, int y, int z){
  attron(COLOR_PAIR(z));
  mvprintw( y++, x+3,"/\\");
  mvprintw( y++, x+2,"/##\\");
  mvprintw( y++, x+1,"/####\\");
  mvprintw( y++, x,  "/######\\");
  mvprintw( y++, x+2,"/###\\");
  mvprintw( y++, x+1,"/#####\\");
  mvprintw( y++, x,  "/#######\\");
  mvprintw( y++, x+3,"|#|");
  mvprintw( y++, x+3,"|#|");
  attroff(COLOR_PAIR(z));
}
void createSquareDoor(int x, int y, int z){
attron(COLOR_PAIR(z));
  mvprintw( y++, x,  "___");
  mvprintw( y++, x,  "|#|");
  mvprintw( y++, x,  "|#|");
  attroff(COLOR_PAIR(z));
}
void createSmallSquare(POSITION *smallsquare, int x, int y, int z){
    smallsquare->x = x;
    smallsquare->y = y;
    attron(COLOR_PAIR(z));
    mvprintw(smallsquare->y, smallsquare->x,  " ___" );
    mvprintw(smallsquare->y+1, smallsquare->x,"|###|");
    mvprintw(smallsquare->y+2, smallsquare->x,"|###|");
  attroff(COLOR_PAIR(z));
  createBox(smallsquare->x, smallsquare->y+4);
}
void createSmallTriangle(POSITION *smalltriangle, int x, int y, int z){
    smalltriangle->x =x;
    smalltriangle->y =y;
    attron(COLOR_PAIR(z));
    mvprintw(smalltriangle->y, smalltriangle->x+1,  "/\\");
    mvprintw(smalltriangle->y+1, smalltriangle->x,"/##\\");
    attroff(COLOR_PAIR(z));
    createBox(smalltriangle->x, smalltriangle->y+3);
}
void createSmallCircle(POSITION *smallcircle, int x, int y, int z){
    smallcircle->x = x;
    smallcircle->y= y;
attron(COLOR_PAIR(z));
    mvprintw(smallcircle->y, smallcircle->x+2,    "_");
    mvprintw(smallcircle->y+1, smallcircle->x,  ".\"#\".");
    mvprintw(smallcircle->y+2, smallcircle->x+1,  "\"-\"");
  attroff(COLOR_PAIR(z));
    createBox(smallcircle->x, smallcircle->y+4);
}
void createSmallTrapeziod(POSITION *smalltrapeziod, int x, int y, int z){
    smalltrapeziod->x = x;
    smalltrapeziod->y = y;
attron(COLOR_PAIR(z));
    mvprintw(smalltrapeziod->y, smalltrapeziod->x+2,    "___");
    mvprintw(smalltrapeziod->y+1, smalltrapeziod->x+1,  "/###\\");
    mvprintw(smalltrapeziod->y+2, smalltrapeziod->x,  "/#####\\");
  attroff(COLOR_PAIR(z));
    createBox(smalltrapeziod->x, smalltrapeziod->y+4);
}
void createSmallParallelogram(POSITION *smallparallelogram, int x, int y, int z){
    smallparallelogram->x = x;
    smallparallelogram->y = y;
attron(COLOR_PAIR(z));
    mvprintw(smallparallelogram->y, smallparallelogram->x,    "_____" );
    mvprintw(smallparallelogram->y+1, smallparallelogram->x,  "\\####\\" );
    mvprintw(smallparallelogram->y+2, smallparallelogram->x+1,  "\\####\\" );
    attroff(COLOR_PAIR(z));
    createBox(smallparallelogram->x, smallparallelogram->y+4);
}
void createSmallRectangle(POSITION *smallrectangle, int x, int y, int z){
    smallrectangle->x = x;
    smallrectangle->y = y;
    attron(COLOR_PAIR(z));
    mvprintw(smallrectangle->y, smallrectangle->x,      "._____." );
    mvprintw(smallrectangle->y+1, smallrectangle->x,    "|#####|" );
    mvprintw(smallrectangle->y+2, smallrectangle->x,    "|#####|" );
    attroff(COLOR_PAIR(z));
    createBox(smallrectangle->x, smallrectangle->y+4);
}
void createBusStop(int x, int y, int z){
  attron(COLOR_PAIR(z));
  mvprintw(y++, x, "._______");
  mvprintw(y++, x, "|\\######\\");
  mvprintw(y++, x, "| \\######\\");
  mvprintw(y++, x, "| |      |");
  mvprintw(y++, x, "  |      |");
  mvprintw(y++, x, "  |      |");
  attroff(COLOR_PAIR(z));
}

void createBox(int x, int y){
    mvprintw(y, x, "[   ]");
}

// Initialize Shapes
void initShapes(POSITION *triangle, POSITION *circle, POSITION *square, POSITION *trapeziod, POSITION *parallelogram, POSITION *rectangle, POSITION *smalltriangle, POSITION *smallcircle, POSITION *smallsquare, POSITION *smalltrapeziod, POSITION *smallparallelogram, POSITION *smallrectangle){
//1[red] 2[green] 3[yellow] 4[blue] 5[magenta] 6[cyan] 7[white]
  //Sun
  createCircle(circle, 74, 7, 7);
  
  //Term 1
  //Home
  createSquare(square, 23, 20, 7);
  createTriangle(triangle, 22, 16, 7);
  createSquareDoor(25, 21, 7);
  //Home2
  createSquare(square, 38, 20, 7);
  createTriangle(triangle, 37, 16, 7);
  createSquareDoor(40, 21, 7);
  //Home3
  createSquare(square, 61, 20, 7);
  createTriangle(triangle, 60, 16, 7);
  createSquareDoor(63, 21, 7);
  //Tree
  createTree(12, 14, 7);
  createTree(48, 14, 7);
  
  //Term 2
  //Home5
  createRectangle(rectangle, 97, 20, 7);
  createParallelogram(parallelogram, 94, 16, 7);
  createSquare(square, 91, 20, 7);
  createTriangle(triangle, 90, 16, 7);
  createSquareDoor(93, 21, 7);
  //Bus Stop
  createBusStop(115, 18, 7);
  createTree(127, 15, 7);

  //Term 3
  //Home4
  createRectangle(rectangle, 24, 32, 7);
  createTrapeziod(trapeziod, 22, 29, 7);
  createSquareDoor(26, 33, 7);
  //Tree 
  createTree(44, 29, 7);
  createBusStop(58, 29, 7);

  //Term 4
  //Home6
  createSquare(square, 86, 33, 7);
  createTriangle(triangle, 85, 29, 7);
  createSquareDoor(88, 34, 7);
  //Home7
  createRectangle(rectangle, 124, 34, 7);
  createParallelogram(parallelogram, 122, 30, 7);
  createSquare(square, 119, 34, 7);
  createTriangle(triangle, 118, 30, 7);
  createSquareDoor(121, 35, 7);
  //Tree
  createTree(101, 29, 7);
  
  //Road
  //Bus
  mvprintw(25, 90, " __________");
  mvprintw(26, 90, "|_|  __  |_|");
  mvprintw(27, 90, "|_o_|__|_o_|");
  
  //Choise
  createSmallTriangle(smalltriangle, 12, 40, 1);
  createSmallSquare(smallsquare, 25, 39, 2);
  createSmallCircle(smallcircle, 38, 39, 3);
  createSmallTrapeziod(smalltrapeziod, 51, 39, 4);
  createSmallRectangle(smallrectangle, 64, 39, 5);

  createSmallParallelogram(smallparallelogram, 77, 39, 6);
  createSmallTriangle(smalltriangle, 90, 40, 4);
  createSmallCircle(smallcircle, 103, 39, 2);
}

void fillinBox(int number){
    attron(COLOR_PAIR(8));
    switch (number) {
        case 0:
            mvprintw(44, 13, "   ");
            break;
        case 1:
            mvprintw(42, 26, "   ");
            break;
        case 2:
            mvprintw(42, 39, "   ");
            break;
        default:break;
    }
}
