#include "game.h"

#include "board.h"
#include "snake.h"

#include <ncursesw/curses.h>
#include <time.h>
#include <stdlib.h>

#define WAIT_TIME 1

time_t gameStartTime;
time_t lastMoveTime;

int initialize(void) {
    // Set the seed of the program
    srand(time(NULL));

    // initializeBoard();

    return RESET_BOARD_STATE;
}

int resetGame(void) {
    // Must reset board before the snake
    resetBoard();
    resetSnake();

    gameStartTime = 
    lastMoveTime = time(NULL);

    return DISPLAY_BOARD_STATE;
}

int displayBoard(void) {
    // board_str is readily rendered
    printw("\n\n--Snek Gehm--\n%s", BOARD_STR);

    if(showScore)
        printw(
            "Score: %3.d  |  Time: %3.ds\n",
            score, 
            lastMoveTime - gameStartTime
        );

    return CHECK_INPUT_STATE;
}

int checkInput(void) {
    // If a certain amount of time has elapsed, move the snake.
    time_t currentTime = time(NULL);
    if(currentTime - lastMoveTime >= WAIT_TIME) {
        lastMoveTime = currentTime;
        return MOVE_SNAKE_STATE;
    }

    switch (getch()) {
        case KEY_UP:
        case 'w':
            return changeDirection(SNAKE_UP);
        case KEY_DOWN:
        case 's':
            return changeDirection(SNAKE_DOWN);
        case KEY_LEFT:
        case 'a':
            return changeDirection(SNAKE_LEFT);
        case KEY_RIGHT:
        case 'd':
            return changeDirection(SNAKE_RIGHT);
        case 'q':
            return STOP_PROGRAM_STATE;
        default:
            return CHECK_INPUT_STATE;
    }
}

int endgameCheckInput(void) {
    switch (getch()) {
        case '\n':
            return RESET_BOARD_STATE;
        case 'q':
            return STOP_PROGRAM_STATE;
        default:
            return END_GAME_STATE;
    }
}