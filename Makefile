# Compiler
CXX = g++
CXXFLAGS = -IUtilities -std=c++17 -Wall

# Source files
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = main

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile cpp -> object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f src/*.o $(TARGET)
