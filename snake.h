#ifndef SNAKE_H
#define SNAKE_H

// States
#define MOVE_SNAKE_STATE 3
#define EAT_APPLE_STATE 4
#define EAT_AIR_STATE 5

/**
 * int changeDirection(char direction);
 * Changes the direction of the snake's head on the board.
 * 
 * Note:
 *  Assumes the given direction is valid
 * 
 * Parameters:
 *   - direction: a character that represents the direction of the snake
 * 
 * Returns: An integer representing the next state to transition to
 */
int changeDirection(char direction);

/**
 * int advanceHead(void);
 * Runs the Snake Moving State of the system
 * 
 * Returns: An integer representing the next state to transition to
 */
int advanceHead(void);

/**
 * int eatApple(void);
 * Runs the Apple Eating state of the system
 * 
 * Returns: An integer representing the next state to transition to
 */
int eatApple(void);

/**
 * int regressTail(void);
 * Runs the Tail Regression state of the system
 * 
 * Returns: An integer representing the next state to transition to
 */
int regressTail(void);

/**
 * void resetSnake(void);
 * Resets the snake's head and tail positions. Create's the new snake's body on the board.
 */
void resetSnake(void);

#endif