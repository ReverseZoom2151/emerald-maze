#include "display.h"
#include "action.h"
#include "direction.h"
#include <stdbool.h>

#define BLOCKSIZE 32

static const int width = 9, height = 9;
static char *level[] = {
    "#########",
    "#...#..*#",
    "#.#.#.###",
    "#.#....*#",
    "#.####.##",
    "#@#*....#",
    "####.##.#",
    "#*...#*.#",
    "#########"
};

static entity *fill(grid *g, state *s) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            newEntity(s, g, x, y, level[y][x]);
            entity *e = getCell(g, x, y);
            wake(e);
        }
    }
    return getPlayer(s);
}

static void draw(display *d, grid *g, int stars) {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      entity *e = getCell(g, x, y);
      switch (getKind(e)) {
        case Blank: colour(d, 0xFF); break;
        case Wall: colour(d, 0x88FF); break;
        case Star: colour(d, 0xFF00FF); break;
        case Player: colour(d, 0xFFFFFFFF);
      }
      block(d, x * BLOCKSIZE, y * BLOCKSIZE, BLOCKSIZE, BLOCKSIZE);
    }
  }
  colour(d, 0xFF00FF);
  for (int x = 0; x < stars; x++) {
    block(d, x * BLOCKSIZE / 2 + BLOCKSIZE / 4, BLOCKSIZE / 4, BLOCKSIZE / 4, BLOCKSIZE / 4);
  }
}

bool navigate(display *d, void *data, const char pressedKey) {
  entity *player = (entity*) data;
  grid *g = getGrid(player);
  int stars = getStars(getState(player));
  if (stars != 0) {
    if (pressedKey == 80) act(player, West);
    else if (pressedKey == 79) act(player, East);
    else if (pressedKey == 82) act(player, North);
    else if (pressedKey == 81) act(player, South);
    draw(d, g, stars);
  } else {
    colour(d, 0xFFFFFFFF);
    block(d, 0, 0, BLOCKSIZE * width, BLOCKSIZE * height);
  }
  show(d);
  return (pressedKey == 27);
}

int main() {
    grid *g = newGrid(width, height);
    state *s = newState();
    entity *player = fill(g, s);
    display *d = newDisplay("Emerald Maze", width * BLOCKSIZE, height * BLOCKSIZE);
    run(d, (void*)player, navigate);
    freeState(s);
    freeGrid(g);
    freeDisplay(d);
}

