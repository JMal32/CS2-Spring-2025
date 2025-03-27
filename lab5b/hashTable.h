// This is the hash table I was copying from his notes in class.

#include <iostream>
#include <vector>

template <typename T> class HashTable {
public:
  HashTable(int size);
  ~HashTable();
  T hash();

private:
  std::vector<std::vector<T>> table;
};

template <typename T>
HashTable<T>::HashTable(int size) : table(size) {
}

template <typename T> int HashTable<T>::hash(T size, T item){
  
}
