#include <iostream>
#include <vector>

template <typename T> class HashTable {
private:
  std::vector<T> initVec; // vector to store the elements
  std::vector<bool> in;   // slots that have values
  int count;              // # of items in hashtable
  float loadFactor;

public:
  HashTable();
  ~HashTable();
};
