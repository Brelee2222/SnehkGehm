#define INITIAL_STATE 8
#define RESET_BOARD_STATE 0
#define CHECK_INPUT_STATE 2
#define END_GAME_STATE 9
#define STOP_PROGRAM_STATE 10

/**
 * int initialize(void);
 * Runs the initialization state of the system.
 * 
 * Returns: An integer representing the next state to transition to
 */
int initialize(void);

/**
 * int resetGame(void);
 * Runs the game reset state of the system.
 * 
 * Returns: An integer representing the next state to transition to
 */
int resetGame(void);

/**
 * int displayBoard(void);
 * Runs the board display state of the system.
 * 
 * Returns: An integer representing the next state to transition to
 */
int displayBoard(void);

/**
 * int checkInput(void);
 * Runs the input checking state of the system.
 * 
 * Returns: An integer representing the next state to transition to
 */
int checkInput(void);

/**
 * int endgameCheckInput(void);
 * Runs the endgame input checking state of the stystem.
 * 
 * Returns: An integer representing the next state to transition to
 */
int endgameCheckInput(void);