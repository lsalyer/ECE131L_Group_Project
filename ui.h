#ifndef UI_H
#define UI_H
#include "logic.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define gWidth 120
#define gheight 22
#define boxH 4
#define boxW 38

void titleImage();
void fuseBoxImage();
void paintingImage();
void dresserImage();
void toolboxImage();
void bedImage();
void lockboxImage();
void clearScreen();
void clearDialog();
void gameCompleteDialog(Player *p);
void paintingFalling(Player *p);
void readJournalDialog1(Player *p);
void readJournalDialog2(Player *p);
void readJournalDialog3(Player *p);
void introScene(Player *p);
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
int getInput(int min, int max);
void drawGameScreen(Player *p, int withMenu);
int progressNum(Player *p);
void printWallOne(Player *p);
void printWallTwo(Player *p);
void printWallThree(Player *p);
void printWallFour(Player *p);
void printExitDialog(Player *p);
void saveSuccessDialog(Player *p);
void saveFailureDialog(Player *p);
void loadGameDialog();
void saveGameDialog();
void saveMenu(Player *p, int wall);
void loadFailureDialog();

#endif