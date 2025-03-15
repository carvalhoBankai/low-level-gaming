CXX = g++
CXXFLAGS = -std=c++11 $(shell pkg-config --cflags raylib) -Iinclude 
LDFLAGS = $(shell pkg-config --libs raylib) -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC_DIR = src
OBJ_DIR = obj
BIN = game

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Default target
all: $(BIN)

# Compile the executable
$(BIN): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up compiled files
clean:
	rm -rf $(OBJ_DIR) $(BIN)

#run the game
run: $(BIN)
	./$(BIN)