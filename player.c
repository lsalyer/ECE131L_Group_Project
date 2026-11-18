#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"

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