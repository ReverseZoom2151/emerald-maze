# Emerald Maze Game

## Overview

**Emerald Maze Game** is a simple grid-based game where the player navigates through a maze, collects stars, and avoids walls. The project also includes visualizations such as a Mandelbrot fractal and some SDL-based demonstrations.

![maze](https://github.com/user-attachments/assets/4a6dd6a4-905a-4d89-bc70-8e81596443c0)
![fractal](https://github.com/user-attachments/assets/3cd136b4-464c-4392-8047-1d226dcf7a64)

## Table of Contents

1. [Project Structure](#project-structure)
2. [Prerequisites](#prerequisites)
3. [Installation](#installation)
4. [Building the Project](#building-the-project)
5. [Running the Games and Visualizations](#running-the-games-and-visualizations)
6. [Cleaning Up](#cleaning-up)
7. [Contributing](#contributing)
8. [License](#license)

## Project Structure


- **`action.c` / `action.h`**: Handles the logic for entity actions such as moving and interacting with objects.
- **`base.c` / `base.h`**: Provides basic utility functions.
- **`direction.c` / `direction.h`**: Manages directional movement and related calculations.
- **`display.c` / `display.h`**: Uses SDL2 for rendering and display management.
- **`entity.c` / `entity.h`**: Manages game entities and their interactions.
- **`fractal.c`**: Generates and visualizes a Mandelbrot fractal.
- **`grid.c` / `grid.h`**: Manages the grid structure for the game.
- **`maze.c`**: Implements the main game logic for the maze.
- **`state.c` / `state.h`**: Manages the state of the game.
- **`hellodisplay.c`** and **`hellosdl.c`**: Simple SDL demos.
- **`Makefile`**: Automates the build process.

## Prerequisites

- **C Compiler**: GCC or Clang
- **SDL2 Library**: The Simple DirectMedia Layer (SDL) library is required to compile and run the graphical components of the project.
  
### Installing SDL2

For Ubuntu/Debian-based systems:

```bash
sudo apt update
sudo apt install libsdl2-dev
```

For macOS (using Homebrew):
**brew install sdl2**

For Windows:

Install SDL2 from the SDL website and ensure the libraries are available in your compiler's search path.

## Installation

Clone the repository to your local machine:

```
git clone https://github.com/yourusername/emerald_maze_game.git
cd emerald_maze_game
```

## Building the Project

The project uses a Makefile to manage the build process. Use the make command to build different parts of the project:

### Build the Maze Game:

```make maze```

### Build the Fractal Visualization:

```make fractal```

Build the Base Module Test:

```make base```

## Running the Games and Visualizations

After building the executables, you can run them as follows:

### Maze Game:

```./maze```

### Fractal Visualization:

```./fractal```

### Base Module Test:

```./base```

## Controls:
- Maze Game: Use the arrow keys to move the player around the maze. Collect stars while avoiding walls. Press ESC to exit.
- Fractal Visualization: Zoom in and out using the Z and X keys. Use the arrow keys to navigate. Press ESC to exit.

## Cleaning Up:

To clean up the build directory and remove all generated executables, run:

```make clean```

## Contributing:

Contributions are welcome! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch: git checkout -b feature-branch-name.
3. Make your changes and commit them: git commit -m 'Description of changes'.
4. Push to the branch: git push origin feature-branch-name.
5. Open a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
