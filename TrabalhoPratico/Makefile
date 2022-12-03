SRC_DIR = src
BUILD_DIR = build
CC = g++
SRC_FILES = $(wildcard temp/*.cpp)
OBJ_NAME = tp
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -L/opt/homebrew/Cellar/sdl2/2.26.0/lib/ -L/opt/homebrew/Cellar/sdl2_image/2.6.2/lib
COMPILER_FLAGS = -std=c++20
LINKER_FLAGS = -lsdl2 -lsdl2_image

all: builder executer

builder:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
executer:
	./$(BUILD_DIR)/$(OBJ_NAME)