SRC_DIR = src
BUILD_DIR = build
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = tp
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -L/Users/josineyjunior/Documents/FACULDADE/AEDS/AEDSI/Lista01/TrabalhoPratico/lib/SDL2 -L/Users/josineyjunior/Documents/FACULDADE/AEDS/AEDSI/Lista01/TrabalhoPratico/lib/SDL2_image
COMPILER_FLAGS = -std=c++20
LINKER_FLAGS = -lsdl2 -lsdl2_image

all: builder executer

builder:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
executer:
	./$(BUILD_DIR)/$(OBJ_NAME)