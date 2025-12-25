# Quick Start - miniRT (Ray Tracing)

## Project Overview
Build a ray tracer from scratch using mathematical and graphics algorithms.

**Language:** C | **Time:** 60-75 hours | **Difficulty:** Advanced

---

## What You'll Build
A program that:
1. Reads a scene description file (.rt format)
2. Generates a 3D rendered image using ray tracing
3. Displays the result in a window
4. Implements lighting, shadows, and transformations

---

## Core Concepts

### Ray Tracing Pipeline
```
For each pixel:
  1. Generate ray from camera through pixel
  2. Find closest object intersection
  3. Calculate lighting at intersection point
  4. Handle shadows
  5. Combine colors
  6. Display pixel
```

### Required Objects
- **Sphere:** Center, diameter, color
- **Plane:** Point, normal, color
- **Cylinder:** Point, axis, diameter, height, color

### Lighting Model
- **Ambient:** Base light on all surfaces
- **Diffuse:** Light based on surface angle
- **Shadows:** Hard shadows (object either lit or dark)

### Transformations
- **Translation:** Move objects in 3D space
- **Rotation:** Rotate around axes
- **Scaling:** Change object size

---

## Scene File Format (.rt)

```
# Ambient lighting
A 0.2 255,255,255

# Camera (position, orientation, FOV)
C -50.0,0,20 0,0,1 70

# Light (position, brightness, color)
L -40.0,50.0,0.0 0.6 10,0,255

# Objects
sp 0.0,0.0,20.6 12.6 10,0,255
pl 0,0,0 0,0,1 255,0,0
cy 0,0,0 0,1,0 14.2 21.42 220,20,60
```

---

## Implementation Phases

### Phase 1: Parsing (8-10h)
- [ ] Read and parse .rt file
- [ ] Validate scene elements
- [ ] Store scene in data structures
- [ ] Error handling

### Phase 2: Core Ray Tracing (12-14h)
- [ ] Vector mathematics library
- [ ] Ray generation from camera
- [ ] Ray-sphere intersection
- [ ] Ray-plane intersection
- [ ] Ray-cylinder intersection

### Phase 3: Lighting (12-14h)
- [ ] Ambient lighting calculation
- [ ] Diffuse lighting calculation
- [ ] Shadow ray casting
- [ ] Combined lighting model

### Phase 4: Display (8-10h)
- [ ] MinilibX window creation
- [ ] Image buffer management
- [ ] Color rendering to pixels
- [ ] Event handling (ESC, window close)

### Phase 5: Transformations (8-10h)
- [ ] Translation implementation
- [ ] 3D rotation matrices
- [ ] Apply to objects and cameras
- [ ] Transformation composition

### Phase 6: Testing & Optimization (6-8h)
- [ ] Test scenes
- [ ] Visual validation
- [ ] Performance optimization
- [ ] Edge case handling

---

## Mathematical Requirements

### Vector Operations
```c
typedef struct s_vec3 {
  double x, y, z;
} t_vec3;

// Operations needed:
// - Add, subtract vectors
// - Dot product (lighting)
// - Cross product (normals)
// - Normalize vector
// - Scale vector
```

### Ray-Sphere Intersection
```
Solve: |origin + t*direction - center|² = radius²
Results in quadratic equation in t
Find closest positive t
```

### Ray-Plane Intersection
```
Solve: (origin + t*direction - point) · normal = 0
Simple linear equation
```

### Ray-Cylinder Intersection
```
Most complex:
1. Intersect with infinite cylinder surface
2. Check if within height bounds
3. Check intersection with end caps
4. Calculate normal at intersection
```

---

## Data Structure Overview

```c
typedef struct s_scene {
  t_ambient  ambient;
  t_camera   camera;
  t_light    light;      // One light for mandatory part
  t_object   *objects;   // Linked list
} t_scene;

typedef struct s_object {
  int        type;        // SPHERE, PLANE, CYLINDER
  t_vec3     position;
  t_vec3     orientation;
  double     param1;      // diameter/width
  double     param2;      // height for cylinder
  t_color    color;
  struct s_object *next;
} t_object;

typedef struct s_intersection {
  double    distance;
  t_vec3    point;
  t_vec3    normal;
  t_object  *object;
} t_intersection;
```

---

## Implementation Checklist

### Parser
- [ ] Open and read .rt file
- [ ] Parse ambient line (A)
- [ ] Parse camera line (C)
- [ ] Parse light lines (L)
- [ ] Parse object lines (sp, pl, cy)
- [ ] Validate all required elements
- [ ] Error messages for invalid input

### Mathematics
- [ ] Vector struct and operations
- [ ] Color struct and operations
- [ ] Matrix for rotations
- [ ] Intersection algorithms

### Ray Tracing Core
- [ ] Ray generation from pixel
- [ ] Scene object intersection
- [ ] Closest hit detection
- [ ] Normal calculation

### Lighting
- [ ] Ambient light application
- [ ] Diffuse light calculation
- [ ] Shadow ray casting
- [ ] Shadow detection

### Display
- [ ] MinilibX window creation
- [ ] Image buffer allocation
- [ ] Pixel writing
- [ ] Image display
- [ ] Event handling

### Transformations
- [ ] Translation for objects
- [ ] Rotation around axes
- [ ] Camera transformations
- [ ] Light transformations

---

## Common Challenges

1. **Cylinder Intersection** - Most complex geometry
2. **Shadow Acne** - Use epsilon for shadow rays
3. **Numerical Precision** - Handle floating point errors
4. **Performance** - Optimize for many objects
5. **Rotation Matrices** - Get order correct

---

## Testing Approach

1. **Start simple:** One sphere, single light
2. **Add complexity:** Multiple objects
3. **Test lighting:** Verify shadows work
4. **Test transformations:** Rotate and move objects
5. **Edge cases:** Objects at extreme positions
6. **Performance:** Measure FPS, optimize hotspots

---

## Bonus Features (Optional)

- Anti-aliasing (multiple rays per pixel)
- Additional shapes (cone, box, torus)
- Reflections (recursive ray tracing)
- Textures/patterns
- Specular highlights
- Parallel rendering with threads

---

## Success Criteria

✅ Scene file parser works  
✅ Ray tracing produces image  
✅ All 3 shapes render correctly  
✅ Lighting calculations accurate  
✅ Shadows display properly  
✅ Window management works  
✅ Transformations functional  
✅ No memory leaks  
✅ No segmentation faults  
✅ Compiles with `-Wall -Wextra -Werror`  

---

## Repository Structure
```
miniRT/
├── README.md
├── TICKETS.md
├── Makefile
├── src/
│   ├── main.c
│   ├── parser.c
│   ├── ray_trace.c
│   ├── lighting.c
│   ├── math/
│   └── display.c
├── includes/
│   ├── minirt.h
│   └── structures.h
├── scenes/
│   ├── test1.rt
│   ├── test2.rt
│   └── bonus.rt
└── .git/
```

---

See detailed TICKETS.md for complete 9-ticket breakdown.
