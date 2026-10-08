#ifndef BOARD_H
#define BOARD_H

// States
#define DISPLAY_BOARD_STATE 1
#define GAME_OVER_STATE 6
#define WIN_STATE 7

// Snake Symbols
#define SNAKE_UP '^'
#define SNAKE_DOWN 'v'
#define SNAKE_LEFT '<'
#define SNAKE_RIGHT '>'

// Other symboles
#define EMPTY_SQUARE '.'
#define APPLE_SQUARE '@'

#ifndef BOARD_WIDTH
    #define BOARD_WIDTH 7
#endif
#define BOARD_HEIGHT BOARD_WIDTH

// The board_str is a pointer to the board.
// After initialization, the board is always readily renderable as a string.
extern const char* BOARD_STR;

extern int score;
extern char showScore;

/** @deprecated
 * void initializeBoard(void);
 * 
 * Initializes the board.
 */
void initializeBoard(void);

/**
 * void resetBoard(void);
 * 
 * Sets all square on the board to an empty space.
 * Sets one square to an apple.
 */
void resetBoard(void);

/**
 * void makeApple(void);
 * 
 * Places an apple on a random empty square on the board.
 */
void makeApple(void);

/**
 * char* getSquare_ptr(int row, int column);
 * 
 * Provides the pointer to a position on the board.
 * 
 * Note:
 *  Assumes the row and column goes a valid position.
 * 
 * Parameters:
 *   - row: the row of the square on the board
 *   - column: the column of the square on the board
 * Returns: A pointer to the square.
 */
char* getSquare_ptr(int row, int column);

#endif