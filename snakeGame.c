#include "game.h"
#include "board.h"
#include "snake.h"

#include <ncursesw/curses.h>
#include <string.h>

void init_ncurses(void);

int main(int argc, char* argv[]) {
    // Check for command-line arguments
    if(argc >= 2) {
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            printf(
                "Snake Game: Use the arrow keys or WASD to steer the snake. \n" 
                "Collect the apples to increase your score. \n"
            );
            return 0;
        }

        if(strcmp(argv[1], "-hideScore") == 0)
            showScore = 0;
    }

    init_ncurses();

    int state = INITIAL_STATE;

    // Recursion for finite-state machine
    while(1) {
        switch (state) {
            case INITIAL_STATE:
                state = initialize();
                break;
            
            case RESET_BOARD_STATE:
                state = resetGame();
                break;

            case DISPLAY_BOARD_STATE:
                state = displayBoard();
                break;
            
            case CHECK_INPUT_STATE:
                state = checkInput();
                break;
            
            case MOVE_SNAKE_STATE:
                state = advanceHead();
                break;
            
            case EAT_APPLE_STATE:
                state = eatApple();
                break;
            
            case EAT_AIR_STATE:
                state = regressTail();
                break;
            
            case GAME_OVER_STATE:
                printw("You lost ):\n(press 'enter' to restart or 'q' to exit)\n");
                state = END_GAME_STATE;
                break;
            
            case WIN_STATE:
                printw("You won!\n(press 'enter' to restart or 'q' to exit)\n");
                state = END_GAME_STATE;
                break;
            
            case END_GAME_STATE:
                state = endgameCheckInput();
                break;
            
            case STOP_PROGRAM_STATE:
                endwin();
                return 0;

            default:
                printf("Invalid state");
                return 1;
        }
    }
}

void init_ncurses(void) {
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    set_escdelay(0);
}