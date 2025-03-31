# FdF - 3D Wireframe Renderer

<p align="center">
  <a href="README_pt-br.md">
    <img src="https://img.shields.io/badge/Leia%20em-Português-brightgreen?style=for-the-badge" alt="Leia em Português">
  </a>
</p>

<p align="center">
  <img src="https://github.com/magalhaesm/fdf/assets/32808884/5675bd55-4211-4a20-95ed-c251c8f1fe59" alt="FdF Project Banner" width="800">
</p>

## Overview

FdF (Fil de Fer, "wireframe" in French) is a 3D wireframe renderer that creates a graphical representation of a landscape from a file containing elevation data. This project is part of the 42 curriculum and focuses on the basics of computer graphics programming, including:

- Creating and managing a window with MiniLibX
- Drawing lines with the Bresenham algorithm
- 3D to 2D projections (isometric and orthographic)
- Basic 3D transformations (translation, rotation, scaling)
- Color handling and gradients

## Features

- Read and parse map files with height information
- Render 3D wireframe landscapes in isometric and orthographic projections
- Color interpretation from map files (when specified) or default scheme based on elevation
- Real-time transformation capabilities:
  - Rotation around X, Y, and Z axes
  - Zoom in/out
  - Translation (move the model in any direction)
  - Adjust height scaling
- Interactive controls with on-screen legend
- Responsive window management
- Gradient color for lines based on elevation

## Usage

```bash
# Compile the program
make

# Run the program with a map file
./fdf maps/42.fdf

# Show the controls
Press '/' during execution
```

## Controls

### Camera Movement
- **Arrow Keys**: Move the model in four directions

### Rotation
- **W/S**: Rotate around X-axis
- **A/D**: Rotate around Y-axis
- **Q/E**: Rotate around Z-axis

### Zoom
- **+**: Zoom in
- **-**: Zoom out

### Altitude Adjustment
- **[**: Increase height scaling
- **]**: Decrease height scaling

### Projection
- **I**: Isometric projection
- **O**: Orthographic projection

### Other
- **R**: Reset to default view
- **ESC**: Close the program
- **/**: Show/hide controls panel

## Map Format

Maps are represented as grid-like text files where each number represents a point in 3D space:
- Horizontal position corresponds to its X coordinate
- Vertical position corresponds to its Y coordinate
- The value corresponds to its Z coordinate (height/elevation)

Optional hexadecimal values after a comma determine the color of each point:

```
0  0  0  0  0  0  0  0  0  0
0 10,0xFF0000 10 10 10 10 10 10 10  0
0 10 10,0x00FF00 10 10 10 10 10 10  0
0 10 10 10,0x0000FF 10 10 10 10 10  0
0 10 10 10 10 10 10 10 10  0
0  0  0  0  0  0  0  0  0  0
```

## Technical Implementation

### Core Components

- **MiniLibX**: A simple X-Window programming API used for rendering
- **Parsing System**: Robust file parsing with error handling
- **Bresenham's Line Algorithm**: Optimized for drawing lines between points
- **Matrix Transformations**: For rotations, scaling, and translations
- **Color Gradient**: Interpolation between points for smooth color transitions

### Project Structure

- **src/**: Source files
  - **main.c**: Entry point
  - **scene.c**: 3D scene management
  - **load_data.c**: Map file parsing
  - **draw_line.c**: Line drawing algorithm
  - **rotation.c**: 3D rotation mathematics
  - **transform.c**: Model transformations
  - **events.c**: User input handling
  - **controls.c**: UI controls and legend
- **include/**: Header files
- **libft/**: Custom C library with utility functions
- **maps/**: Sample map files

## Compilation

The project compiles with the following flags:
```
-Wall -Wextra -Werror -O3
```

And links against:
```
-lmlx -lXext -lX11 -lm
```

## Developed by
Marcelo Magalhães (mdias-ma) - 42 São Paulo
