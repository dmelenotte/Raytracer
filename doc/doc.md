# Scene File Parsing and Raycasting Approach

This project uses a JSON scene file to describe all objects including: lights, camera and primitives.
The JSON is parsed and mapped directly to in-memory objects or structures, forming the basis for rendering.

# JSON Parsing
The JSON parsing is handled by a dedicated parser that reads the scene file and constructs the corresponding objects in memory.
The parser is designed to be extensible, allowing for easy addition of new object types or properties in the future.
The scene file can include various elements such as spheres, planes, and lights, each defined with their respective properties.
The parser uses a factory pattern to create instances of these objects based on the JSON data.
The JSON structure is designed to be intuitive and easy to modify, enabling users to create complex scenes with minimal effort.
The parser also includes error handling to ensure that any issues with the JSON file are reported clearly, allowing for quick debugging.

Here is a simple example of a scene file that describes a camera, a plane, and a sphere. The raytracer will render the scene based on this description:
```json
{
  "camera": {
    "resolution": {
      "width": 1920,
      "height": 1080
    },
    "position": {"x": 0, "y": 0, "z": 30},
    "rotation": {"x": 5, "y": 15, "z": 0},
    "fieldOfView": 90.0,
    "depth": 1
  },
  "primitives": {
    "planes": [
      {
        "axis": "Y",
        "position": -30,
        "color": {"r": 215, "g": 219, "b": 211},
        "albedo": {"x": 100, "y": 100, "z": 100},
        "reflection": {"x": 100, "y": 100, "z": 100}
      }
    ],
    "spheres": [
      {
        "position": {"x": 0, "y": -20, "z": 100},
        "radius": 25.0,
        "color": {"r": 18, "g": 237, "b": 14},
        "albedo": {"x": 100, "y": 100, "z": 100},
        "reflection": {"x": 100, "y": 100, "z": 100}
      }
    ],
    "boxs": [
      {
        "position": {"x": 60, "y": -10, "z": 100},
        "width" : 80,
        "height": 10,
        "depth" : 80,
        "direction": {"x": 0, "y": 0, "z": -10},
        "color": {"r": 64, "g": 64, "b": 255},
        "albedo": {"x": 100, "y": 100, "z": 100},
        "reflection": {"x": 100, "y": 100, "z": 100}
      }
    ]
  },
  "lights": {
    "ambient": {
      "intensity": 0.2
    },
    "directionals": [
      {
        "intensity": 4.0,
        "shininess": 12.0,
        "direction": {"x": 1, "y": -1, "z": 0}
      }
    ]
  }
}
```
[image exemple](./exemple.png)

## requirements for the camera
- `resolution`: Specifies the width and height of the rendered image.
- `position`: Defines the camera's position in 3D space.
- `rotation`: Specifies the camera's rotation in 3D space.
- `fieldOfView`: Defines the camera's field of view in degrees.
- `depth`: Specifies the depth of field for the camera.
## requirements for the primitives

- `planes`: Defined by axis (`"X"`, `"Y"`, or `"Z"`), position (float), color (RGB), albedo (vector3), and reflection (vector3).
  - **axis**: `"X"`, `"Y"`, or `"Z"`
  - **position**: float (no strict min/max, but typically within scene bounds)
  - **color**: `r`, `g`, `b` (integers, min: 0, max: 255)
  - **albedo**: `x`, `y`, `z` (integers, min: 0, max: 100)
  - **reflection**: `x`, `y`, `z` (integers, min: 0, max: 100)
  ```json
  {
    "axis": "X|Y|Z",
    "position": 10,
    "color": {"r": 18, "g": 237, "b": 14},
    "albedo": {"x": 100, "y": 100, "z": 100},
    "reflection": {"x": 100, "y": 100, "z": 100}
  }
  ```

- `spheres`: Defined by position (vector3), radius (float), color (RGB), albedo (vector3), and reflection (vector3).
  - **position**: `x`, `y`, `z` (floats, scene bounds)
  - **radius**: float (min: >0.0)
  - **color**: `r`, `g`, `b` (integers, min: 0, max: 255)
  - **albedo**: `x`, `y`, `z` (integers, min: 0, max: 100)
  - **reflection**: `x`, `y`, `z` (integers, min: 0, max: 100)
  ```json
  {
    "position": {"x": 60, "y": -10, "z": 100},
    "radius": 1.2,
    "color": {"r": 18, "g": 237, "b": 14},
    "albedo": {"x": 100, "y": 100, "z": 100},
    "reflection": {"x": 100, "y": 100, "z": 100}
  }
  ```

- `cones`: Defined by position (vector3), radius (float), color (RGB), albedo (vector3), and reflection (vector3).
  - **position**: `x`, `y`, `z` (floats, scene bounds)
  - **radius**: float (min: >0.0)
  - **color**: `r`, `g`, `b` (integers, min: 0, max: 255)
  - **albedo**: `x`, `y`, `z` (integers, min: 0, max: 100)
  - **reflection**: `x`, `y`, `z` (integers, min: 0, max: 100)
  ```json
  {
    "position": {"x": 60, "y": -10, "z": 100},
    "radius": 1.2,
    "color": {"r": 18, "g": 237, "b": 14},
    "albedo": {"x": 100, "y": 100, "z": 100},
    "reflection": {"x": 100, "y": 100, "z": 100}
  }
  ```

- `cylinders`: Defined by position (vector3), radius (float), color (RGB), albedo (vector3), and reflection (vector3).
  - **position**: `x`, `y`, `z` (floats, scene bounds)
  - **radius**: float (min: >0.0)
  - **color**: `r`, `g`, `b` (integers, min: 0, max: 255)
  - **albedo**: `x`, `y`, `z` (integers, min: 0, max: 100)
  - **reflection**: `x`, `y`, `z` (integers, min: 0, max: 100)
  ```json
  {
    "position": {"x": 60, "y": -10, "z": 100},
    "radius": 1.2,
    "color": {"r": 18, "g": 237, "b": 14},
    "albedo": {"x": 100, "y": 100, "z": 100},
    "reflection": {"x": 100, "y": 100, "z": 100}
  }
  ```

- `boxs`: Defined by position (vector3), width, height, depth (float), color (RGB), albedo (vector3), and reflection (vector3).
  - **position**: `x`, `y`, `z` (floats, scene bounds)
  - **width**, **height**, **depth**: float (min: >0.0)
  - **color**: `r`, `g`, `b` (integers, min: 0, max: 255)
  - **albedo**: `x`, `y`, `z` (integers, min: 0, max: 100)
  - **reflection**: `x`, `y`, `z` (integers, min: 0, max: 100)
  ```json
  {
    "position": {"x": 60, "y": -10, "z": 100},
    "width": 3,
    "height": 5,
    "depth": 8,
    "color": {"r": 18, "g": 237, "b": 14},
    "albedo": {"x": 100, "y": 100, "z": 100},
    "reflection": {"x": 100, "y": 100, "z": 100}
  }
  ```

## requirements for the lights
- `ambient`: To build the ambient light you need to specifie the intensity between 0 and 1.
```json
"ambient": {
      "intensity": 0.3
    },
```
- `directionals`: To build the directional light you need to specifie the diffuse intensity between 0 and 1, shininess, and direction in 3D space.
  - **intensity**: float (min: 0.0)
  - **shininess**: float (min: 0.0)
  - **direction**: `x`, `y`, `z` (floats, scene bounds)
```json
{
  "directionals": [
    {
      "intensity": 0.3,
      "shininess": 0.5,
      "direction": {"x": 2.3, "y": 4.6, "z": 3.5}
    }
  ]
}
```

# Design Patterns

### Factory Pattern
Handles the instantiation of scene elements (like spheres, planes, and lights) from the JSON scene file.
This allows for flexible and dynamic scene construction based on the file's content.

### Composite Pattern
Organizes the collect of the scene objects into a tree structure, allowing for easy management of complex scenes.
This pattern is particularly useful for grouping objects that share common properties or behaviors, such as materials or transformations.

### Observer Pattern
Enables components (such as the renderer or UI) to react to changes in the scene, ensuring updates are propagated throughout the application.

# Raycasting Approach

Once the scene is parsed from the JSON file, the raycasting implementation iterates through all scene objects, testing each for ray intersections.
Each object type implements a shared interface for intersection logic, making it straightforward to add new shapes or behaviors.
The raycasting loop is designed for clarity and extensibility, so new features or optimizations can be integrated easily.

## Example: Ray and Sphere Intersection

Below is an example demonstrating how a `Ray` and a `Sphere` interact during raycasting, using modern C++ and typical class interfaces:

```cpp
#include "Ray.hpp"
#include "Sphere.hpp"

Ray ray(Position(0, 0, 0), Vector(1, 0, 0));
Vector normal(0, 0, 0);
Sphere Sphere(Position(2,44,4), 2.3, Color(25,46,53), Color(50, 50, 50), Color(100, 100, 100));

float t = 0.0f;
if (sphere.hit(ray, t)) {
  // The ray intersects the sphere at distance t
  // Intersection point: ray.origin + t * ray.direction
}
```

Each primitive (like `Sphere`) implements an `hit` method that checks for intersection with a given `Ray`, reference `t (distance)`, reference `normal` and returns a boolean if there is a hit between objects.

A typical raycasting loop over all scene objects looks like this:

```cpp
float closestT = std::numeric_limits<float>::max();

for (const auto& object : sceneObjects) {
  float t = 0.0f;
  if (object->hit(ray, t) && t < closestT) {
    closestT = t;
    // Compute shading and lighting at the intersection point
  }
}

```

## how to build objects
To add a new object type:

1. **Create the class:**  
    Make a new class (e.g., `Box`) that inherits from the base object interface and implements the `intersect` method.

2. **Add to the factory:**  
    In `ObjectsFactory`, add a creation method for your object (e.g., `createBox`) and register it in the factory map.

3. **Update the parser:**  
    Modify the JSON parser to recognize your new object type and call the factory with the right parameters.

4. **Test:**  
    Add your object to a scene JSON and check that it parses and renders correctly.


## Benefits

- Keeps scene description and logic modular and maintainable.
- Simplifies handling of complex, extensible scenes.
- Makes it easy to add new object types or rendering features.
- Ensures clear separation between scene parsing and raycasting logic.

# Dependencies
- C++20
- CMake
- Nlohmann JSON library : ``` https://github.com/nlohmann/json.git```
- SFML