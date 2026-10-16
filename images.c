#include <stdio.h>
#include "text.h"
#include "images.h"

void titleImage(){
    int size = 56;
    int line = 8;
    printText("  ____                        _____ _ _   _           \n", size, line++, 0, 120, 'c');
    printText(" / ___| __ _ _ __ ___   ___  |_   _(_) |_| | ___      \n", size, line++, 0, 120, 'c');
    printText("| |  _ / _` | '_ ` _ \\ / _ \\   | | | | __| |/ _ \\     \n", size, line++, 0, 120, 'c');
    printText("| |_| | (_| | | | | | |  __/   | | | | |_| |  __/     \n", size, line++, 0, 120, 'c');
    printText(" \\____|\\__,_|_| |_| |_|\\___|   |_| |_|\\__|_|\\___|     \n", size, line++, 0, 120, 'c');
}