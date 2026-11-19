#include <stdio.h>
#include "player.h"
#include "text.h"
#include "navigation.h"

#define DELAY 0
#define MENU_MIN 1
#define MENU_MAX 5
// Richard Zoltowski

void movingChoice(Player *p, int usrImp, int wall){
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
            exitGame(p, wall);
            break;
	}
}

//Starting point: Bed
void wallOne(Player *p){
    int wall = 1;
    drawGameScreen(p, 1);
    //Check if the bed has been checked
    if(!p->progress_check[15]){
        printText("There is a Bed in front of you", 31, 5, DELAY, gWidth, 'c');
    //Check if oil has been used on lockbox
    } else if (!p->progress_check[10]){
        printText("You can see a Lockbox under the bed, but\nit is locked and the dial is stuck.", 77, 5, DELAY, gWidth, 'c');
    } else if (!p->progress_check[17]){
        printText("You can see a Lockbox under the bed with a combination dial.", 61, 5, DELAY, gWidth, 'c');
    } else {
        printText("You can see an opened Lockbox under the bed,\n"
            "but it is empty", 61, 5, DELAY, gWidth, 'c');
    }
    
    int choice = getInput(MENU_MIN, MENU_MAX);
    switch(choice){
        case 1:
            movingChoice(p, 4, wall);
            break;
        case 2:
            //If bed has not been interacted with before, then change progress status
            if(!p->progress_check[15]){
                progUpdate(p, 15);
                wallOne(p);
            //If oil has not been used, call function to let user know
            } else {
                wallOne(p);
            }
            
            break;
        case 3:
            movingChoice(p, 2, wall);
            break;
        case 4:
            useItemMenu(p, 1);
            break;
        case 5:
            movingChoice(p, 5, wall);
            break;
    }
}

//Starting point: workbench
void wallTwo(Player *p){ 
    int wall = 2;
    drawGameScreen(p, 1);
    //Determine that proper text to display based on progress
    //Sheet has not been removed
    if(!p->progress_check[3]){
        printText("There is a sheet covering something in front of you", 52, 5, DELAY, gWidth, 'c');
    //Sheet has been removed
    } else if (!p->progress_check[4]){
        printText("There is a workbech in front of you\nwith a Journal on it", 57, 5, DELAY, gWidth, 'c');
    //Journal has been picked up
    } else if (!p->progress_check[7]){
        printText("There is a workbench in front of you\nwith Cabinets", 51, 5, DELAY, gWidth, 'c');
    //Lockbox has been found
    } else if (!p->progress_check[8]){
        //Text if Small Brass Key has been used
        if(p->progress_check[10]){
            printText("There is a workbench in front of you with an unlocked toolbox on it.", 69, 5, DELAY, gWidth, 'c');
        //Small Brass Key has not been used
        } else {
            printText("There is an open cabinet in front of you with a toolbox in it.\nThe toolbox is locked.", 86, 5, DELAY, gWidth, 'c');
        }
    } else {
        printText("There is an open cabinet with an empty\n"
            "toolbox in front of you.", 64, 5, DELAY, gWidth, 'c');
    }
    int choice = getInput(MENU_MIN, MENU_MAX);
    switch(choice){
        case 1:
            movingChoice(p, 1, wall);
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
                //Update that workbench searched and Journal retrieved
                progUpdate(p, 4);
                progUpdate(p, 5);
                wallTwo(p);
            } else if (!p->progress_check[7]){
                //Update that cabinets searched
                progUpdate(p, 7);
                wallTwo(p);
            } else {
                wallTwo(p);
            }
            break;
        case 3:
            movingChoice(p, 3, wall);
            break;
        case 4:
            useItemMenu(p, 2);
            break;
        case 5:
            movingChoice(p, 5, wall);
            break;
    }
}

//Starting point: dresser
void wallThree(Player *p){
    int wall = 3;
    drawGameScreen(p, 1);
    //Determine that proper text to display based on progress
    //Dresser is closed
    if(!p->progress_check[11]){
        printText("There is a dresser in front of you.", 36, 5, DELAY, gWidth, 'c');
    //Dresser opened
    } else if (!p->progress_check[12]){
        printText("You open the dresser drawer and see clothing.", 46, 5, DELAY, gWidth, 'c');
    //Clothes have been moved
    } else if (!p->progress_check[13]){
        printText("You see a Small Brass Key under the clothing.", 47, 5, DELAY, gWidth, 'c');
    //Small Brass Key taken
    } else {
        printText("There is a dresser with the drawer open,\n"
            "but, there does not appear to be anything useful here.", 96, 5, DELAY, gWidth, 'c');
    } 
    int choice = getInput(MENU_MIN, MENU_MAX);
    switch(choice){
        case 1:
            movingChoice(p, 2, wall);
            break;
        case 2:
             if(!p->progress_check[11]){
                //Update to show drawer was opened
                progUpdate(p, 11);
                //Reload wall
                wallThree(p);
            } else if (!p->progress_check[12]){
                //Update that clothes were moved
                progUpdate(p, 12);
                wallThree(p);
            } else if (!p->progress_check[13]){
                //Update that Small Brass Key Obtained
                addItem(p, "Brass Key");
                progUpdate(p, 13);
                wallThree(p);
            } else {
                wallThree(p);
            }
            break;
        case 3:
            movingChoice(p, 4, wall);
            break;
        case 4:
            useItemMenu(p, 3);
            break;
        case 5:
            movingChoice(p, 5, wall);
            break;
    }
}

//Starting point: Painting
void wallFour(Player *p){
     int wall = 4;
    drawGameScreen(p, 1);
    //Determine that proper text to display based on progress
    //Crooked painting is hanging on wall
    if(!p->progress_check[0]){
        printText("There is a crooked painting on the wall.", 41, 5, DELAY, gWidth, 'c');
    //Painting has fallen
    } else if (!p->progress_check[1]){
        printText("The painting fell to the floor when you touched it.\n"
            "A fuse box is now visible, but it seems one of the\n"
            "switches is turned off.", 127, 5, DELAY, gWidth, 'c');
    //Fuse switched on
    } else if (!p->progress_check[17]){
        printText("When you flipped the fuse, the lights turned\n"
            "on! There is a locked door to the outside.", 88, 5, DELAY, gWidth, 'c');
    }
    int choice = getInput(MENU_MIN, MENU_MAX);
    switch(choice){
        case 1:
            movingChoice(p, 3, wall);
            break;
        case 2:
            if(!p->progress_check[0]){
                //Update to show painting fell
                progUpdate(p, 0);
                //Reload wall
                wallFour(p);
            } else if (!p->progress_check[1]){
                //Update to show fuse turned on and lights on
                progUpdate(p, 1);
                progUpdate(p, 2);
                wallFour(p);
            } else {
                wallFour(p);
            }
        case 3:
            movingChoice(p, 1, wall);
            break;
        case 4:
            useItemMenu(p, 4);
            break;
        case 5:
            movingChoice(p, 5, wall);
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

void menu(){
    boxBorder(gWidth, gheight, 1, 1);
    titleImage();
    printText("[1] Play", 9, 14, 0, gWidth, 'c');
    printText("[2] Exit", 9, 15, 0, gWidth, 'c');
    int selection = getInput(1, 2);
    if(selection == 1){
        initGame();
    }
    clearScreen();
}

void gameComplete(Player *p){
    char selection = 'a';
    clearScreen();
    boxBorder(gWidth, gheight, 1, 1);
    printText("CONGRATULATIONS!\n"
        "You Escaped the Room!", 39, gheight / 2, DELAY, gWidth, 'c');
    printText("Press Enter to Continue", 24, (gheight / 2) + 3, 0, gWidth, 'c');
    do{
        scanf("%c", &selection);
    } while (selection != '\n');
    free(p);
    menu();
}

void useItemMenu(Player *p, int wall){
    int i;
    int boxH = 10;
    int boxW = 20;
    int startLine = (gheight / 2) - (boxH / 2);
    int startCol = (gWidth / 2) - (boxW / 2);
    int selection = 0;
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
    //selection = getInput(1, 6);
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
            movingChoice(p, wall, wall);
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
        printText("Invalid Selection.", 19, gheight / 2, DELAY, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if(strcmp(p->items[index], "Journal") == 0){
        //Journal can be read anywhere as long as lights are on
        if(p->progress_check[2]){
            rmItem(p, "Journal");
            drawGameScreen(p, 0);
            progUpdate(p, 6);
            addItem(p, "Code");
            printText("You are able to read the Journal, which has\na numerical code written in it", 76, gheight / 2, DELAY, gWidth, 'c');
            printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
            do{
                scanf("%c", &selection);
            } while (selection != '\n');
        } else {
            drawGameScreen(p, 0);
            printText("It is too dark to read the Journal", 35, gheight / 2, DELAY, gWidth, 'c');
            printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
            do{
                scanf("%c", &selection);
            } while (selection != '\n');
        }
    } else if (strcmp(p->items[index], "Oil") == 0 && !p->progress_check[10] && wall == 1) {
        //Check that oil has been used on lockbox and that Player is one wall 1
        //Handle use of oil
        rmItem(p, "Oil");
        drawGameScreen(p, 0);
        progUpdate(p, 10);
        printText("The oil loosens the dial\n"
            "on the lockbox.", 41, gheight / 2, DELAY, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if (strcmp(p->items[index], "Code") == 0 && p->progress_check[10] && wall == 1) {
        //Check that oil has been used on lockbox and that Player is one wall 1
        //Handle use of oil
        rmItem(p, "Code");
        addItem(p, "Key");
        drawGameScreen(p, 0);
        progUpdate(p, 16);
        printText("The code unlocks the lockbox.\n"
            "You find a large Key inside", 58, gheight / 2, DELAY, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if (strcmp(p->items[index], "Brass Key") == 0 && p->progress_check[7] && wall == 2){
        //Check that toolbox has been discovered and that player is on wall 2
        rmItem(p, "Brass Key");
        addItem(p, "Oil");
        drawGameScreen(p, 0);
        progUpdate(p, 14);
        progUpdate(p, 8);
        progUpdate(p, 9);
        printText("You use the Small Brass Key on the toolbox and it unlocks.\n"
            "You find a Small Brass Key inside.", 59, gheight / 2, DELAY, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if (strcmp(p->items[index], "Key") == 0 && wall == 4) {
        gameComplete(p);
    } else {
        drawGameScreen(p, 0);
        printText("You cannot use that item here.", 31, gheight / 2, DELAY, gWidth, 'c');
        printText("Press Enter to Continue", 24, (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    }
    movingChoice(p, wall, wall);
}