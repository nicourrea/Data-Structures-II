# Define compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Name of the executable
EXEC = proj4.x

# Source files
SOURCES = proj4.cpp passserver.cpp base64.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^  # Make sure this line starts with a tab

# Rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<  # This line should also start with a tab

# Clean target
clean:
	rm -f $(OBJECTS) $(EXEC)  # And this line

# Custom target for testing
test:
	./$(EXEC) < test1 > outtest1  # This line as well

.PHONY: all clean test
