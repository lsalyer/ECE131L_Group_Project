#ifndef TEXT_H
#define TEXT_H

#define gWidth 120
#define gheight 22

#include "player.h"

void clearScreen();
void userInfo(Player *p);
void printText(char arr[], int size, int line, int del, int w, char a);
void borderTop(int w, int h, int line, int col);
void borderSides(int w, int h, int line, int col);
void borderBottom(int w, int h, int line, int col);
void boxBorder(int w, int h, int line, int col);
void changePos(int line, int col);
int alignCenter(char arr[], int size, int w);
int alignRight(char arr[], int size, int w);
int alignLeft(char arr[], int size, int w);
int getAlignment(char arr[], int size, int w, char a);
int numLines(char arr[], int size);
int nextLine(char arr[], int size, int start);
void clearBuffer();
void gameMenu();
int getInput();
void drawGameScreen(Player *p);
int progressNum(Player *p);

#endif