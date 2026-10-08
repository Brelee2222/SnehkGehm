#include "board.h"

#include <stdlib.h>

#ifndef CHARACTER_SPACING
    #define CHARACTER_SPACING 2
#endif

#define SPACING_CHARACTER ' '

typedef struct Square {
    char spacing[CHARACTER_SPACING];
    char value;
} Square_t;

// board is an 2D array
Square_t board[BOARD_HEIGHT][BOARD_WIDTH+1] = {
    // Fill spacing with the spacing character
    [0 ... BOARD_HEIGHT-1][0 ... BOARD_WIDTH].spacing = { [0 ... CHARACTER_SPACING-1] = SPACING_CHARACTER },
    // Add new lines
    [0 ... BOARD_HEIGHT-2][BOARD_WIDTH].value = '\n',
    // Modify the last square a little differently
    [BOARD_HEIGHT-1][BOARD_WIDTH].spacing[0] = '\n',
    [BOARD_HEIGHT-1][BOARD_WIDTH].value = '\0'
};
const char* BOARD_STR = (char *) board; // The board is readily displayable as a string

int score;
char showScore = 1;

void initializeBoard(void); // DEPRECATED

void resetBoard(void) {
    // Set all square to empty
    for(int row = 0; row < BOARD_HEIGHT; row++)
        for(int column = 0; column < BOARD_WIDTH; column++)
            *getSquare_ptr(row, column) = EMPTY_SQUARE;

    // Make an apple
    *getSquare_ptr(BOARD_HEIGHT / 2, BOARD_WIDTH-2) = APPLE_SQUARE;

    score = 0;
}

void makeApple(void) {
    int boardSize = (BOARD_WIDTH + 1)*BOARD_HEIGHT;
    int index = 0; // index starts on an arbitrary value
           
    for(int i = rand()%(BOARD_WIDTH*BOARD_HEIGHT); i >= 0; i--) {
        index++; 

        // (*board) effectively converts the board from a 2d to 1d array
        while((*board)[index%boardSize].value != EMPTY_SQUARE)
            index++; 
    }

    // (*board) effectively converts the board from a 2d to 1d array
    (*board)[index%boardSize].value = APPLE_SQUARE;
}

inline char* getSquare_ptr(int row, int column) {
    return &board[row][column].value;
}