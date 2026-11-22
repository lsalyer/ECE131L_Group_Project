#include "ui.h"
#include "logic.h"

void printWallOne(Player *p){
    if(!p->progress_check[15]){
        bedImage();
        char text[] = "There is a bed against this wall.\n" 
        "The sheets hang off the side all the way to\n"
        "floor.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    //Check if oil has been used on lockbox
    } else if (!p->progress_check[16]){
        lockboxImage();
        char text[] = "You moved the sheet, but it is so dark.\n" 
        "It seems as though something is just barely\n"
        "visible under the bed.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    } else if (!p->progress_check[10]){
        lockboxImage();
        char text[] = "You pulled a small lockbox out from under\n"
                      "the bed. It requires a a code to unlock it,\n"
                      "but the dial won't turn.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    } else if(!p->progress_check[17]){
        lockboxImage();
        char text[] = "You oiled the dial on the small lockbox and\n"
                      "the dial spins freely. But, it requires\n"
                      "a code to unlock it.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    } else {
        lockboxImage();
        char text[] = "You can see an opened Lockbox under the bed,\n"
            "but it is empty";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    }
}

void printWallTwo(Player *p){
    if(!p->progress_check[3]){
        char text[] = "There is a sheet covering something in front of you.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    //Sheet has been removed
    } else if (!p->progress_check[4]){
        char text[] = "You removed the dusty sheet.\n"
            "Underneath the sheet is a cluttered\n"
            "workbench with cabinets underneath it.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    } else if(!p->progress_check[7]){
        char text[] = "You cleared off the clutter on the\n"
            "workbench and found a journal. You see\n"
            "cabinets underneath the workbench.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    } else if (!p->progress_check[8]){
        //Text if Small Brass Key has been used
        if(!p->progress_check[14]){
            toolboxImage();
            char text[] = "The cabinet gave a loud creak as you opened\n"
                "it. Inside you found a toolbox, which you put\n"
                "on the workbench in front of you. The\n"
                "toolbox has a small lock which looks\n"
                "like it takes a key.";
            printText(text, strlen(text), 5, DELAY, gWidth, 'c');
        }
    } else {
        char text[] = "There is a workbench in front of you that has\n"
            "an open cabinet underneath, but you see nothing\n"
            "useful here.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    }
}

void printWallThree(Player *p){
    if(!p->progress_check[11]){
        dresserImage();
        char text[] = "You see a dresser in front of you\n"
        "against the wall.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    //Dresser opened
    } else if (!p->progress_check[12]){
        char text[] = "You open the dresser drawer and see\n"
        "a pile of clothing inside.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    //Clothes have been moved
    } else if (!p->progress_check[13]){
        char text[] = "You sift through the clothing in the drawer\n"
        "and see a Small Brass Key!";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    //Small Brass Key taken
    } else {
        char text[] = "There is a dresser with the drawer open,\n"
            "but, it just contains some tighty whiteys\n"
            "and other clothes.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    } 
}

void printWallFour(Player *p){
        if(!p->progress_check[0]){
        paintingImage();
        char text[] = "You face a wall with a crooked\n"
        "painting hanging on it.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    //Painting has fallen
    } else if (!p->progress_check[1]){
        fuseBoxImage();
        char text[] = "The painting fell to the floor when you touched it,\n"
            "revealing a fuse box! It appears one of the\n"
            "fuses has been turned off.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    //Fuse switched on
    } else {
        char text[] = "When you flipped the fuse, the lights turned\n"
            "on! There is a locked door to the outside.";
        printText(text, strlen(text), 5, DELAY, gWidth, 'c');
    }
}

void paintingFalling(Player *p){
    int delay = 400000000;
    drawGameScreen(p, 0);
    char text[] = "You attempt to straighten the painting.";
    printText(text, strlen(text), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text2[] = "... ... ... CRASH!";
    printText(text2, strlen(text2), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
}

void introScene(Player *p){
    int delay = 400000000;
    drawGameScreen(p, 0);
    char text[] = "... ... ...";
    printText(text, strlen(text), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text2[] = "... ... ...!";
    printText(text2, strlen(text2), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text3[] = "You wake up in bed,\n"
        "in a darkened room...";
    printText(text3, strlen(text3), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text4[] = "You crawl out of your bed.\n"
        "Your body hurts...";
    printText(text4, strlen(text4), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text5[] = "You look around the darkened room.\n"
        "You can't see very well...";
    printText(text5, strlen(text5), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    char prompt[] = "Press enter to continue...";
    printText(prompt, strlen(prompt), (gheight / 2) - (boxH / 2) + 5, 0, gWidth, 'c');
    char choice = 'a';
    while(tolower(choice) != '\n'){
        changePos((gheight / 2) - (boxH / 2) + 5, (gWidth / 2) + 14);
        printf("  ");
        changePos((gheight / 2) - (boxH / 2) + 5, (gWidth / 2) + 14);
        scanf("%c", &choice);
    }
    movingChoice(p, 3, 3);
}

void printExitDialog(Player *p){
    drawGameScreen(p, 0);
    boxBorder(boxW, boxH, (gheight / 2) - (boxH / 2), (gWidth / 2) - (boxW / 2));
    char text[] = "Do you want to save your progress?\n(Y/N):";
    printText(text, strlen(text), (gheight / 2) - (boxH / 2) + 2, 0, gWidth, 'c');
}

void saveSuccessDialog(Player *p){
    drawGameScreen(p, 0);
    boxBorder(boxW, boxH, (gheight / 2) - (boxH / 2), (gWidth / 2) - (boxW / 2));
    char text[] = "Your game was saved successfully\nPress Enter to Exit to menu";
    printText(text, strlen(text), (gheight / 2) - (boxH / 2) + 2, 0, gWidth, 'c');
}

void saveFailureDialog(Player *p){
    drawGameScreen(p, 0);
    boxBorder(boxW, boxH, (gheight / 2) - (boxH / 2), (gWidth / 2) - (boxW / 2));
    char text[] = "Your game failed to save\nPress Enter to Return to game";
    printText(text, strlen(text), (gheight / 2) - (boxH / 2) + 2, 0, gWidth, 'c');
}

void loadFailureDialog(){
    clearScreen();
    boxBorder(gWidth, gheight, 1, 1);
    boxBorder((gWidth / 2), (gheight / 2), (gheight / 4), (gWidth / 4));
    boxBorder(boxW, boxH, (gheight / 2) - (boxH / 2), (gWidth / 2) - (boxW / 2));
    char text[] = "Your game failed to save\nPress Enter to Return to menu";
    printText(text, strlen(text), (gheight / 2) - (boxH / 2) + 2, 0, gWidth, 'c');
    char choice = 'a'; 
    while(tolower(choice) != '\n'){
        changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
        printf("  ");
        changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
        scanf("%c", &choice);
    }
    menu();
}

void loadGameDialog(){
    Player *p1 = loadGame("save1.dat");
    Player *p2 = loadGame("save2.dat");
    Player *p3 = loadGame("save3.dat");
    changePos((gheight / 4) + 1, (gWidth / 4) + 2);
    char text[] = "Choose a saved game to load";
    printText(text, strlen(text), (gheight / 4) + 1, 0, gWidth, 'c');
    /*for(int i = 1; i < 4; i++){
        char filename[10];
        Player *p = loadGame(getFilename(i));
        changePos((gheight / 4) + 2, (gWidth / 4) + (i * 2));
        if(p == NULL){
            printf("[%d] Empty", i);
        } else {
            printf("[%d] %s", i, p->name);
            free(p);
        }
    }*/
    if (p1 == NULL) {
        changePos((gheight / 4) + 2, (gWidth / 4) + 2);
        printf("[1] Empty");
    } else {
        changePos((gheight / 4) + 2, (gWidth / 4) + 2);
        printf("[1] %s", p1->name);
        free(p1);
    }
    if (p2 == NULL) {
        changePos((gheight / 4) + 4, (gWidth / 4) + 2);
        printf("[2] Empty");
    } else {
        changePos((gheight / 4) + 4, (gWidth / 4) + 2);
        printf("[2] %s", p2->name);
        free(p2);
    }
    if (p3 == NULL) {
        changePos((gheight / 4) + 6, (gWidth / 4) + 2);
        printf("[3] Empty");
    } else {
        changePos((gheight / 4) + 6, (gWidth / 4) + 2);
        printf("[3] %s", p3->name);
        free(p3);
    }
    changePos((gheight / 4) + 10, (gWidth / 4) + 2);
    printf("[4] Exit");
}

void saveGameDialog(){
    Player *p1 = loadGame("save1.dat");
    Player *p2 = loadGame("save2.dat");
    Player *p3 = loadGame("save3.dat");
    changePos((gheight / 4) + 1, (gWidth / 4) + 2);
    char text[] = "Choose a position to save your game";
    printText(text, strlen(text), (gheight / 4) + 1, 0, gWidth, 'c');
    if (p1 == NULL) {
        changePos((gheight / 4) + 2, (gWidth / 4) + 2);
        printf("[1] Empty");
    } else {
        changePos((gheight / 4) + 2, (gWidth / 4) + 2);
        printf("[1] %s", p1->name);
        free(p1);
    }
    if (p2 == NULL) {
        changePos((gheight / 4) + 4, (gWidth / 4) + 2);
        printf("[2] Empty");
    } else {
        changePos((gheight / 4) + 4, (gWidth / 4) + 2);
        printf("[2] %s", p2->name);
        free(p2);
    }
    if (p3 == NULL) {
        changePos((gheight / 4) + 6, (gWidth / 4) + 2);
        printf("[3] Empty");
    } else {
        changePos((gheight / 4) + 6, (gWidth / 4) + 2);
        printf("[3] %s", p3->name);
        free(p3);
    }
    char warning[] = "WARNING: THIS WILL OVERWRITE A CURRENT SAVED GAME";
    printText(warning, strlen(warning), (gheight / 4) + 8, 0, gWidth, 'c');
    changePos((gheight / 4) + 10, (gWidth / 4) + 2);
    printf("[4] Exit");
}

void removeSheetDialog(Player *p){
    clearScreen();
    drawGameScreen(p, 0);
    char text[] = "You removed the dusty sheet.\n"
        "Underneath the sheet is a cluttered\n"
        "workbench with cabinets underneath it.";
    printText(text, strlen(text), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    char choice = 'a'; 
    while(tolower(choice) != '\n'){
        changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
        printf("  ");
        changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
        scanf("%c", &choice);
    }
}

void readJournalDialog1(Player *p){
    clearScreen();
    drawGameScreen(p, 0);
    char text[] = "You try to read the Journal.\n"
        "A three digit code is scribbled on the first page.\n"
        "Many of the entries are unreadable...";
    char command[] = "Press Enter to Continue";
    printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
    printText(command, strlen(command), (gheight / 2) + 3, 0, gWidth, 'c');
    char selection = 'a';
    do{
        scanf("%c", &selection);
    } while (selection != '\n');
}

void readJournalDialog2(Player *p){
    clearDialog();
    char text[] = "\"...I regret what I've done, these experiments\"\n"
        "\"have made a horrible creation...\"";
    char command[] = "Press Enter to Continue";
    printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
    printText(command, strlen(command), (gheight / 2) + 3, 0, gWidth, 'c');
    char selection = 'a';
    do{
        scanf("%c", &selection);
    } while (selection != '\n');
}

void readJournalDialog3(Player *p){
    clearDialog();
    char text[] = "\"...All of my work, since 1986, culminated\"\n"
        "\"in this...My, what a waste...\"\n"
        "\n"
        "\"...I need to destroy it, I cannot let anyone find it...\"\n"\
        "\"Then, I will get into the basket weaving trade..\"";
    char command[] = "Press Enter to Continue";
    printText(text, strlen(text), gheight / 2, DELAY, gWidth, 'c');
    printText(command, strlen(command), (gheight / 2) + 6, 0, gWidth, 'c');
    char selection = 'a';
    do{
        scanf("%c", &selection);
    } while (selection != '\n');
}

void gameCompleteDialog(Player *p){
    int delay = 400000000;
    clearScreen();
    drawGameScreen(p, 0);
    char text[] = "You put the large key into the\n"
                "lock on the door...";
    printText(text, strlen(text), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text2[] = "...CLICK!";
    printText(text2, strlen(text2), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text3[] = "You push open the door...\n"
        "Daylight shines on your face...";
    printText(text3, strlen(text3), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text4[] = "You are FREE!!!!";
    printText(text4, strlen(text4), (gheight / 2) - (boxH / 2) + 2, 3, gWidth, 'c');
    for(int a = 0; a < delay * 2; a++){}
    char text5[] = "**low growling**";
    printText(text5, strlen(text5), (gheight / 2) - (boxH / 2) + 4, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text6[] = "What??            \n"
            "How...               \n"
            "\n"
            "did you get out??";
    printText(text6, strlen(text6), (gheight / 2) - (boxH / 2) + 2, 6, gWidth, 'c');
    for(int a = 0; a < delay; a++){}
    clearDialog();
    char text7[] = "THE END";
    printText(text7, strlen(text7), (gheight / 2) - (boxH / 2) + 2, 15, gWidth, 'c');
}

void clearDialog(){
    printText("                                                \n"
            "                                                \n"
            "                                                \n"
            "                                                \n"
            "                                                \n"
            "                                                 ", 
        295, (gheight / 2) - (boxH / 2) + 1, 0, gWidth, 'c');
}