# miniRT - Project Tickets

## Project: miniRT - Ray Tracer Implementation
**Language:** C  
**Complexity:** Advanced  
**Total Estimated Time:** 60-75 hours

---

## EPIC: Complete Ray Tracing Engine

### TICKET #1: Project Setup & Architecture
**Status:** Not Started  
**Priority:** High  
**Estimated Time:** 4-5 hours

#### Description
Set up project structure and design architecture.

#### Tasks
1. **Research ray tracing concepts** (1.5 hours)
   - Understand ray-casting algorithm
   - Learn about intersection calculations
   - Study lighting models (ambient, diffuse, specular)
   - Research sphere, plane, cylinder intersections

2. **Design program architecture** (1.5 hours)
   - Plan data structure hierarchy
   - Design scene parser
   - Plan ray tracing algorithm flow
   - Design window management

3. **Set up development environment** (1 hour)
   - Create Makefile
   - Set up MinilibX linking
   - Create header files structure
   - Initialize git repository

---

### TICKET #2: Data Structures & Scene Model
**Status:** Not Started  
**Priority:** High  
**Estimated Time:** 6-8 hours

#### Description
Create essential data structures for scene representation.

#### Tasks
1. **Create vector and mathematical structures** (1.5 hours)
   - Define t_vec3 structure (x, y, z)
   - Vector operations: add, subtract, dot product, cross product
   - Normalize and magnitude functions
   - Scalar multiplication

2. **Create color structure** (1 hour)
   - Define t_color with R, G, B values
   - Color operations and validation
   - RGB to pixel conversion for display

3. **Create geometric object structures** (2 hours)
   - Define t_object base structure
   - Create t_sphere (center, diameter, color)
   - Create t_plane (point, normal, color)
   - Create t_cylinder (point, axis, diameter, height, color)
   - Object type identification

4. **Create lighting structures** (1 hour)
   - Define t_light (position, brightness, color)
   - Define t_ambient (ratio, color)
   - Light value constraints validation

5. **Create camera structure** (1 hour)
   - Define t_camera (position, orientation, FOV)
   - Direction vectors (right, up, forward)
   - Camera-to-world transformation
   - Field of view handling

---

### TICKET #3: Scene Parser
**Status:** Not Started  
**Priority:** High  
**Estimated Time:** 8-10 hours

#### Description
Implement parsing of .rt scene description files.

#### Tasks
1. **Design parser architecture** (1.5 hours)
   - Plan parsing strategy (line-by-line or full file)
   - Design token parsing
   - Error handling strategy
   - Plan validation

2. **Implement file I/O** (1.5 hours)
   - Create file reading function
   - Handle file errors
   - Line-by-line processing
   - Comment handling (if any)

3. **Implement element parsing** (3 hours)
   - Parse Ambient lighting (A)
   - Parse Camera (C)
   - Parse Light (L)
   - Parse Sphere (sp)
   - Parse Plane (pl)
   - Parse Cylinder (cy)
   - Handle element separation and ordering

4. **Implement coordinate and color parsing** (1.5 hours)
   - Parse x,y,z coordinates
   - Parse R,G,B color values
   - Parse normalized vectors
   - Range validation

5. **Error handling and validation** (1 hour)
   - Validate required elements (A, C, L)
   - Check duplicate declarations
   - Range checking for all values
   - Meaningful error messages

---

### TICKET #4: Ray Generation & Intersection
**Status:** Not Started  
**Priority:** High  
**Estimated Time:** 10-12 hours

#### Description
Implement ray generation and geometric intersection calculations.

#### Tasks
1. **Implement ray structure** (1 hour)
   - Define t_ray (origin, direction)
   - Ray point at distance calculation
   - Ray parameter handling

2. **Implement sphere intersection** (2.5 hours)
   - Ray-sphere intersection algorithm
   - Solve quadratic equation
   - Handle multiple intersections
   - Calculate intersection point and normal
   - Handle point inside sphere

3. **Implement plane intersection** (2 hours)
   - Ray-plane intersection algorithm
   - Handle parallel rays
   - Calculate intersection point
   - Normal calculation (always same)
   - Handle both sides of plane

4. **Implement cylinder intersection** (3 hours)
   - Ray-cylinder intersection (complex)
   - Handle cylindrical surface
   - Handle top and bottom caps
   - Calculate multiple intersection points
   - Select closest valid intersection
   - Normal at intersection point

5. **Create intersection result structure** (1 hour)
   - Define t_intersection
   - Store hit distance, point, normal, object
   - Closest intersection selection
   - Shadow ray optimization

6. **Implement closest intersection finder** (1.5 hours)
   - Test ray against all objects
   - Find closest intersection
   - Return intersection details
   - Handle no intersection case

---

### TICKET #5: Lighting & Shading
**Status:** Not Started  
**Priority:** High  
**Estimated Time:** 12-14 hours

#### Description
Implement lighting calculations and shading models.

#### Tasks
1. **Implement ambient lighting** (1.5 hours)
   - Apply ambient light to all objects
   - Multiply ambient ratio by object color
   - Ensure no complete darkness

2. **Implement diffuse lighting** (2.5 hours)
   - Calculate light direction from surface to light
   - Compute normal dot light direction
   - Apply brightness ratio
   - Accumulate with ambient lighting
   - Handle negative dot products

3. **Implement hard shadows** (3 hours)
   - Cast shadow ray from intersection to light
   - Check for object occlusion
   - If occluded, don't apply light
   - If not occluded, apply lighting
   - Handle epsilon for shadow acne prevention

4. **Implement specular reflection** (optional) (2 hours)
   - Calculate reflection direction
   - Compute eye to reflection angle
   - Apply specular highlight calculation
   - Smooth surface appearance

5. **Create lighting calculation function** (1.5 hours)
   - Combine all lighting components
   - Apply to pixel color
   - Clamp color values [0, 255]
   - Return final pixel color

6. **Optimize light calculations** (1.5 hours)
   - Cache light calculations
   - Early exit for heavy shadows
   - Performance profiling

---

### TICKET #6: Main Rendering Loop & Display
**Status:** Not Started  
**Priority:** High  
**Estimated Time:** 8-10 hours

#### Description
Implement ray tracing main loop and window display.

#### Tasks
1. **Set up MinilibX window** (1.5 hours)
   - Initialize MLX library
   - Create window
   - Create image/buffer
   - Handle window closing

2. **Implement ray generation per pixel** (2 hours)
   - Generate ray from camera through each pixel
   - Handle screen-to-world transformation
   - Correct FOV handling
   - Pixel sampling (1 ray per pixel for now)

3. **Implement main rendering loop** (2 hours)
   - For each pixel:
   - Generate ray
   - Find closest intersection
   - Calculate lighting
   - Write color to image buffer
   - Iterate through all pixels efficiently

4. **Implement image display** (1 hour)
   - Convert calculated colors to pixel format
   - Write image to window
   - Handle refresh

5. **Implement window event handling** (1.5 hours)
   - ESC key closes program
   - Window close button works
   - Proper cleanup on exit
   - No hanging processes

---

### TICKET #7: Object Transformations
**Status:** Not Started  
**Priority:** High  
**Estimated Time:** 8-10 hours

#### Description
Implement translation and rotation transformations.

#### Tasks
1. **Implement translation** (1.5 hours)
   - Translate objects by vector offset
   - Translate cameras
   - Translate lights
   - Update scene representation

2. **Implement rotation (3D)** (3.5 hours)
   - Implement rotation around X axis
   - Implement rotation around Y axis
   - Implement rotation around Z axis
   - Compose multiple rotations (order matters)
   - Rotation matrices

3. **Implement scaling** (1.5 hours)
   - Scale object dimensions
   - Sphere diameter scaling
   - Cylinder dimensions scaling
   - Maintain aspect ratios if needed

4. **Implement transformation composition** (1.5 hours)
   - Combine multiple transformations
   - Matrix multiplication
   - Apply to object and rays

---

### TICKET #8: Testing & Optimization
**Status:** Not Started  
**Priority:** Medium  
**Estimated Time:** 8-10 hours

#### Description
Test ray tracer and optimize performance.

#### Tasks
1. **Create test scene files** (1.5 hours)
   - Simple test scene (1 sphere)
   - Scene with multiple objects
   - Lighting test scenes
   - Transformation test scenes

2. **Functional testing** (2 hours)
   - Test sphere rendering
   - Test plane rendering
   - Test cylinder rendering
   - Test lighting effects
   - Test shadows

3. **Visual inspection** (1.5 hours)
   - Verify image quality
   - Check shadow accuracy
   - Validate lighting
   - Look for visual artifacts

4. **Performance profiling** (1.5 hours)
   - Measure FPS
   - Profile hotspots
   - Identify bottlenecks
   - Memory usage analysis

5. **Optimization** (1.5 hours)
   - Optimize intersection calculations
   - Cache frequently used values
   - Optimize lighting calculations
   - Reduce redundant calculations

---

### TICKET #9: Bonus Features (Optional)
**Status:** Not Started  
**Priority:** Low  
**Estimated Time:** 10-15 hours

#### Description
Implement advanced features for higher grade.

#### Tasks
1. **Anti-aliasing** (2 hours)
   - Multiple rays per pixel
   - Average pixel color
   - Smoother edges

2. **Additional shapes** (3-4 hours)
   - Cone implementation
   - Torus implementation
   - Box implementation
   - Proper intersection and normals

3. **Advanced lighting** (3-4 hours)
   - Specular highlights
   - Reflection rays (recursive)
   - Transparency/refraction
   - Fresnel effects

4. **Performance features** (2 hours)
   - Threading for parallel rendering
   - Bounding box optimization
   - Spatial partitioning (if time)

5. **Visual enhancements** (2 hours)
   - Texture mapping basics
   - Better color handling
   - Progressive rendering
   - Real-time preview with parameter changes

---

## Mathematical Foundations Required
1. **Vector Math:** Dot product, cross product, normalization
2. **Ray Math:** Parametric ray equations, ray-object intersections
3. **Lighting Models:** Ambient, diffuse, specular components
4. **Transformations:** Rotation matrices, translation, composition
5. **Linear Algebra:** Matrix operations, solving linear systems

---

## Development Standards
- **Language:** C with proper norm compliance
- **Compilation:** `-Wall -Wextra -Werror`
- **Makefile:** With all, clean, fclean, re, bonus rules
- **Memory:** No leaks (use valgrind)
- **Functions:** Use allowed library functions
- **No Global Variables:** (except environment variable for libft if needed)

---

## File Organization
```
src/
  ├── main.c
  ├── parser.c
  ├── ray_trace.c
  ├── objects.c
  ├── lighting.c
  ├── math/
  │   ├── vector.c
  │   ├── matrix.c
  │   └── intersections.c
  └── display.c

includes/
  ├── minirt.h
  ├── structures.h
  ├── math.h
  └── prototypes.h

Makefile
libft/ (copy of libft if used)
```

---

## Submission Checklist
- [ ] All mandatory features implemented
- [ ] Scene parser working correctly
- [ ] Ray tracing algorithm produces output
- [ ] Lighting calculations correct
- [ ] Shadows rendering properly
- [ ] Window displays image correctly
- [ ] Window management (ESC, close button)
- [ ] Code compiles with all flags
- [ ] No memory leaks
- [ ] No norm errors (if applicable)
- [ ] Test scene files included
- [ ] Makefiles correct (all, clean, fclean, re)
- [ ] Git repository with commits
- [ ] Bonus features working (if implemented)
