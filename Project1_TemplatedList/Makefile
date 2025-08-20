CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -O2

BIN=templated_list

all: $(BIN)

$(BIN): mydriver.cpp
	$(CXX) $(CXXFLAGS) -o $@ mydriver.cpp

clean:
	rm -f $(BIN)
