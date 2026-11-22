#include <stdio.h>
#include "ui.h"

void titleImage(){
    int size = 54;
    int line = 8;
    printText("______ __  __  ____    ____    ___     ___   ___  ___", size, line++, 0, gWidth, 'c');
    printText("| || | ||  || ||       || \\\\  // \\\\   // \\\\  ||\\\\//||", size, line++, 0, gWidth, 'c');
    printText("  ||   ||==|| ||==     ||_// ((   )) ((   )) || \\/ ||", size, line++, 0, gWidth, 'c');
    printText("  ||   ||  || ||___    || \\\\  \\\\_//   \\\\_//  ||    ||", size, line++, 0, gWidth, 'c');
    
}

void fuseBoxImage(){
    char text[] = ",--------,\n"
                  "|    --+ |\n"
                  "|    --+ |\n"
                  "| +--    |\n"
                  "| +--    |\n"
                  "'--------'";
    printText(text, strlen(text), (gheight / 2) - 3, 0, gWidth, 'l');
}

void paintingImage(){
    char text[] = "   .-'\\\n"     
                  ".-'    \\\n"    
                  "\\   \\\\  \\\n"   
                  " \\  \\\\\\  \\\n"  
                  "  \\  \\.\\--\\\n" 
                  "   \\.'   .-'\n"
                  "    \\_.-'   \n";
    printText(text, strlen(text), (gheight / 2) - 3, 0, gWidth, 'l');
}

void dresserImage(){
    char text[] = "----------\n"
                  " |,,,,,,| \n"
                  " |'````'| \n"
                  " |,,,,,,| \n"
                  " |'````'| \n"
                  " |------| \n";
    printText(text, strlen(text), (gheight / 2) - 3, 0, gWidth, 'l');
}

void toolboxImage(){
    char text[] = "    _______    \n"
                  ",---|-----|---,\n"
                  "|-----|^|-----|\n"
                  "|             |\n"
                  "'-------------'\n";
    printText(text, strlen(text), (gheight / 2) - 3, 0, gWidth, 'l');
}

void bedImage(){
    char text[] = "         |\n"
                  "|,,,,,,,,|\n"
                  "|````````|\n";
    printText(text, strlen(text), (gheight / 2) - 3, 0, gWidth, 'l');
}

void lockboxImage(){
    char text[] = ",-----------,\n"
                  "|-----------|\n"
                  "|   ,---,   |\n"
                  "|   '---'   |\n"
                  "'-----------'\n";
    printText(text, strlen(text), (gheight / 2) - 3, 0, gWidth, 'l');
}