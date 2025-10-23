cmake_minimum_required(VERSION 3.15)
project(Raytracer LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wunused -Wextra -Wpedantic -g3")

set(EXEC_NAME raytracer)

file(GLOB SOURCES src/*.cpp
    src/file_manager/*.cpp
    src/parser/*.cpp src/parser/getters/*.cpp src/parser/data_getter/*.cpp src/parser/data_getter/types/*.cpp
    src/elementary_data/*.cpp
    src/objects/*.cpp src/objects/camera/*.cpp src/objects/light/*.cpp src/objects/primitives/*.cpp
    src/pixel_buffer/*.cpp
    src/raytracing/*.cpp
    src/graphic_render/*.cpp)

find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)
add_executable(${EXEC_NAME} ${SOURCES})

target_link_libraries(${EXEC_NAME}
  PRIVATE
    nlohmann_json::nlohmann_json
    sfml-graphics
    sfml-window
    sfml-system
)
