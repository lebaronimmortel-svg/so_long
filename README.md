*This project has been created as part of the 42 curriculum by alexfuen.*

## Description
so_long is a small 2D top-down game built with the **MiniLibX** graphical library. The objective is to guide a player through a tile-based labyrinth, collect every collectible scattered across the map, and reach the exit with the minimum number of moves.

The project is split into a mandatory part and a bonus part:

**Mandatory part** incorporates the following main features:
- Parses a `.ber` map file composed of specific characters: walls (`1`), empty floor (`0`), collectibles (`C`), player spawn (`P`), and the exit (`E`).
- Thorough map validation: checks for a rectangular perimeter entirely surrounded by walls, exactly one spawn point, at least one collectible, and exactly one exit.
- Pathfinding validation (flood fill algorithm) to ensure the map is solvable: verifies that a valid path exists from the player to every collectible and the exit before launching the window.
- Renders 2D textures for each tile using the MiniLibX window and image functions.
- Handles player movement via `W`, `A`, `S`, `D` or arrow keys, incrementing a move counter displayed in the shell after every step.
- Closes the window and terminates cleanly upon pressing `ESC` or clicking the window's close button.

**Bonus part** extends the mandatory version with:
- An in-game move counter displayed directly on the screen rather than only printed to the terminal.
- Sprite animations: idle, movement, or collectible animations played across frames using the MiniLibX loop hook.
- Patrol enemies that move across the map: walking into an enemy causes the player to lose and resets or quits the game immediately.

Memory is properly managed throughout; all allocated map structures, arrays, and MiniLibX image textures are cleanly destroyed and freed upon exit.

## Instructions
To compile and run the project, the standard `Makefile` rules apply:
- Run `make` or `make all` to compile the mandatory executable `so_long`.
- Run `make bonus` to compile the bonus executable `so_long_bonus`.
- Other available `Makefile` rules include `clean`, `fclean`, and `re`.
- Once compiled, launch the game by passing a valid `.ber` map file as an argument:
```bash
./so_long map.ber
```
```bash
./so_long_bonus map.ber
```
### Map File Format
The `.ber` map must be rectangular and enclosed by walls:
```bash
1111111111111
1P00100C00001
1000101111001
100C00000E001
1111111111111
```
### Controls
| Key / Action | Effect |
|---|---|
| `W` / `↑` | Move up |
| `S` / `↓` | Move down |
| `A` / `←` | Move left |
| `D` / `→` | Move right |
| `ESC` | Exit the game |
| Window cross | Exit the game |

## Resources
Resources for this project were:
 
 - https://en.wikipedia.org/wiki/Flood_fill — An explanation of the flood-fill algorithm
 - the minilibX manual