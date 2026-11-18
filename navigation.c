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
    drawGameScreen(p, 1);
    int choice = getInput();
    changePos(11, 50);
    printf("Welcome, %s", p->name);
    movingChoice(p, choice);
}

//Starting point: Bed
void wallOne(Player *p){
    drawGameScreen(p, 1);
    //Check if the bed has been checked
    if(!p->progress_check[15]){
        printText("There is a Bed in front of you", 31, 5, 4, gWidth, 'c');
    //Check if oil has been used on lockbox
    } else if (!p->progress_check[10]){
        printText("You can see a Lockbox under the bed, but it is locked and the dial is stuck.", 77, 5, 4, gWidth, 'c');
    }
    
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 4);
            break;
        case 2:
            //If bed has not been interacted with before, then change progress status
            if(!p->progress_check[15]){
                progUpdate(p, 15);
                wallOne(p);
            //If oil has not been used, call function to let user know
            } else if (!p->progress_check[10]){
                //Go to lockbox function
            //If oil has been used, update status to get key
            } else if (p->progress_check[10]){
                //Function to get key
            }
            
            break;
        case 3:
            movingChoice(p, 2);
            break;
        case 4:
            useItemMenu(p, 2);
            break;
        case 5:
            movingChoice(p, 5);
            break;
    }
}

//Starting point: workbench
void wallTwo(Player *p){ 
    drawGameScreen(p, 1);
    //Determine that proper text to display based on progress
    //Sheet has not been removed
    if(!p->progress_check[3]){
        printText("There is a sheet covering something in front of you", 52, 5, 4, gWidth, 'c');
    //Sheet has been removed
    } else if (!p->progress_check[4]){
        printText("There is a workbech in front of you\nwith a Journal on it", 56, 5, 4, gWidth, 'c');
    //Journal has been picked up
    } else if (!p->progress_check[5]){
        printText("There is a workbench in front of you\nwith Cabinets", 49, 5, 4, gWidth, 'c');
    //Lockbox has been found
    } else if (!p->progress_check[8]){
        //Text if Small Brass Key has been used
        if(p->progress_check[10]){
            printText("There is a workbench in front of you with an unlocked toolbox on it.", 57, 5, 4, gWidth, 'c');
        //Small Brass Key has not been used
        } else {
            printText("There is a workbench in front of you with a toolbox on it.\nThe toolbox is locked.", 82, 5, 4, gWidth, 'c');
        } 
        
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
            } else if (!p->progress_check[15]){
                //Call lockbox function
            }
            break;
        case 3:
            movingChoice(p, 3);
            break;
        case 4:
            useItemMenu(p, 2);
            break;
        case 5:
            movingChoice(p, 5);
            break;
    }
}

//Starting point: dresser
void wallThree(Player *p){
    drawGameScreen(p, 1);
    printText("Viewing Wall Three", 19, 5, 4, gWidth, 'c');
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 2);
            break;
        case 3:
            movingChoice(p, 4);
            break;
        case 4:
            useItemMenu(p, 2);
            break;
        case 5:
            movingChoice(p, 5);
            break;
    }
}

//Starting point: Painting
void wallFour(Player *p){
    drawGameScreen(p, 1);
    printText("Viewing Wall Four", 18, 5, 4, gWidth, 'c');
    int choice = getInput();
    switch(choice){
        case 1:
            movingChoice(p, 3);
            break;
        case 3:
            movingChoice(p, 1);
            break;
        case 4:
            useItemMenu(p, 2);
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

void useItemMenu(Player *p, int wall){
    int selection = 0;
    int i;
    int boxH = 10;
    int boxW = 20;
    int startLine = (gheight / 2) - (boxH / 2);
    int startCol = (gWidth / 2) - (boxW / 2);
    //int numI = numItems(p);
    clearScreen();
    boxBorder(gWidth, gheight, 1, 1);
    userInfo(p);
    boxBorder(boxW, boxH, startLine, startCol);

    if(strcmp(p->items[0], "") == 0){
        printText("You do not have any items.", 27, startLine - 2, 0, gWidth, 'c');
    }
    for(i = 0; i < MAX_ITEM; i++){
        changePos(startLine + 1 + i, startCol + 1);
        printf("[%d] %s", i + 1, p->items[i]);
    }
    changePos(startLine + 2 + i, startCol + 1);
    printf("[%d] Close Menu", i + 1);

    while (selection < 1 || selection > 6){
        changePos(gheight - 3, (gWidth / 2) + 10);
        printf("    ");
        printText("Enter your selection: ", 23, gheight - 3, 0, gWidth, 'c');
        scanf("%d", &selection);
    }

    //Need to determine if selection is usable on the current wall
    switch(selection){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            useItem(p, selection - 1, wall);
            break;
        case 6:
            movingChoice(p, wall);
            break;
    }

    
}

void useItem(Player *p, int index, int wall){
    /*This function needs to compare the item being used 
    and the item it is supposed to be used on. It should also 
    make sure that the player is on the wall with the item
    that the selection needs to be used on*/
    clearBuffer();
    char selection = 'a';
    if(strcmp(p->items[index], "") == 0){
        drawGameScreen(p, 0);
        printText("Invalid Selection.", 19, gheight / 2, 4, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if(strcmp(p->items[index], "Journal") == 0){
        //Journal can be read anywhere as long as lights are on
        if(p->progress_check[2]){
            drawGameScreen(p, 0);
            progUpdate(p, 6);
            addItem(p, "Code");
            printText("You are able to read the Journal, which has\na four digit code written in it", 76, gheight / 2, 4, gWidth, 'c');
            printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
            do{
                scanf("%c", &selection);
            } while (selection != '\n');
        } else {
            drawGameScreen(p, 0);
            printText("It is too dark to read the Journal", 35, gheight / 2, 4, gWidth, 'c');
            printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
            do{
                scanf("%c", &selection);
            } while (selection != '\n');
        }
    } else if (strcmp(p->items[index], "Code") == 0 && p->progress_check[10] && wall == 1) {
        //Check that oil has been used on lockbox and that Player is one wall 1
        //Handle use of oil
        drawGameScreen(p, 0);
        progUpdate(p, 10);
        printText("You use the oil on the dial of the lockbox\nand it now spins freely.", 68, gheight / 2, 4, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if (strcmp(p->items[index], "Brass Key") == 0 && p->progress_check[8] && wall == 2){
        //Check that toolbox has been discovered and that player is on wall 2
        drawGameScreen(p, 0);
        progUpdate(p, 14);
        printText("You use the Small Brass Key on the toolbox and it unlocks.", 59, gheight / 2, 4, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else {
        drawGameScreen(p, 0);
        printText("You cannot use that item here.", 31, gheight / 2, 4, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    }
    movingChoice(p, wall);
}