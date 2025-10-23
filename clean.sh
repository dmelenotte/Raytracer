#!/bin/bash

# clean all project file
rm -rf raytracer
rm -rf build

# clean all tmp file
rm -rf ./*.png
rm -rf ./*.ppm
rm -rf ./**/*.o
rm -rf ./**/*.vgcore
rm -rf ./**/*.so
rm -rf ./**/*.out
rm -rf ./**/*.gcno
rm -rf ./**/*.gcda
rm -rf vgcore.*

echo -e "\e[1;35mClean Finished at $(date) ✔✔ \e[0m"
