*This project has been created as part of the 42 curriculum by epandele.*

# so_long

A simple 2D game built with MiniLibX where you control a character collecting items in a maze-like map.

## Description

**so_long** is a small graphical project that introduces the basics of game development and graphics programming. The player navigates through a rectangular map, collecting all items (represented by Ichigo's hollow masks) before reaching the exit. The game validates map structure, ensures all collectibles are reachable, and tracks player movements.

### Key Features
- Top-down 2D view with tile-based graphics
- Map validation (walls, rectangular shape, path-finding)
- Movement counter displayed in terminal
- Custom XPM sprites for walls, floor, player, collectibles, and exit
- ESC key or window close to exit properly

### Game Rules
1. Collect all items (C) on the map
2. Reach the exit (E) after collecting everything
3. Move using WASD or arrow keys
4. Try to minimize your move count!

## Instructions

### Prerequisites
- Linux system (tested on Ubuntu 24)
- X11 development libraries
- Make

### Compilation*This project has been created as part of the 42 curriculum by epandele.*

# so_long

A simple 2D game built with MiniLibX where you control a character collecting items in a maze-like map.

## Description

**so_long** is a small graphical project that introduces the basics of game development and graphics programming. The player navigates through a rectangular map, collecting all items (represented by Ichigo's hollow masks) before reaching the exit. The game validates map structure, ensures all collectibles are reachable, and tracks player movements.

### Key Features
- Top-down 2D view with tile-based graphics
- Map validation (walls, rectangular shape, path-finding)
- Movement counter displayed in terminal
- Custom XPM sprites for walls, floor, player, collectibles, and exit
- ESC key or window close to exit properly

### Game Rules
1. Collect all items (C) on the map
2. Reach the exit (E) after collecting everything
3. Move using WASD or arrow keys
4. Try to minimize your move count!

## Instructions

### Prerequisites
- Linux system (tested on Ubuntu 24)
- X11 development libraries
- Make

### Compilation
```bash
make
```

This will compile the project and all its dependencies (libft, get_next_line, ft_printf, MiniLibX).

### Running the Game
```bash
./so_long [map_file.ber]
```

Example:
```bash
./so_long map.ber
```

### Map Format
Maps must be `.ber` files with the following rules:
- Rectangular shape (not square)
- Surrounded by walls (`1`)
- Must contain exactly one player (`P`), one exit (`E`), and at least one collectible (`C`)
- Empty spaces represented by `0`
- All collectibles and exit must be reachable

Example valid map:
```
11111111111111111
111000000010001E1
111000C0001010101
1P100000C01010101
10100000001010101
100000C0000010001
11111111111111111
```

### Controls
- `W` / `↑` - Move up
- `A` / `←` - Move left  
- `S` / `↓` - Move down
- `D` / `→` - Move right
- `ESC` - Exit game

### Cleaning
```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile everything
```

## Project Structure
```
so_long/
├── src/              # Source files
├── includes/         # Header files
├── ft_libft/         # Custom C library
├── ft_printf/        # Custom printf implementation
├── get_next_line/    # File reading utility
├── minilibx-linux/   # Graphics library
├── img/              # Game sprites (XPM format)
├── Makefile
└── *.ber             # Map files
```

## Technical Choices

### Why MiniLibX?
MiniLibX is a simple graphics library that provides just enough functionality to create 2D games without overwhelming complexity. It's perfect for learning the basics of:
- Window management
- Image rendering
- Event handling (keyboard, mouse, window close)

### Flood Fill Algorithm
I implemented a recursive flood fill to validate that all collectibles and the exit are reachable from the player's starting position. This ensures the map is actually solvable before the game starts.

### Custom Libraries
Rather than using standard library functions, I built my own implementations:
- **libft**: Common C functions (strlen, split, calloc, etc.)
- **ft_printf**: Custom printf for formatted output
- **get_next_line**: Reads map files line by line

This was both a learning exercise and a way to have full control over the codebase.

## Resources

### Official Documentation
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [X Window System](https://www.x.org/wiki/)

### Tutorials & Articles
- [42 Docs - so_long](https://harm-smits.github.io/42docs/projects/so_long)
- [Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill)
- [Working with XPM files](https://www.x.org/releases/X11R7.7/doc/libX11/libX11/libX11.html#XPM_Functions)

### AI Usage
AI (Claude) was used for:
- **Debugging**: Identifying segmentation faults and logic errors
- **Code review**: Checking norm compliance and suggesting optimizations  
- **Documentation**: Helping structure this README and clarify explanations
- **Learning**: Understanding MiniLibX functions and best practices

**What I wrote myself:**
- All core game logic (player movement, collision detection, win conditions)
- Map parsing and validation
- Flood fill implementation
- Custom library functions (libft, get_next_line, ft_printf)
- Integration of all components

AI was a helpful assistant, but the project architecture, problem-solving approach, and final implementation decisions were mine.

## Known Issues
- Map must be rectangular (not square) - this is intentional per the requirements
- Window size is determined by map dimensions (no resizing)
- Sprite size is fixed at 64x64 pixels

## Acknowledgments
Thanks to the 42 community for map examples, MiniLibX tips, and debugging help!

---

**Note**: This project was developed as part of the 42 School curriculum. If you're a 42 student, please follow your school's academic integrity policies regarding code sharing and collaboration.
```bash
make
```

This will compile the project and all its dependencies (libft, get_next_line, ft_printf, MiniLibX).

### Running the Game
```bash
./so_long [map_file.ber]
```

Example:
```bash
./so_long map.ber
```

### Map Format
Maps must be `.ber` files with the following rules:
- Rectangular shape (not square)
- Surrounded by walls (`1`)
- Must contain exactly one player (`P`), one exit (`E`), and at least one collectible (`C`)
- Empty spaces represented by `0`
- All collectibles and exit must be reachable

Example valid map:
```
11111111111111111
111000000010001E1
111000C0001010101
1P100000C01010101
10100000001010101
100000C0000010001
11111111111111111
```

### Controls
- `W` / `↑` - Move up
- `A` / `←` - Move left  
- `S` / `↓` - Move down
- `D` / `→` - Move right
- `ESC` - Exit game

### Cleaning
```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile everything
```

## Project Structure
```
so_long/
├── src/              # Source files
├── includes/         # Header files
├── ft_libft/         # Custom C library
├── ft_printf/        # Custom printf implementation
├── get_next_line/    # File reading utility
├── minilibx-linux/   # Graphics library
├── img/              # Game sprites (XPM format)
├── Makefile
└── *.ber             # Map files
```

## Technical Choices

### Why MiniLibX?
MiniLibX is a simple graphics library that provides just enough functionality to create 2D games without overwhelming complexity. It's perfect for learning the basics of:
- Window management
- Image rendering
- Event handling (keyboard, mouse, window close)

### Flood Fill Algorithm
I implemented a recursive flood fill to validate that all collectibles and the exit are reachable from the player's starting position. This ensures the map is actually solvable before the game starts.

### Custom Libraries
Rather than using standard library functions, I built my own implementations:
- **libft**: Common C functions (strlen, split, calloc, etc.)
- **ft_printf**: Custom printf for formatted output
- **get_next_line**: Reads map files line by line

This was both a learning exercise and a way to have full control over the codebase.

## Resources

### Official Documentation
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [X Window System](https://www.x.org/wiki/)

### Tutorials & Articles
- [42 Docs - so_long](https://harm-smits.github.io/42docs/projects/so_long)
- [Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill)
- [Working with XPM files](https://www.x.org/releases/X11R7.7/doc/libX11/libX11/libX11.html#XPM_Functions)

### AI Usage
AI (Claude) was used for:
- **Debugging**: Identifying segmentation faults and logic errors
- **Code review**: Checking norm compliance and suggesting optimizations  
- **Documentation**: Helping structure this README and clarify explanations
- **Learning**: Understanding MiniLibX functions and best practices

**What I wrote myself:**
- All core game logic (player movement, collision detection, win conditions)
- Map parsing and validation
- Flood fill implementation
- Custom library functions (libft, get_next_line, ft_printf)
- Integration of all components

AI was a helpful assistant, but the project architecture, problem-solving approach, and final implementation decisions were mine.

## Known Issues
- Map must be rectangular (not square) - this is intentional per the requirements
- Window size is determined by map dimensions (no resizing)
- Sprite size is fixed at 64x64 pixels

## Acknowledgments
Thanks to the 42 community for map examples, MiniLibX tips, and debugging help!

---

**Note**: This project was developed as part of the 42 School curriculum. If you're a 42 student, please follow your school's academic integrity policies regarding code sharing and collaboration.