#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"
#include "text.h"
#include "navigation.h"

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
    while(p->items[i] != ""){
        i++;
    }

    return i;
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
17      | Key
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