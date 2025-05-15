CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
TARGET = bin/app
SRCS = src/main.cpp src/OperableString.cpp

all:
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf bin
