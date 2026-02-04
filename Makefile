# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -IUtilities

# Source files
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = main

# Default rule
all: src/pch.h.gch $(TARGET)

# Link executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp -> .o using precompiled header
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -include ../pch.h -c $< -o $@

# Precompiled header
src/pch.h.gch: pch.h
	$(CXX) $(CXXFLAGS) -x c++-header pch.h -o src/pch.h.gch

# Clean build files
clean:
	rm -f src/*.o $(TARGET) src/pch.h.gch
