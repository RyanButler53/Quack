CXX = clang++
CXXFLAGS = -std=c++2a -g -O2 -Wall -pedantic
TARGET = experiment

all: $(TARGET)

experiment: experiment.o
	$(CXX) -o experiment experiment.o

experiment.o: experiment.cpp quack.hpp quack-private.hpp
	$(CXX) -c experiment.cpp $(CXXFLAGS)

clean: 
	rm -rf $(TARGET) *.o