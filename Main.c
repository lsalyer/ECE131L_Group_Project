#include <stdio.h>
#include "player.h"
#include "text.h"
#include "navigation.h"
#include "images.h"

void menu();

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
        
        //fgets(input, 10, stdin);
    } while (selection != 1 && selection != 2);
    if(selection == 1){
        clearBuffer();
        initGame();
    }
    clearScreen();
}

//Test screen
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
        printText(secText, secSize, 2, 3, gWidth, 'l');

        while (1){}
}







