#include <iostream>
#include <vector>

using namespace std;

template <typename T> class HashTable {
private:
  vector<T> slots;
  vector<bool> occupied;
  int size;

  // Private method declarations
  int hash(const T &item) const;
  int rehash(int index) const; // Linear probing collision resolution

public:
  HashTable();
  void quickLoad(const vector<T> &listOfValues, float loadFactor);
  void add(const T &item);
  bool get(const T &item) const;
};

template <typename T> HashTable<T>::HashTable() : size(1000) {
  slots.resize(size);
  occupied.resize(size, false);
}

template <typename T> int HashTable<T>::hash(const T &item) const {
  return item % size;
}

template <typename T> int HashTable<T>::rehash(int index) const {
  // When a collision occurs, we simply move to the next slot
  // until we find an empty slot or the item we're looking for.
  return (index + 1) % size;
}

template <typename T>
void HashTable<T>::quickLoad(const vector<T> &listOfValues, float loadFactor) {
  size = static_cast<int>(listOfValues.size() / loadFactor);
  slots.resize(size);
  occupied.resize(size, false);

  for (const T &item : listOfValues) {
    add(item);
  }
}

template <typename T> void HashTable<T>::add(const T &item) {
  int index = hash(item);
  while (occupied[index]) {
    index = rehash(index);
  }
  slots[index] = item;
  occupied[index] = true;
}

template <typename T> bool HashTable<T>::get(const T &item) const {
  int index = hash(item);
  int startIndex = index;
  while (occupied[index]) {
    if (slots[index] == item) {
      return true;
    }
    index = rehash(index);
    if (index == startIndex) {
      break;
    }
  }
  return false;
}
