#include "HashTable.h"
using namespace std;

HashTable::HashTable(int initialSize) {
    slots.resize(initialSize, -1);
    size = initialSize;
}

int HashTable::hash(int key) {
    return key % size;
}

int HashTable::rehash(int index) {
    return (index + 1) % size;
}

void HashTable::add(int item) {
    int index = hash(item);
    while (slots[index] != -1) {
        index = rehash(index);
    }
    slots[index] = item;
}

bool HashTable::get(int item) {
    int index = hash(item);
    int start = index;
    
    while (slots[index] != -1) {
        if (slots[index] == item) {
            return true;
        }
        index = rehash(index);
        if (index == start) {
            return false;
        }
    }
    return false;
}

void HashTable::quickLoad(const vector<int>& listOfValues, double loadFactor) {
    int newSize = static_cast<int>(listOfValues.size() / loadFactor);
    slots.clear();
    slots.resize(newSize, -1);
    size = newSize;
    
    for (int value : listOfValues) {
        add(value);
    }
} 