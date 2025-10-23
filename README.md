# Raytracer

## About the Project

Ray tracing is a powerful technique for generating realistic digital images by simulating the behavior of light. This project focuses on implementing a basic raytracer capable of rendering 3D scenes with features such as spheres, planes, and basic lighting. Designed with simplicity and extensibility in mind, this raytracer serves as a foundation for further enhancements and experimentation.

---

## Project Objectives

The primary objective of this project is to develop a functional raytracer that can interpret and render 3D scenes described in external files. It's about raytracing and raycasting techniques, the project aims to provide a clear and modular implementation that can be expanded with additional features.

---

## How to Bluid
To build the project, you need to have the following dependencies installed:
- CMake
- A C++ compiler (g++, clang++)
To build the project, follow these steps:
``` bash
git clone git@github.com:dmelenotte/Raytracer.git
cd Raytracer
./build.sh
```
To clean the project, you can use the following command:
``` bash
./clean.sh
```

---

## How to Use

To run the raytracer, use the following command:

```bash
./raytracer <SCENE_FILE>.json
```

Replace `<SCENE_FILE>` with the path to your scene description file in JSON extention.
The output will be saved as an image file in the current directory.
To see the picture, you can use the following command:
```bash
ffmpeg -i <OUTPUT_FILE>.ppm <OUTPUT_FILE>.png
```
---

## Documentation

Comprehensive documentation for the project is available [here](./doc/doc.md). It includes details about the design patterns used, JSON parsing, instructions for adding new objects, and more.
