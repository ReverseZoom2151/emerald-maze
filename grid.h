#include <stdbool.h>

struct grid;
typedef struct grid grid;

struct entity;
typedef struct entity entity;
typedef int direction;

grid *newGrid(int width, int height);

void freeGrid(grid *g);

entity *getCell(grid *g, int x, int y);

void setCell(grid *g, int x, int y, entity *e);
void *nextCell(grid *g, int x, int y, direction d);
