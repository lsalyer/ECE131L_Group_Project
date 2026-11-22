#include <stdio.h>
#include "ui.h"
#include "logic.h"
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
    printWallOne(p);
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
            } else if (!p->progress_check[16]){
                progUpdate(p, 16);
                wallOne(p);
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
    printWallTwo(p);
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
                //Update that workbench is uncluttered   
                addItem(p, "Journal");
                progUpdate(p, 5);            
                progUpdate(p, 4);
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
    printWallThree(p);
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
    printWallFour(p);
    int choice = getInput(MENU_MIN, MENU_MAX);
    switch(choice){
        case 1:
            movingChoice(p, 3, wall);
            break;
        case 2:
            if(!p->progress_check[0]){
                //Update to show painting fell
                paintingFalling(p);
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
    fgets(name, MAX_NAME, stdin);
    Player *p1 = createPlayer(name);
    introScene(p1);
}

void menu(){
    boxBorder(gWidth, gheight, 1, 1);
    titleImage();
    int line = 14;
    char optionOne[] = "[1] Play";
    char optionTwo[] = "[2] Load"; 
    char optionThree[] = "[3] Exit";
    printText(optionOne, strlen(optionOne), line++, 0, gWidth, 'c');
    printText(optionTwo, strlen(optionTwo), line++, 0, gWidth, 'c');
    printText(optionThree, strlen(optionThree), line, 0, gWidth, 'c');
    int selection = getInput(1, 3);
    if(selection == 1){
        initGame();
    } else if (selection == 2){
        loadMenu();
    } else {
        exit(EXIT_SUCCESS);
    }
    clearScreen();
}


void loadMenu(){
    clearScreen();
    boxBorder(gWidth, gheight, 1, 1);
    boxBorder((gWidth / 2), (gheight / 2), (gheight / 4), (gWidth / 4));
    loadGameDialog();
    int selection = getInput(1, 4);
    //char filename[] = {'s', 'a', 'v', 'e', (char)selection, '.', 'd', 'a', 't'};
    if (selection == 1){
        Player *p = loadGame("save1.dat");
        if(p == NULL){
            loadFailureDialog();
        } else {
           movingChoice(p, 1, 1); 
        }
    } else if (selection == 2){
        Player *p = loadGame("save2.dat");
        if(p == NULL){
            loadFailureDialog();
        } else {
           movingChoice(p, 1, 1); 
        } 
    } else if (selection == 3){
        Player *p = loadGame("save3.dat");
        if(p == NULL){
            loadFailureDialog();
        } else {
           movingChoice(p, 1, 1); 
        } 
    } else if(selection == 4){
        menu();
    }
}

void saveMenu(Player *p, int wall){
    clearScreen();
    boxBorder(gWidth, gheight, 1, 1);
    boxBorder((gWidth / 2), (gheight / 2), (gheight / 4), (gWidth / 4));
    saveGameDialog();
    bool saveStatus;
    int savePos = getInput(1, 4);
    if (savePos == 1){
        saveStatus = saveGame(p, "save1.dat");
    } else if(savePos == 2){
        saveStatus = saveGame(p, "save2.dat");
    } else if(savePos == 3){
        saveStatus = saveGame(p, "save3.dat");
    } else {
        movingChoice(p, 1, 1);
    }
    if(saveStatus == true){
        saveSuccessDialog(p);
        char choice = 'a'; 
        while(tolower(choice) != '\n'){
            changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
            printf("  ");
            changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
            scanf("%c", &choice);
        }
        free(p);
        menu();
    } else {
        saveFailureDialog(p);
        char choice = 'a'; 
        while(tolower(choice) != '\n'){
            changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
            printf("  ");
            changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
            scanf("%c", &choice);
        }
        movingChoice(p, wall, wall);
    }
}

void gameComplete(Player *p){
    char selection = 'a';
    gameCompleteDialog(p);
    
    do{
        scanf("%c", &selection);
    } while (selection != '\n');
    free(p);
    menu();
}

void useItemMenu(Player *p, int wall){
    int i;
    int boxHitem = 10;
    int boxWitem = 20;
    int startLine = (gheight / 2) - (boxHitem / 2);
    int startCol = (gWidth / 2) - (boxWitem / 2);
    int selection = 0;
    //int numI = numItems(p);
    clearScreen();
    boxBorder(gWidth, gheight, 1, 1);
    userInfo(p);
    boxBorder(boxWitem, boxHitem, startLine, startCol);

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

    movingChoice(p, wall, wall);
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
        char text[] = "Invalid Selection.";
        char command[] = "Press Enter to Continue";
        printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
        printText(command, strlen(command), (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if(strcmp(p->items[index], "Journal") == 0){
        //Journal can be read anywhere as long as lights are on
        if(p->progress_check[2]){
            rmItem(p, "Journal");
            progUpdate(p, 6);
            addItem(p, "Code");
            drawGameScreen(p, 0);
            readJournalDialog1(p);
            readJournalDialog2(p);
            readJournalDialog3(p);
        } else {
            drawGameScreen(p, 0);
            char text[] = "It is too dark to read the Journal";
            char command[] = "Press Enter to Continue";
            printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
            printText(command, strlen(command), (gheight / 2) + 2, 0, gWidth, 'c');
            do{
                scanf("%c", &selection);
            } while (selection != '\n');
        }
    } else if (strcmp(p->items[index], "Oil") == 0 && !p->progress_check[10] && wall == 1) {
        //Check that oil has been used on lockbox and that Player is one wall 1
        //Handle use of oil
        rmItem(p, "Oil");
        progUpdate(p, 10);
        drawGameScreen(p, 0);
        char text[] = "You oil the locking mechanism...\n"
            "It spins freely. Good as new!";
        char command[] = "Press Enter to Continue";
        printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
        printText(command, strlen(command), (gheight / 2) + 3, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if (strcmp(p->items[index], "Code") == 0 && p->progress_check[10] && wall == 1) {
        //Check that oil has been used on lockbox and that Player is one wall 1
        //Handle use of oil
        rmItem(p, "Code");
        addItem(p, "Key");
        progUpdate(p, 18);
        drawGameScreen(p, 0);
        char text[] = "You spin the dial using the numbers.\n"
            "in the code. The box pops open...\n"
            "The box contains a large key!";
        char command[] = "Press Enter to Continue";
        printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
        printText(command, strlen(command), (gheight / 2) + 4, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if (strcmp(p->items[index], "Brass Key") == 0 && p->progress_check[7] && wall == 2){
        //Check that toolbox has been discovered and that player is on wall 2
        rmItem(p, "Brass Key");
        addItem(p, "Oil");
        progUpdate(p, 14);
        progUpdate(p, 9);
        drawGameScreen(p, 0);
        char text[] = "You use the Small Brass Key on the toolbox.\n" 
            "The lock pops open!\n"
            "There is a small bottle of oil inside.";
        char command[] = "Press Enter to Continue";
        printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
        printText(command, strlen(command), (gheight / 2) + 4, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    } else if (strcmp(p->items[index], "Key") == 0 && wall == 4) {
        gameComplete(p);
    } else {
        drawGameScreen(p, 0);
        char text[] = "You cannot use that item here.";
        char command[] = "Press Enter to Continue";
        printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
        printText(command, strlen(command), (gheight / 2) + 2, 0, gWidth, 'c');
        do{
            scanf("%c", &selection);
        } while (selection != '\n');
    }
    movingChoice(p, wall, wall);
}
