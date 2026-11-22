#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui.h"
#include "logic.h"

void addItem(Player *p, char *s) {
    for (int i = 0; i < MAX_ITEM; i++) {
        int compare = strcmp(p->items[i], "");
        if (compare == 0) {
            strcpy(p->items[i], s);
            break;
        }
    }
}

void rmItem(Player *p, char *s) {
    for (int i = 0; i < MAX_ITEM; i++) {
        int compare = strcmp(p->items[i], s);
        if (compare == 0) {
            strcpy(p->items[i],"");
            break;
        }
        
    }
    
}

int numItems(Player *p){
    int i = 0;
    while(strcmp(p->items[i], "") != 0){
        i++;
    }

    return i;
}

int tasksComplete(Player *p){
    int complete = 0;
    for(int i = 0; i < NUM_CHECK; i++){
        if(p->progress_check[i] == true){
            complete++;
        }
    }
    return complete;
}

/*
Index   | Item Tracked
0       | Crooked Painting
1       | Fusebox
2       | Lights
3       | Sheet Covering
4       | Workbench
5       | Journal
6       | Journal Access
7       | Cabinets
8       | Toolbox
9       | Oil (item)
10      | Oil (used)
11      | Dresser
12      | Clothes
13      | Small Brass Key (item)
14      | Small Brass Key (used)
15      | Bed
16      | Lockbox
17      | Code
18      | Door Key
*/
void progUpdate(Player *p, int index) {
    p->progress_check[index] = true;
}


Player* createPlayer(char name[]) {
    //Allocate mem
    Player *pptr = malloc(sizeof(Player));
    if (pptr == NULL) {
        EXIT_FAILURE;
    }

    strcpy(pptr->name, name); //Takes the usrs name and passes string value to p1.name.
    
    // This loop turns all bools to false in p1.progress_check[]
    for (int i = 0; i < NUM_CHECK; i++) {
        pptr->progress_check[i] = false;
    }
    
    //Set the array of items to nothing (They are strings).
    for (int i = 0; i < MAX_ITEM; i++) {
        strcpy(pptr->items[i], ""); // We need to make this a 2D array because we need a amount of items and the names.
    }
    
    return pptr;
}

void exitGame(Player *p, int wall){
    char selection = 'a';
    printExitDialog(p);
    while(tolower(selection) != 'y' && tolower(selection) != 'n'){
        changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 15);
        printf("  ");
        changePos((gheight / 2) - (boxH / 2) + 3, (gWidth / 2) + 4);
        scanf("%c", &selection);
    }
    if(tolower(selection) == 'y'){
        saveMenu(p, wall);
    } else {
        free(p);
        menu();
    }
    
}

bool saveGame(const Player *p, char filename[]) {
    if (p == NULL) {
        return false;
    }
    
    FILE *file = fopen(filename, "wb"); //opens the text file called save.bat and writes in it in binary
    if (file == NULL) {
        return false;    
    }
    
    size_t written = fwrite(p, sizeof(Player), 1, file);
    fclose(file);

    return written == 1;
}

Player* loadGame(char filename[]) {
    Player *p = malloc(sizeof(Player));
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    } else {
        fread(p, sizeof(Player),  1, file);
        fclose(file);
    }

    return p;
}