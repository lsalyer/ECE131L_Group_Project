#include <stdio.h>
#include "player.h"
#include "text.h"
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
        case 5:
            EXIT_SUCCESS;
	}
}

void introScene(Player *p){
    drawGameScreen(p);
    int choice = getInput();
    changePos(11, 50);
    printf("Welcome, %s", p->name);
    movingChoice(p, choice);
}

//Starting point: Bed
void wallOne(Player *p){
    drawGameScreen(p);
    if(!p->progress_check[13]){
        printText("There is a Bed in front of you", 31, 5, 4, gWidth, 'c');
    } else if (!p->progress_check[14]){
        printText("You can see a Lockbox under the bed", 36, 5, 4, gWidth, 'c');
    }
    
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 4);
            break;
        case 2:
            if(!p->progress_check[13]){
                progUpdate(p, 13);
                wallOne(p);
            } else if (!p->progress_check[14]){
                //Go to lockbox function
            }
            
            break;
        case 3:
            movingChoice(p, 2);
            break;
        case 5:
            movingChoice(p, 5);
            break;
    }
}

//Starting point: Dresser
void wallTwo(Player *p){ 
    drawGameScreen(p);
    //Determine that proper text to display based on progress
    if(!p->progress_check[3]){
        printText("There is a sheet covering something in front of you", 52, 5, 4, gWidth, 'c');
    } else if (!p->progress_check[4]){
        printText("There is a dresser in front of you\nwith a Journal on it", 56, 5, 4, gWidth, 'c');
    } else if (!p->progress_check[5]){
        printText("There is a dresser in front of you\nwith Cabinets", 49, 5, 4, gWidth, 'c');
    } 
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 1);
            break;
        case 2:
            if(!p->progress_check[3]){
                //Update to show sheet has been removed
                progUpdate(p, 3);
                //Reload wall
                wallTwo(p);
            } else if (!p->progress_check[4]){
                //User gets Journal
                addItem(p, "Journal");
                //Update that Journal retrieved
                progUpdate(p, 4);
                wallTwo(p);
            } else if (!p->progress_check[5]){
                //Update that cabinets searched
                progUpdate(p, 5);
                wallTwo(p);
            }
            break;
        case 3:
            movingChoice(p, 3);
            break;
        case 5:
            movingChoice(p, 5);
            break;
    }
}

//Starting point: Workbench
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
        case 5:
            movingChoice(p, 5);
            break;
    }
}

//Starting point: Painting
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
        case 5:
            movingChoice(p, 5);
            break;
    }
}

void initGame(){
    clearScreen();
    boxBorder(gWidth, gheight, 1, 1);

    char name[MAX_NAME];
    boxBorder(36, 5, 8, 42);
    printText("Player Name:", 12, 10, 0, gWidth, 'c');
    changePos(11, 50);
    fgets(name, 30, stdin);
    Player *p1 = createPlayer(name);
    wallOne(p1);
}