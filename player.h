#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

#define NUM_CHECK 17
#define MAX_LEN 10
#define MAX_ITEM 5
#define MAX_NAME 20


typedef struct {
    char name[MAX_NAME];
    bool progress_check[NUM_CHECK];
    char items[MAX_ITEM][MAX_LEN]; //First bracket is the the amount of Items. The second is the max len of char.    
} Player;

// param player structure and string. search first blank and add item into that idex.
void addItem(Player *p, char *s); 
// prarm player struct and string. search for item then remove item from specific idex. 
void rmItem(Player *p, char *s);
// take integer from specific index and flips to true.
void progUpdate(Player *p, int index);
//usr input string name, creates progesscheck to false, and create array of string with nothing.
//journal, code, oil, small brass key, master key
Player* createPlayer(char name[]); 
int numItems(Player *p);

#endif