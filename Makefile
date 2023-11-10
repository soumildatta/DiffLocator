# Makefile for difflocator

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -O3 -std=c++17

# Target binary name
TARGET = difflocator

# Source files
SRC = main.cpp
HELPERS = Colors.h timer.h

# Compile the program
$(TARGET): $(SRC) $(HELPERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean target
clean:
	rm -f $(TARGET)
