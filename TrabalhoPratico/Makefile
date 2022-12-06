SRC_DIR = src
BUILD_DIR = build
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = tp
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -L/home/daniel/Área de Trabalho/git/ufvjm/aeds-1/TrabalhoPratico/include/SDL2_image -L/home/daniel/Área de Trabalho/git/ufvjm/aeds-1/TrabalhoPratico/include/SDL2
COMPILER_FLAGS = -std=c++11
LINKER_FLAGS = -lsdl2 -lsdl2_image

all: builder executer

builder:
	$(CC) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
executer:
	./$(BUILD_DIR)/$(OBJ_NAME)