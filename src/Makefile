# Project structure
SRC_DIR  := .
INC_DIR  := ../include
OBJ_DIR  := obj
BIN_DIR  := bin

# Compiler and flags
CXX      := g++
CXXFLAGS := -ggdb -O0 -std=c++20 -Wall -Werror -I$(INC_DIR)

# Files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET := $(BIN_DIR)/main

# Default target
.PHONY: all
all: $(TARGET)

# Link step
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile step
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if missing
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Clean target
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
