# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = location_program

# Source files
SRC = main.cpp Location.cpp Place.cpp Region.cpp City.cpp Metropolis.cpp
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run