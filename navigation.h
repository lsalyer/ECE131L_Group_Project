#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "text.h"

void useItemMenu(Player *p, int wall);
void useItem(Player *p, int index, int wall);
void movingChoice(Player *p, int usrImp);
void wallOne(Player *p);
void wallTwo(Player *p);
void wallThree(Player *p);
void wallFour(Player *p);
void initGame();

#endif