#include <stdio.h>
#include "text.h"

//Parameters: Text array, size of array, line to being printing, delay, width of text area, and alignment (c)enter, (l)eft, or (r)ight
void printText(char arr[], int size, int line, int del, int w, char a){
    
    //Need to create parsing operator to handle size of each line or text i.e., \n
    int numL = numLines(arr, size);

    //If the input has more than one line, this section will process it
    if(numL > 1){
        //Start index is set to 0; Ending index is declared, but not set
        int start = 0, end;
        //Processes each line in order
        for(int i = 0; i < numL; i++){
            //Call function to determine the end of the first line
            end = nextLine(arr, size, start);
            //Change cursor position to give proper alignment as requested
            //We increment the line after usage and will get the appropriate starting position for each line using getAlignment function
            changePos(line++, getAlignment(arr, end - start, w, a));
            //Print the current line
            for(int j = start; j < end; j++){
                printf("%c", arr[j]);
                //Delay based on preference to give typing effect
                for(int a = 0; a < del * 10000000; a++){}
            }
            //We now set the start index to the index position after the current line's new line character
            start = ++end;
        }
    } else{
        //For one line of text, we simply move to the specified line and get the appropriate starting column to match alignment
        changePos(line, getAlignment(arr, size, w, a));
        for(int i = 0; i < size; i++){
            printf("%c", arr[i]);
            for(int a = 0; a < del * 10000000; a++){}
        }
    }
}

//Function to draw the top border of a box
void borderTop(int w, int h, int line, int col){
    changePos(line, col);
    for(int i = 0; i < w; i++){
        printf("_");
    }
    printf("\n");
}

//Function to draw the sides border of a box
void borderSides(int w, int h, int line, int col){
    for(int y = 0; y < h; y++){
        changePos(++line, col);
        printf("||");
        for(int i = 0; i < w - 4; i++){
            printf(" ");
        }
        printf("||\n");
    }
}

//Function to create the botom of a box
void borderBottom(int w, int h, int line, int col){
    changePos(line + h, col);
    printf("||");
    for(int i = 0; i < w - 4; i++){
        printf("_");
    }
    printf("||");
}

//Master function to create a custom box
void boxBorder(int w, int h, int line, int col){
    borderTop(w, h, line, col);
    borderSides(w, h, line, col);
    borderBottom(w, h, line, col);
}

//Function to change cursor position
void changePos(int line, int col){
    printf("\033[%d;%dH", line, col);
}

//Function to clear the current screen
void clearScreen(){
    printf("\033[0;0H");
    printf("\033[J");
}

//Parameters: Text array, array size, and width of box
int alignCenter(char arr[], int size, int w){
    int center = w / 2;
    int strHalf = size / 2;
    return center - strHalf;
}

//Calculate column for appropriate left text alignment
int alignLeft(char arr[], int size, int w){
    return w / 10;
}

//Calculate column for appropriate right text alignment
int alignRight(char arr[], int size, int w){
    return w - (w / 10) - size;
}

//Processes user alignment request and calls appropriate function
int getAlignment(char arr[], int size, int w, char a){
    switch(a){
        case 'c':
            return alignCenter(arr, size, w);
            break;
        case 'l':
            return alignLeft(arr, size, w);
            break;
        case 'r':
            return alignRight(arr, size, w);
            break;
        default:
            //Determine what to do if invalid entry
            break;
    }
}

//Determines the number of lines in a text array and returns the answer
int numLines(char arr[], int size){
    int lines = 1;
    for(int i = 0; i < size; i++){
        if (arr[i] == '\n'){lines += 1;}
    }
    return lines;
}

//Determines the end of a line within a multiline character array
int nextLine(char arr[], int size, int start){
    for(int i = start; i < size; i++){
        if(arr[i] == '\n'){
            return i;
        } else if (i == size - 1) {
            return i;
        }
    }
}