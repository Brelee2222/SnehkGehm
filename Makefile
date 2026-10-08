opt_level=3

character_spacing=1
board_width=7

DEFINES = -DBOARD_WIDTH=$(board_width) -DCHARACTER_SPACING=$(character_spacing)

EXECUTABLE_PATH=snakeGame

snakeGame: snakeGame.o snake.o board.o game.o
	gcc snakeGame.o snake.o board.o game.o -lncurses -o $(EXECUTABLE_PATH)

snakeGame.o: snakeGame.s
	gcc -c snakeGame.s -o snakeGame.o
snakeGame.s: snakeGame.i
	gcc -O$(opt_level) -S snakeGame.i -o snakeGame.s
snakeGame.i: snakeGame.c
	gcc $(DEFINES) -E snakeGame.c -o snakeGame.i

snake.o: snake.s
	gcc -c snake.s -o snake.o
snake.s: snake.i
	gcc -O$(opt_level) -S snake.i -o snake.s
snake.i: snake.c snake.h
	gcc $(DEFINES) -E snake.c -o snake.i

board.o: board.s
	gcc -c board.s -o board.o
board.s: board.i
	gcc -O$(opt_level) -S board.i -o board.s
board.i: board.c board.h
	gcc $(DEFINES) -E board.c -o board.i

game.o: game.s
	gcc -c game.s -o game.o
game.s: game.i
	gcc -O$(opt_level) -S game.i -o game.s
game.i: game.c game.h
	gcc $(DEFINES) -E game.c -o game.i

clean:
	rm *.i *.o *.s $(EXECUTABLE_PATH)