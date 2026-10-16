#include <stdio.h>
#include "text.h"
#include "images.h"

const int gWidth = 120;
const int gheight = 22;

void menu();
void gameScreen();
void clearScreen();

int main(){
    clearScreen();
    menu();     
}

void menu(){
    int selection = 0;
    do
    {
        boxBorder(gWidth, gheight, 1, 1);
        titleImage();
        printText("[1] Play", 9, 14, 0, gWidth, 'c');
        printText("[2] Exit", 9, 15, 0, gWidth, 'c');
        printText("Choose wisely: ", 16, 17, 0, gWidth, 'c');

        changePos(17, 68);
        scanf("%d", &selection);
    } while (selection != 1 && selection != 2);
    if(selection == 1){
        gameScreen();
    }
    clearScreen();
}

void gameScreen(){

        clearScreen();

        boxBorder(gWidth, gheight, 1, 1);

        int line = 3;
        int col = 20;
        char arrText[] = "You have decided to begin a dangerous journey.\nThis dungeon is quite dangerous!\nLast Chance to leave!";
        char secText[] = "This is your last chance to turn back!!";
        int size = sizeof(arrText) / sizeof(arrText[0]);
        int secSize = sizeof(secText) / sizeof(secText[0]);
        changePos(line, col);
        printText(arrText, size, line, 6, gWidth, 'r');
        printText(secText, secSize, 5, 3, gWidth, 'l');

        while (1){}
}



