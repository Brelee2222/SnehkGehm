#include "snake.h"

#include "board.h"

#include <stdio.h>

#define NUMBER_OF_SEGMENTS 2

/**
 * typedef struct Position( unsigned int row, unsigned int column )
 * 
 * Define a position on the board. 
 * Effectively acts as a pointer to a location on the board.
 * 
 * Members:
 *   - row : The row of the square pointing to
 *   - column : The column of the square pointing to
 */
typedef struct Position {
    unsigned int row;
    unsigned int column;
} Position_t;

// The pointers to the head and tail of the snake linked-list
Position_t headPos;
Position_t tailPos;

Position_t* stepPosition(Position_t* pos); // Effectively acts as getNextNode() for a linked list
char* accessSquare(Position_t* pos); // Gets the pointer to a square using from the given position
char isLoss(void);
char isWin(void);

// Returns a state
int advanceHead(void) {
    char lastSquare = *accessSquare(&headPos);
    char nextSquare = *accessSquare(stepPosition(&headPos));

    // The head is not yet placed. Check if what is there first creates a loss
    if(isLoss())
        return GAME_OVER_STATE;

    *accessSquare(&headPos) = lastSquare;

    if(nextSquare == APPLE_SQUARE)
        return EAT_APPLE_STATE;

    if(nextSquare == EMPTY_SQUARE)
        return EAT_AIR_STATE;
}

int regressTail(void) {
    Position_t tempTail = tailPos;
    stepPosition(&tailPos);

    // Effectively deallocates the node
    *accessSquare(&tempTail) = EMPTY_SQUARE;

    return DISPLAY_BOARD_STATE;
}

int eatApple(void) {
    score++;

    if(isWin())
        return WIN_STATE;

    makeApple();

    return DISPLAY_BOARD_STATE;
}

int changeDirection(char direction) {
    *accessSquare(&headPos) = direction;

    return DISPLAY_BOARD_STATE;
}

void resetSnake(void) {
    int snakeRow = BOARD_HEIGHT / 2;

    headPos.row = snakeRow;
    headPos.column = NUMBER_OF_SEGMENTS - 1;

    tailPos.row = snakeRow;
    tailPos.column = 0;

    for(int i = NUMBER_OF_SEGMENTS-1; i >= 0; i--)
        *getSquare_ptr(snakeRow, i) = SNAKE_RIGHT;
}

Position_t* stepPosition(Position_t* pos) {
    switch (*accessSquare(pos)) {
        case SNAKE_UP:
            pos->row--;
            break;
        case SNAKE_DOWN:
            pos->row++;
            break;
        case SNAKE_LEFT:
            pos->column--;
            break;
        case SNAKE_RIGHT:
            pos->column++;
            break;
        default:
            perror("Not a correct snake direction");
    }
    
    return pos;
}

inline char* accessSquare(Position_t* pos) {
    return getSquare_ptr(pos->row, pos->column);
}

inline char isLoss(void) {
    if(headPos.row >= BOARD_HEIGHT || headPos.column >= BOARD_WIDTH)
        return 1;
    
    char currentSquare = *accessSquare(&headPos);
    if(
        currentSquare == SNAKE_UP ||
        currentSquare == SNAKE_DOWN ||
        currentSquare == SNAKE_LEFT ||
        currentSquare == SNAKE_RIGHT
    ) return 1;

    return 0;
}

inline char isWin(void) {
    return score - NUMBER_OF_SEGMENTS >= BOARD_WIDTH * BOARD_HEIGHT;
}