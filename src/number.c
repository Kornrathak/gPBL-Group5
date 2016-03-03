#include <ncurses.h>
#include <stdlib.h>
#include "gpbl.h"
#include <stdio.h>

void setStartDisplay(){
    int x = 25, y = 15;
    mvprintw(y++, x,"###########################################################################################");
    mvprintw(y++, x,"##             #######            ######             ########        #######   #######   ##");
    mvprintw(y++, x,"##   ##   ##   ######   #######   ###########   ############   ####   ######   #######   ##");
    mvprintw(y++, x,"##   ##   ##   ######              ##########   ###########   ######   #####              #");
    mvprintw(y++, x,"##   ##   ##   ######   #######   ###########   ###########  ###############   #######   ##");
    mvprintw(y++, x,"##   ##   ##   ######   #######   ###########   ###########   ######   #####   #######   ##");
    mvprintw(y++, x,"##   ##   ##   ######   #######   ###########   ############   ####   ######   #######   ##");
    mvprintw(y++, x,"##   ##   ##   ######   #######   ###########   #############        #######   #######   ##");
    mvprintw(y++, x,"###########################################################################################");
    mvprintw(y++, x+30,"##             ######              #");
    mvprintw(y++, x+30,"##   ##   ##   ######   ############");
    mvprintw(y++, x+30,"##   ##   ##   #####            ####");
    mvprintw(y++, x+30,"##   ##   ##   ######   ############");
    mvprintw(y++, x+30,"##   ##   ##   ######   ############");
    mvprintw(y++, x+30,"##   ##   ##   ######              #");
    mvprintw(y++, x,"###########################################################################################  ##");
    mvprintw(y++, x,"##   #######   #######            ######            #######            #####   ########   #  ##");
    mvprintw(y++, x,"##   #######   ######   #######   ######   #######   ######   #######   #####   ######   ##  ##");
    mvprintw(y++, x,"##              #####              ####             ######             #######   ####   ###  ##");
    mvprintw(y++, x,"##   #######   ######   #######   ######   ################   ##################      #####  ##");
    mvprintw(y++, x,"##   #######   ######   #######   ######   ################   ###################    ######  ##");
    mvprintw(y++, x,"##   #######   ######   #######   ######   ################   ###################    ######    ");
    mvprintw(y++, x,"###########################################################################################  ##");
     
   //press enter to play
   mvprintw(y++, x+25,"###############################################");
   mvprintw(y++, x+25,"#                                             #");  
   mvprintw(y++, x+25,"#   P R E S S    E N T E R   T O    P L A Y   #");
   mvprintw(y++, x+25,"#                                             #");
   mvprintw(y++, x+25,"###############################################");
}

void setZero(void) {
    mvprintw(ROW_GAME, 107,      "0000000000000");
    mvprintw(ROW_GAME + 1, 107,  "0000000000000");
    mvprintw(ROW_GAME + 2, 107,  "000       000");
    mvprintw(ROW_GAME + 3, 107,  "000       000");
    mvprintw(ROW_GAME + 4, 107,  "000       000");
    mvprintw(ROW_GAME + 5, 107,  "000       000");
    mvprintw(ROW_GAME + 6, 107,  "000       000");
    mvprintw(ROW_GAME + 7, 107,  "0000000000000");
    mvprintw(ROW_GAME + 8, 107,  "0000000000000");
}

void setOne(void) {
    mvprintw(ROW_GAME, 107,     "     000"); // number
    mvprintw(ROW_GAME + 1, 107, "     000");
    mvprintw(ROW_GAME + 2, 107, "     000");
    mvprintw(ROW_GAME + 3, 107, "     000");
    mvprintw(ROW_GAME + 4, 107, "     000");
    mvprintw(ROW_GAME + 5, 107, "     000");
    mvprintw(ROW_GAME + 6, 107, "     000");
    mvprintw(ROW_GAME + 7, 107, "     000");
    mvprintw(ROW_GAME + 8, 107, "     000");
    return;
}

void setTwo(void) {
    mvprintw(ROW_GAME, 107,      "0000000000000");
    mvprintw(ROW_GAME + 1, 107,  "0000000000000");
    mvprintw(ROW_GAME + 2, 107,  "          000");
    mvprintw(ROW_GAME + 3, 107,  "          000");
    mvprintw(ROW_GAME + 4, 107,  "0000000000000");
    mvprintw(ROW_GAME + 5, 107,  "000");
    mvprintw(ROW_GAME + 6, 107,  "000");
    mvprintw(ROW_GAME + 7, 107,  "0000000000000");
    mvprintw(ROW_GAME + 8, 107,  "0000000000000");
    return;
}

void setThree(void) {
    mvprintw(ROW_GAME, 107,      "0000000000000");
    mvprintw(ROW_GAME + 1, 107,  "0000000000000");
    mvprintw(ROW_GAME + 2, 107,  "          000");
    mvprintw(ROW_GAME + 3, 107,  "          000");
    mvprintw(ROW_GAME + 4, 107,  "0000000000000");
    mvprintw(ROW_GAME + 5, 107,  "          000");
    mvprintw(ROW_GAME + 6, 107,  "          000");
    mvprintw(ROW_GAME + 7, 107,  "0000000000000");
    mvprintw(ROW_GAME + 8, 107,  "0000000000000");
    return;
}

void setFour(void) {
    mvprintw(ROW_GAME, 107,      "000       000");
    mvprintw(ROW_GAME + 1, 107,  "000       000");
    mvprintw(ROW_GAME + 2, 107,  "000       000");
    mvprintw(ROW_GAME + 3, 107,  "000       000");
    mvprintw(ROW_GAME + 4, 107,  "0000000000000");
    mvprintw(ROW_GAME + 5, 107,  "          000");
    mvprintw(ROW_GAME + 6, 107,  "          000");
    mvprintw(ROW_GAME + 7, 107,  "          000");
    mvprintw(ROW_GAME + 8, 107,  "          000");
    return;
}

void setFive(void) {
    mvprintw(ROW_GAME, 107,      "0000000000000");
    mvprintw(ROW_GAME + 1, 107,  "0000000000000");
    mvprintw(ROW_GAME + 2, 107,  "000");
    mvprintw(ROW_GAME + 3, 107,  "000");
    mvprintw(ROW_GAME + 4, 107,  "0000000000000");
    mvprintw(ROW_GAME + 5, 107,  "          000");
    mvprintw(ROW_GAME + 6, 107,  "          000");
    mvprintw(ROW_GAME + 7, 107,  "0000000000000");
    mvprintw(ROW_GAME + 8, 107,  "0000000000000");
    return;
}

void setSix(void) {
    mvprintw(ROW_GAME, 107,      "0000000000000");
    mvprintw(ROW_GAME + 1, 107,  "0000000000000");
    mvprintw(ROW_GAME + 2, 107,  "000");
    mvprintw(ROW_GAME + 3, 107,  "000");
    mvprintw(ROW_GAME + 4, 107,  "0000000000000");
    mvprintw(ROW_GAME + 5, 107,  "000       000");
    mvprintw(ROW_GAME + 6, 107,  "000       000");
    mvprintw(ROW_GAME + 7, 107,  "0000000000000");
    mvprintw(ROW_GAME + 8, 107,  "0000000000000");
    return;
}

void setSeven(void) {
    mvprintw(ROW_GAME, 107,      "0000000000000");
    mvprintw(ROW_GAME + 1, 107,  "0000000000000");
    mvprintw(ROW_GAME + 2, 107,  "          000");
    mvprintw(ROW_GAME + 3, 107,  "          000");
    mvprintw(ROW_GAME + 4, 107,  "          000");
    mvprintw(ROW_GAME + 5, 107,  "          000");
    mvprintw(ROW_GAME + 6, 107,  "          000");
    mvprintw(ROW_GAME + 7, 107,  "          000");
    mvprintw(ROW_GAME + 8, 107,  "          000");
    return;
}
