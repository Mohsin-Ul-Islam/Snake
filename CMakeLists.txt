project(Snake)
include_directories(./include ./src)
add_executable(run ./src/main.cpp ./src/Game.cpp ./src/Window.cpp ./src/Controller.cpp ./src/Snake.cpp)
