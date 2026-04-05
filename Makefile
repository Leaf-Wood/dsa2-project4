CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O3

TARGET = main

OBJS = main.o Algorithms.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Bin.hpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

algorithms.o: Algorithms.cpp Bin.hpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c Algorithms.cpp

clean:
	rm -f *.o $(TARGET)