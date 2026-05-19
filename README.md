# so_long

*This project has been created as part of the 42 curriculum by aalvarad.*

## Description

`so_long` is a small 2D top-down game built with the school's graphical library, **MiniLibX**. The player controls a character that must collect every collectible on the map before reaching the exit, while avoiding walls. The current move count is printed in the shell at every step.

The project covers several core programming areas:
- Window and event management with MiniLibX
- Parsing and validating a custom map format (`.ber`)
- Path validation using a **flood fill** algorithm
- Tile-based rendering with XPM textures
- Manual memory management (no leaks)

### The world

Instead of the dolphin theme suggested in the subject, this version is set in a stylized **traditional Chinese palace**: the player controls a robot dog inspired by the Unitree Go2, the collectibles are red Chinese lanterns, and the exit is a pagoda gate. Walls are red brick with golden trim, and the ground is stone paving.

### Controls

| Key | Action |
| --- | --- |
| `W` / `↑` | Move up |
| `S` / `↓` | Move down |
| `A` / `←` | Move left |
| `D` / `→` | Move right |
| `ESC` | Quit the game |
| Window close button | Quit the game |

### Map format

Maps are plain text files with the `.ber` extension, made of these 5 characters:

| Char | Meaning |
| --- | --- |
| `0` | Empty space (walkable) |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player starting position |

A valid map must:
- be rectangular
- be entirely surrounded by walls
- contain exactly **one** `P` and **one** `E`
- contain at least **one** `C`
- have a valid path from `P` to every `C` and to `E`

Example:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

If any of these rules is violated, the program exits cleanly with `Error\n` followed by an explicit message.

## Instructions

### Build

```sh
make
```

The Makefile automatically detects the operating system (`macOS` or `Linux`) and links the appropriate version of MiniLibX. It compiles with `-Wall -Wextra -Werror` and does not relink.

Available rules: `all`, `clean`, `fclean`, `re`.

### Run

```sh
./so_long assets/maps/map.ber
```

A few test maps are provided in `assets/maps/`.

### Project structure

```
.
├── Makefile
├── include/
│   └── so_long.h
├── src/
│   ├── main.c             # entry point + check_all + init_game
│   ├── parsing.c          # file reading
│   ├── check_map.c        # structural validation (size, chars, rectangle, walls)
│   ├── check_content.c    # P/E/C counting
│   ├── flood_fill.c       # path validation via flood fill
│   ├── init_mlx.c         # window, textures, rendering
│   ├── game.c             # key handling, movement, clean exit
│   ├── error.c            # unified error handling
│   └── utils.c            # free_map and other helpers
├── libft/                 # personal C library
├── mlx_macos/             # MiniLibX for macOS
├── mlx_linux/             # MiniLibX for Linux
└── assets/
    ├── maps/              # sample .ber maps
    └── textures/          # XPM textures
```

## Resources

### Documentation and references

- **MiniLibX documentation**: [Harm Smits' MLX 42 documentation](https://harm-smits.github.io/42docs/libs/minilibx) — the most useful unofficial reference for MiniLibX function signatures and event codes.
- **XPM file format**: [Wikipedia X PixMap](https://en.wikipedia.org/wiki/X_PixMap) — to understand the layout of the texture files.
- **Flood fill algorithm**: classical recursive 4-directional flood fill, see [Wikipedia: Flood fill](https://en.wikipedia.org/wiki/Flood_fill).
- **42 norm**: official norminette reference for code style.
- **`man` pages**: `open`, `read`, `write`, `malloc`, `free`, `exit`.

### Use of AI

AI assistance was used for two specific tasks:

1. **Generating the custom XPM textures.** The 5 sprites (wall, floor, player, collectible, exit) were generated programmatically with a Python script (run separately from the project, not part of the submission). The textures were then verified visually and tested in the game. This was a tooling shortcut: writing XPM files by hand at 64×64 pixels is purely mechanical and AI was used to automate that process.
2. **Pedagogical support during development.** AI was used as a learning aid (similar to a peer or a tutor) to discuss algorithm design (flood fill, parsing strategy), explain MiniLibX behavior, and review code for norm compliance. Every line of the submitted C code was written, understood, and tested by me — any AI suggestion that wasn't fully understood was either reworked or discarded.

No external code was copy-pasted into the project. All `.c` files were written from scratch and can be explained line by line during defense.

## Features summary

- ✅ Mandatory parsing rules fully validated (size, characters, rectangle, walls, P/E/C count, path)
- ✅ Top-down 2D view with custom XPM textures
- ✅ Smooth window management (move, switch, minimize)
- ✅ Movement with WASD and arrow keys
- ✅ Wall collision
- ✅ Collectible pickup
- ✅ Win condition (all collectibles + reach exit)
- ✅ Move counter printed in the shell
- ✅ ESC and window cross close the program cleanly
- ✅ No memory leaks (verified with `leaks` on macOS)
