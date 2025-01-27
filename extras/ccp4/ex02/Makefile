
# Target executable name (Change this if needed)
TARGET := Abstract
# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Directories
OBJ_DIR := obj


# Source files
SRCS := main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp

# Object files
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Additional target to remove generated files and the executable
fclean: clean
	rm -f $(TARGET)

# Recompile everything
re: fclean all

# Phony targets to avoid filename conflicts
.PHONY: all clean fclean re
