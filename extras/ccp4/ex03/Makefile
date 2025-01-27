# Target executable name (Change this if needed)
TARGET := a.out
# Compiler and flags
CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Directories
OBJ_DIR := obj

# Source files
SRCS := main.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp AMateria.cpp

# Object files
OBJS := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling source files to object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -rf $(OBJ_DIR)

# Additional target to remove generated files and the executable
fclean: clean
	rm -f $(TARGET)

# Recompile everything
re: fclean all

# Phony targets to avoid filename conflicts
.PHONY: all clean fclean re
