#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "ui.h"

#define DELAY 4
#define MENU_MIN 1
#define MENU_MAX 5
#define NUM_CHECK 18
#define MAX_LEN 10
#define MAX_ITEM 5
#define MAX_NAME 20
#define SAVE_FILE "save.dat"

typedef struct {
    char name[MAX_NAME];
    bool progress_check[NUM_CHECK];
    char items[MAX_ITEM][MAX_LEN]; //First bracket is the the amount of Items. The second is the max len of char.    
} Player;

void useItemMenu(Player *p, int wall);
void useItem(Player *p, int index, int wall);
void movingChoice(Player *p, int usrImp, int wall);
void wallOne(Player *p);
void wallTwo(Player *p);
void wallThree(Player *p);
void wallFour(Player *p);
void gameComplete(Player *p);
void menu();
void loadMenu();
void initGame();
bool saveGame(const Player *p, char filename[]);
Player* loadGame(char filename[]);
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
int tasksComplete(Player *p);
void exitGame(Player *p, int wall);
//bool saveGame(const Player *p);
//Player* loadGame(int number)

#endif