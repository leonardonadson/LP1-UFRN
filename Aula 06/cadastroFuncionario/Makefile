# Makefile 
CXX      := g++
CXXFLAGS := -Iinclude_cpp -std=c++17 -Wall

# Make expande os arquivos .c e .cpp
SRCS_CPP := $(wildcard *.cpp)

.PHONY: all clean test_cpp

all: test_cpp

test_cpp:
	$(CXX) $(CXXFLAGS) $(SRCS_CPP) -o final_cpp
	./final_cpp

clean:
	rm -f final_cpp