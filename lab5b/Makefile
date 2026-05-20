CXX = g++
CXXFLAGS = -std=c++11

all: lab5b

lab5b: main.o HashTable.o
	$(CXX) $(CXXFLAGS) -o lab5b main.o HashTable.o

main.o: main.cpp HashTable.h
	$(CXX) $(CXXFLAGS) -c main.cpp

HashTable.o: HashTable.cpp HashTable.h
	$(CXX) $(CXXFLAGS) -c HashTable.cpp

clean:
	rm -f *.o lab5b 