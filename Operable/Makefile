CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp
OUT = bin/app

all:
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf bin
