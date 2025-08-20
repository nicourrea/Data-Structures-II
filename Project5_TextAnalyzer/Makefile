# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -g

# Source file
SOURCE = proj5.cpp

# Executable name
EXECUTABLE = proj5.x

# Test files and output files
TEST_FILES = test0 test1 test2 test3
OUTPUT_FILES = output0.txt output1.txt output2.txt output3.txt

# Default target to compile the executable
all: $(EXECUTABLE)

# Compile the source file into the executable
$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCE)

# Run the executable with each test file and save output to corresponding .txt files
run-tests: $(EXECUTABLE)
	./$(EXECUTABLE) < test0 > output0.txt
	./$(EXECUTABLE) < test1 > output1.txt
	./$(EXECUTABLE) < test2 > output2.txt
	./$(EXECUTABLE) < test3 > output3.txt

# Clean up the compiled executable and output files
clean:
	rm -f $(EXECUTABLE) $(OUTPUT_FILES)

.PHONY: all run-tests clean
