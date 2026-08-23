*This project has been created as part of the 42 curriculum by asando and radandri.*

# miniRT

## Description

miniRT is a small ray tracer written in C as part of the 42 curriculum. It
generates a computer-rendered image from a scene description file and displays
the result in a window using MLX42.

The renderer supports the mandatory geometric objects:

- spheres (`sp`)
- planes (`pl`)
- cylinders (`cy`), including their end caps

It also supports ambient and diffuse lighting, multiple light sources, hard
shadows, camera orientation, object translation and rotation, and specular
highlights. Scene input is validated and malformed files are rejected with an
explicit error message.

## Features

- Ray-object intersection for spheres, planes and finite cylinders
- Cylinder diameter and height configuration
- Multiple objects of the same or different types
- Multiple light sources
- Ambient, diffuse and specular lighting
- Hard-shadow computation
- Camera field of view and arbitrary normalized orientation
- Object transformations using optional translation (`T`) and rotation (`R`)
- Clean exit with `ESC` or the window close button

## Instructions

### Requirements

The project requires a C compiler, `make`, CMake, GLFW and the development
libraries needed by MLX42. On WSL Debian, install them with:

```bash
sudo apt update
sudo apt install build-essential cmake libglfw3-dev libx11-dev \
	libxrandr-dev libxi-dev libxcursor-dev libxinerama-dev
```

On Linux Debian or Ubuntu, install them with:
```bash
sudo apt-get update
sudo apt-get install -y build-essential git libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libglfw3-dev
```

Libft and MLX42 are included as Git submodules. If they are not present yet,
the Makefile initializes them automatically. They can also be initialized
manually with:

```bash
git submodule update --init --recursive
```

### Compilation

Build the project with:

```bash
make
```

This creates the `miniRT` executable. Other available Makefile rules are:

```bash
make clean   # Remove project object files and clean Libft
make fclean  # Remove object files, libraries and the executable
make re      # Clean everything and rebuild
```

### Execution

Run the program with one `.rt` scene file:

```bash
./miniRT assets/tests/01_sphere_basic.rt
```

The window can be closed with the `ESC` key or its close button.

### Scene format

Each element starts with an identifier. Values can be separated by spaces or
line breaks, and elements may appear in any order. A minimal scene is:

```text
A 0.2 255,255,255
C 0,0,-20 0,0,1 70
L 0,10,-10 0.7 255,255,255
sp 0,0,0 8 255,0,0
pl 0,-4,0 0,1,0 200,200,200
cy 4,0,4 0,1,0 4 8 0,0,255
```

The supported identifiers and parameters are:

| Identifier | Parameters |
| --- | --- |
| `A` | ambient ratio, RGB color |
| `C` | position, normalized orientation, horizontal FOV |
| `L` | position, brightness ratio, RGB color |
| `sp` | center, diameter, RGB color |
| `pl` | point, normalized normal, RGB color |
| `cy` | center, normalized axis, diameter, height, RGB color |

Object lines may optionally be followed by transformations such as:

```text
sp 0,0,0 8 255,0,0 T 3,0,0 [R 0,0,1.5708] [T 1,2,3]
```

- Colors use integer RGB components from `0` to `255`.
- Ratios are in the range `0.0` to `1.0`.
- The camera FOV is in the range `0` to `180` degrees.

## Project Structure

- `src/parsing/`: scene-file parsing and validation
- `src/math/`: vectors, rays and mathematical operations
- `src/objects/`: geometric intersection routines
- `src/render/`: ray tracing, shading, shadows and MLX42 display
- `include/`: project data structures and function declarations
- `lib/libft/`: authorized 42 Libft dependency
- `lib/MLX42/`: MLX42 dependency

## Resources

- [Ray tracing in one weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
- The Ray Tracer Challenge by Jamis buck
- [French ray tracing ressources by Nicolas Bonneel](https://www.youtube.com/watch?v=1HYhrx9bzP8)
- [MLX42 documentation](https://github.com/codam-coding-college/MLX42)
- [Scratchapixel: Ray Tracing](https://www.scratchapixel.com/)

AI was used as a support tool for repetitive and tedious task:
- We used AI to generate test data, including possible inputs and expected outputs for ours different fonctions (eg: translations, rotations, normalized vectors, ...).
- Reviewing the README to improve wording.