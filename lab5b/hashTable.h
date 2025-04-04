// This is the hash table I was copying from his notes in class.

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T> class HashTable {
public:
    HashTable(int size = 1000) : slots(size, T()) {}
    
    // Add an item to the hash table
    void add(const T& item) {
        int index = hash(item);
        while (slots[index] != T()) {  // While slot is not empty
            index = rehash(index);
        }
        slots[index] = item;
    }
    
    // Get an item from the hash table
    bool get(const T& item) const {
        int index = hash(item);
        int startIndex = index;
        
        while (slots[index] != T()) {  // While slot is not empty
            if (slots[index] == item) {
                return true;
            }
            index = rehash(index);
            if (index == startIndex) {  // We've searched the entire table
                return false;
            }
        }
        return false;
    }
    
    // Hash function
    int hash(const T& item) const {
        return std::abs(item) % slots.size();
    }
    
    // Rehash function (linear probing)
    int rehash(int index) const {
        return (index + 1) % slots.size();
    }
    
    // Quick load method
    void quickLoad(const std::vector<T>& listOfValues, double loadFactor) {
        int size = static_cast<int>(listOfValues.size() / loadFactor);
        slots.resize(size, T());
        
        for (const T& item : listOfValues) {
            add(item);
        }
    }
    
    // Get current size
    int size() const {
        return slots.size();
    }

private:
    std::vector<T> slots;
};

#endif // HASHTABLE_H
