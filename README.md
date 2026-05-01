# cub3D - 42 Project

## 📚 Description

**cub3D** is a project from School 42 inspired by the legendary **Wolfenstein 3D**, widely recognized as the first true FPS in gaming history. Using raycasting techniques, this project creates a dynamic 3D graphical representation of a maze from a first-person perspective.

The goal is to master raycasting algorithms, understand the mathematics behind 3D projection, work with the MiniLibX graphical library, and handle textures, colors, and player movements to create an immersive gaming experience.

> *"My first RayCaster with miniLibX"*

## 🛠️ Features

### Mandatory Part
- **Raycasting Engine**: Real-time 3D rendering using Digital Differential Analysis (DDA)
- **Textured Walls**: Four different wall textures (North, South, East, West)
- **Floor & Ceiling Colors**: Customizable RGB colors
- **Smooth Movement**: WASD controls for player navigation
- **Camera Rotation**: Arrow keys for looking left/right
- **Map Parsing**: `.cub` file format for scene configuration
- **Collision Detection**: Player cannot walk through walls
- **Window Management**: Clean exit on ESC or window close

### Bonus Part
- ✅ **Interactive Minimap**: Real-time 2D overview with player position
- ✅ **Animated Doors**: Opening/closing door system with E key interaction
- ✅ **Mouse Controls**: Look around using mouse movement
- ✅ **Wall Collision**: Refined hitbox system
- ✅ **Door States**: Visual feedback for door states (closed, opening, open, closing)

## 📂 Project Structure

```
cub3D/
├── srcs/
│   ├── exec/
│   │   ├── 2D_to_3D.c              # 3D projection from raycasting
│   │   ├── display_line.c          # Vertical line rendering with textures
│   │   ├── display_line_set.c      # Texture mapping calculations
│   │   ├── display_ray.c           # Ray visualization
│   │   ├── display_shape.c         # Drawing utilities
│   │   ├── free.c                  # Memory cleanup
│   │   ├── hooks.c                 # Keyboard event handlers
│   │   ├── init.c                  # MiniLibX initialization
│   │   ├── init_textures.c         # Texture loading
│   │   ├── loop_update_ray.c       # Ray hit detection
│   │   ├── raycasting.c            # DDA algorithm implementation
│   │   ├── update_game.c           # Game loop
│   │   └── update_move_camera.c    # Player movement and rotation
│   ├── parsing/
│   │   ├── main.c                  # Entry point
│   │   ├── check.c                 # Texture validation
│   │   ├── check_2.c               # Map formatting
│   │   ├── check_line_colors.c     # RGB validation
│   │   ├── free_all.c              # Memory management
│   │   ├── init_game.c             # Game structure initialization
│   │   ├── parsing.c               # Main parsing logic
│   │   ├── parsing_line_colors.c   # Floor/ceiling color parsing
│   │   ├── parsing_line_textures.c # Texture path parsing
│   │   ├── parsing_map.c           # Map grid parsing
│   │   ├── parsing_map_utils.c     # File reading utilities
│   │   ├── parsing_map_utils_2.c   # File validation
│   │   ├── parsing_map_utils_4.c   # Element parsing
│   │   ├── parsing_map_utils_5.c   # Player direction setup
│   │   ├── valid_map.c             # Map element validation
│   │   ├── valid_track.c           # Flood fill algorithm
│   │   └── valid_track_utils.c     # Grid copying utilities
│   └── bonus/
│       ├── exec_bonus/             # Same as exec with bonus features
│       │   ├── minimap_bonus.c     # Minimap rendering
│       │   ├── init_doors_bonus.c  # Door texture loading
│       │   ├── move_player_bonus.c # Enhanced movement
│       │   └── ... (+ all exec files with bonus features)
│       └── parsing_bonus/          # Same as parsing with doors
│           ├── parsing_door_bonus.c # Door parsing
│           └── ... (+ all parsing files)
├── includes/
│   ├── cub3D.h                     # Main header
│   ├── exec.h                      # Execution functions
│   ├── parsing.h                   # Parsing functions
│   ├── struct.h                    # Data structures
│   └── *_bonus.h                   # Bonus headers
├── textures/                       # Wall and door textures (.xpm)
├── maps/                           # Scene files (.cub)
├── libft/                          # Custom C library
├── get_next_line/                  # Line reading utility
├── minilibx/                       # Graphics library
├── Makefile                        # Compilation rules
└── README.md                       # This file
```

## 🚀 Installation & Usage

### 1. Prerequisites

```bash
# Install required packages (Debian/Ubuntu)
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# For macOS
brew install make
```

### 2. Compilation

```bash
# Clone the repository
git clone <repository_url> cub3D
cd cub3D

# Compile mandatory part
make

# Compile bonus part
make bonus

# Clean object files
make clean

# Full cleanup
make fclean

# Recompile everything
make re
```

### 3. Execution

#### Mandatory Part
```bash
./cub3D maps/basic_scene.cub
```

#### Bonus Part
```bash
./cub3D_bonus maps/big_scene.cub
```

### 4. Controls

**Movement:**
- `W` - Move forward
- `S` - Move backward
- `A` - Strafe left
- `D` - Strafe right

**Camera:**
- `←` - Rotate camera left
- `→` - Rotate camera right
- `Mouse` - Look around (bonus only)

**Actions:**
- `E` - Interact with doors (bonus only)
- `P` - Pause/unpause mouse control (bonus only)
- `ESC` - Exit game

## 🗺️ Map File Format (.cub)

### Structure

```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Elements

**Textures:**
- `NO` - North wall texture path (.xpm)
- `SO` - South wall texture path (.xpm)
- `WE` - West wall texture path (.xpm)
- `EA` - East wall texture path (.xpm)

**Colors:**
- `F` - Floor color (R,G,B) - values 0-255
- `C` - Ceiling color (R,G,B) - values 0-255

**Map Characters:**
- `0` - Empty space (walkable)
- `1` - Wall
- `N/S/E/W` - Player starting position and orientation
- `D` - Door (bonus only)
- ` ` (space) - Void (outside map)

### Map Rules

1. Map must be surrounded by walls (`1`)
2. Only one player starting position
3. Valid characters: `0`, `1`, `N`, `S`, `E`, `W`, ` `, `D` (bonus)
4. No empty lines within the map
5. All texture paths must be valid `.xpm` files
6. RGB values must be in range 0-255

## ⚙️ How It Works

### Raycasting Algorithm

#### 1. Ray Initialization
For each vertical stripe on the screen, cast a ray from the player's position:

```c
camera_x = 2 * x / screen_width - 1;
ray.dir_x = player.dir_x + player.plane_x * camera_x;
ray.dir_y = player.dir_y + player.plane_y * camera_x;
```

#### 2. DDA (Digital Differential Analysis)
Step through the grid until hitting a wall:

```c
while (!ray.hit)
{
    if (side_dist_x < side_dist_y)
    {
        side_dist_x += delta_dist_x;
        map_x += step_x;
        side = VERTICAL;
    }
    else
    {
        side_dist_y += delta_dist_y;
        map_y += step_y;
        side = HORIZONTAL;
    }
    
    if (map[map_y][map_x] == '1')
        ray.hit = 1;
}
```

#### 3. Wall Height Calculation
```c
perpendicular_dist = (side_dist - delta_dist);
line_height = (int)(screen_height / perpendicular_dist);
```

#### 4. Texture Mapping
```c
wall_x = player.y + perpendicular_dist * ray.dir_y; // or x
wall_x -= floor(wall_x);
tex_x = (int)(wall_x * texture_width);
```

### Player Movement

```c
// Forward/Backward
new_x = player.x + player.dir_x * move_speed;
new_y = player.y + player.dir_y * move_speed;

// Strafe Left/Right
new_x = player.x + player.plane_x * move_speed;
new_y = player.y + player.plane_y * move_speed;
```

### Camera Rotation

```c
old_dir_x = dir_x;
dir_x = dir_x * cos(rot_speed) - dir_y * sin(rot_speed);
dir_y = old_dir_x * sin(rot_speed) + dir_y * cos(rot_speed);

plane_x = -dir_y;
plane_y = dir_x;
```

## 🎮 Bonus Features Details

### Minimap

- **Size**: 200x200 pixels
- **Range**: 5 tiles around player
- **Colors**:
  - Red: Walls
  - Orange: Walkable floor
  - Blue: Closed doors
  - Green: Open doors
  - Yellow: Doors in transition
  - Black: Void

### Animated Doors

**States:**
1. **Closed** (frame 0): Fully closed, blocks movement
2. **Opening** (frames 1-4): Animation in progress
3. **Open** (frame 5): Fully open, passable
4. **Closing** (frames 4-1): Animation in reverse

**Interaction:**
- Press `E` near a door to toggle
- Doors animate smoothly over 5 frames
- Timer-based frame updates
- Collision detection based on frame state

### Mouse Control

- **Sensitivity**: Adjustable rotation speed
- **Centering**: Mouse auto-recenters for continuous rotation
- **Toggle**: Press `P` to enable/disable mouse look
- **Hidden cursor**: Cursor hidden during mouse control

## 🧪 Testing

### Basic Tests

```bash
# Valid map with all elements
./cub3D maps/basic_scene.cub

# Large map
./cub3D maps/big_scene.cub

# Map with doors (bonus)
./cub3D_bonus maps/map_with_doors.cub
```

### Error Handling Tests

```bash
# Missing file
./cub3D maps/nonexistent.cub
# Expected: Error message

# Invalid extension
./cub3D maps/test.txt
# Expected: "Error: Invalid file extension"

# Duplicate textures
# Expected: "Error: Double definition of NO texture"

# Invalid RGB
# Expected: "Error: R G or B too high or too low"

# Map not closed
# Expected: "Error: Map is not closed"

# No player
# Expected: "Error: Player not present in the map"

# Invalid character in map
# Expected: "Error: Map contain invalid character"
```

### Memory Leak Check

```bash
# Using valgrind
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/basic_scene.cub

# Expected: No leaks from your code
# Note: MiniLibX may have internal leaks (acceptable)
```

## 🎯 Key Algorithms

### Digital Differential Analysis (DDA)

The DDA algorithm efficiently traverses a grid along a ray by calculating the distance to the next grid intersection:

```c
// Calculate step direction and initial side distances
if (ray.dir_x < 0)
{
    step_x = -1;
    side_dist_x = (player.x - map_x) * delta_dist_x;
}
else
{
    step_x = 1;
    side_dist_x = (map_x + 1 - player.x) * delta_dist_x;
}
```

### Flood Fill (Map Validation)

Ensures the map is properly closed by checking if the player can reach the void:

```c
int flood_fill(char **grid, int x, int y, t_map *map)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
        return (0); // Reached outside - map not closed
    
    if (grid[y][x] == '1' || grid[y][x] == 'X')
        return (1); // Wall or already visited
    
    if (grid[y][x] == ' ')
        return (0); // Void - map not closed
    
    grid[y][x] = 'X'; // Mark as visited
    
    // Recursively check all directions
    return (flood_fill(grid, x+1, y, map) &&
            flood_fill(grid, x-1, y, map) &&
            flood_fill(grid, x, y+1, map) &&
            flood_fill(grid, x, y-1, map));
}
```

## 🐛 Common Challenges & Solutions

### Challenge 1: Fisheye Effect
**Problem**: Walls appear curved  
**Solution**: Calculate perpendicular distance instead of Euclidean:
```c
perp_dist = (side_dist - delta_dist); // NOT sqrt(dx² + dy²)
```

### Challenge 2: Texture Distortion
**Problem**: Textures stretch incorrectly  
**Solution**: Use proper texture coordinate calculation:
```c
hit_point = player.y + perp_dist * ray.dir_y; // For vertical walls
hit_point -= floor(hit_point); // Get fractional part
tex_x = (int)(hit_point * texture_width);
```

### Challenge 3: Wall Flickering
**Problem**: Walls flicker at certain angles  
**Solution**: Use consistent side detection:
```c
if (side == VERTICAL)
    wall_x = player.y + perp_dist * ray.dir_y;
else
    wall_x = player.x + perp_dist * ray.dir_x;
```

### Challenge 4: Map Parsing Errors
**Problem**: Incorrect map validation  
**Solution**: Implement robust flood fill and format map to rectangular grid

### Challenge 5: Memory Leaks
**Problem**: Textures not properly freed  
**Solution**: Systematic cleanup of all MiniLibX images:
```c
mlx_destroy_image(mlx, texture[i].img_ptr);
```

### Challenge 6: Door Collision (Bonus)
**Problem**: Player walks through opening doors  
**Solution**: Check door frame state before allowing movement:
```c
if (map[y][x] == 'D' && door->frame < 4)
    return (BLOCKED);
```

## 💡 Optimization Tips

1. **Minimize MLX Calls**: Draw to buffer, then display once per frame
2. **Efficient Ray Casting**: Stop DDA when wall is hit
3. **Smart Texture Loading**: Load textures once at initialization
4. **Collision Buffering**: Use distance threshold for smooth movement
5. **Frame Independence**: Decouple logic from render speed

## 📊 Performance

**Target Performance:**
- 60 FPS on modern hardware
- Smooth movement and rotation
- No visible stuttering
- Responsive controls

**Optimizations Applied:**
- Single buffer write per frame
- Early ray termination
- Minimal MLX function calls
- Efficient memory management

## 📝 Data Structures

### Main Game Structure
```c
typedef struct s_game
{
    t_player    player;      // Player position and direction
    t_map       map;         // Map grid and doors
    t_texture   texture;     // Wall textures and colors
    t_milx      libx;        // MiniLibX data
    t_keys_move move_keys;   // Keyboard state
    t_ray       ray[200];    // Ray data for minimap
    t_img       walls[4];    // Wall textures (N,S,E,W)
    t_img       doors[4][5]; // Door animation frames
    int         pause_mouse; // Mouse control state
} t_game;
```

### Player Structure
```c
typedef struct s_player
{
    double x;        // X position
    double y;        // Y position
    double dir_x;    // Direction vector X
    double dir_y;    // Direction vector Y
    double plane_x;  // Camera plane X
    double plane_y;  // Camera plane Y
    double fov;      // Field of view
} t_player;
```

### Ray Structure
```c
typedef struct s_ray
{
    double dir_x, dir_y;           // Ray direction
    double side_dist_x, side_dist_y; // Distance to next grid line
    double delta_dist_x, delta_dist_y; // Distance between grid lines
    int    map_x, map_y;           // Current map position
    int    step_x, step_y;         // Step direction
    int    hit;                    // Wall hit flag
    int    side;                   // Which side was hit
    double real_dist;              // Perpendicular distance
    int    is_door;                // Door hit flag
    t_door *door;                  // Door pointer
} t_ray;
```

## 🔍 Allowed Functions

### Standard Library
- `open`, `close`, `read`, `write`
- `malloc`, `free`
- `perror`, `strerror`
- `exit`
- `math library`: `-lm` (math.h functions)

### MiniLibX Functions
- `mlx_init`
- `mlx_new_window`
- `mlx_new_image`
- `mlx_get_data_addr`
- `mlx_put_image_to_window`
- `mlx_xpm_file_to_image`
- `mlx_destroy_image`
- `mlx_destroy_window`
- `mlx_destroy_display`
- `mlx_hook`
- `mlx_loop_hook`
- `mlx_loop`
- `mlx_mouse_hide`, `mlx_mouse_show`, `mlx_mouse_move` (bonus)
- `mlx_get_screen_size`

## 📚 Resources

### Raycasting Tutorials
- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive raycasting guide
- [Permadi's Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) - Step-by-step explanation
- [Ray-Casting Algorithms](https://rosettacode.org/wiki/Ray-casting_algorithm) - Code examples

### Technical Documentation
- [DDA Line Algorithm](https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/) - Digital Differential Analysis
- [Wolfenstein 3D Wikipedia](https://en.wikipedia.org/wiki/Wolfenstein_3D) - Historical context
- [Game Programming Patterns](http://gameprogrammingpatterns.com/) - Design patterns

### Video Tutorials
- [Make Your Own Raycaster](https://www.youtube.com/watch?v=gYRrGTC7GtA) - Complete implementation guide
- [Raycasting in C](https://www.youtube.com/watch?v=ebzlMOw79Yw) - Coding walkthrough
- [3D Graphics Programming](https://www.youtube.com/watch?v=TOEi6T2mtHo) - Theory and practice

### Additional Resources
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Library reference
- [cub3D Blog Post](https://ismailassil.medium.com/ray-casting-c-8bfae2c2fc13) - Project insights
- [Ray-Casting Tutorial](https://people.utm.my/shahabuddin/?p=6277) - Academic resource

## 🏆 Evaluation Criteria

### Mandatory Part
- [ ] Program compiles without errors
- [ ] No memory leaks
- [ ] Proper error handling
- [ ] Textures load correctly
- [ ] Wall rendering works
- [ ] Floor and ceiling colors display
- [ ] Player movement (WASD)
- [ ] Camera rotation (arrows)
- [ ] Map parsing validates correctly
- [ ] ESC and window close exit cleanly
- [ ] Map must be closed by walls

### Bonus Part
- [ ] Mandatory part is perfect
- [ ] Minimap displays correctly
- [ ] Doors open/close with animation
- [ ] Mouse control works
- [ ] Wall collisions function properly
- [ ] No crashes or undefined behavior

## ⚠️ Important Notes

### Norm Compliance
- All code must follow 42's coding norm
- Maximum 25 lines per function
- Maximum 5 functions per file
- Specific naming conventions
- Norm errors result in 0 grade

### MiniLibX
- May have internal leaks (acceptable)
- X11 required on Linux
- Different behavior on macOS/Linux
- Always test on school machines

### Memory Management
- Free all allocated memory
- Destroy all MLX images
- Close all file descriptors
- No leaks from your code

### Map Validation
- Must be surrounded by walls
- No holes in walls
- Only one player
- Valid characters only
- Proper file format

## 🎓 Learning Outcomes

- **Raycasting Algorithm**: Deep understanding of 3D projection from 2D
- **Graphics Programming**: Working with pixels, textures, and rendering
- **Mathematical Concepts**: Trigonometry, vectors, and linear algebra
- **Game Development**: Movement, collision, and game loop
- **File Parsing**: Robust configuration file handling
- **Memory Management**: Complex data structure allocation/cleanup
- **Event Handling**: Keyboard and mouse input processing

---

**Project completed as part of the 42 School curriculum by aghalmi & amoderan** 🚀

*Good luck with your implementation!*
