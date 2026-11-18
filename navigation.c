#include <stdio.h>
#include "navigation.h"

// Richard Zoltowski

void movingChoice(Player *p, int usrImp){
	switch (usrImp){
		case 1: //Wall 1
			wallOne(p);			
			break;
		case 2: //Wall 2
			wallTwo(p);
			break;	
		case 3: //Wall 3
			wallThree(p);
			break;
		case 4: //Wall 4
			wallFour(p);
			break;		
	}
}

void introScene(Player *p){
    drawGameScreen(p);
    int choice = getInput();
    changePos(11, 50);
    printf("Welcome, %s", p->name);
    movingChoice(p, choice);
}

void wallOne(Player *p){
    drawGameScreen(p);
    printText("Viewing Wall One", 17, 5, 4, gWidth, 'c');
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 4);
            break;
        case 3:
            movingChoice(p, 2);
            break;
    }
}

void wallTwo(Player *p){ 
    drawGameScreen(p);
    printText("Viewing Wall Two", 17, 5, 4, gWidth, 'c');
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 1);
            break;
        case 3:
            movingChoice(p, 3);
            break;
    }
}

void wallThree(Player *p){
    drawGameScreen(p);
    printText("Viewing Wall Three", 19, 5, 4, gWidth, 'c');
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 2);
            break;
        case 3:
            movingChoice(p, 4);
            break;
    }
}

void wallFour(Player *p){
    drawGameScreen(p);
    printText("Viewing Wall Four", 18, 5, 4, gWidth, 'c');
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 3);
            break;
        case 3:
            movingChoice(p, 1);
            break;
    }
}