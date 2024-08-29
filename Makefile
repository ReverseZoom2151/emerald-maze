base = base.c
direction = direction.c base.c
grid = grid.c $(direction)
state = state.c base.c
entity = entity.c state.c $(grid)
action = action.c $(entity)
display = display.c -lSDL2
maze = maze.c $(action) $(display)
fractal = fractal.c display.c -lSDL2  

DEV = -g -fsanitize=undefined -fsanitize=address
OPT = -O2 -flto
CC = gcc 
# CC = clang
CFLAGS = -D$@Test -std=c11 -Wall -pedantic $(DEV) -o m

maze: $(maze)
	$(CC) $(CFLAGS) -o maze $(maze)

fractal: $(fractal)
	$(CC) $(CFLAGS) -o fractal $(fractal)

base: $(base)
	$(CC) $(CFLAGS) -o base $(base)

clean:
	rm -f maze fractal base
