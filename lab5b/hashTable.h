#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class HashTable {
private:
    vector<T> slots;
    vector<bool> occupied;
    int size;

    int hash(const T& item) const {
        return item % size;
    }

    int rehash(int index) const {
        return (index + 1) % size;
    }

public:
    HashTable() : size(1000) {
        slots.resize(size);
        occupied.resize(size, false);
    }

    void quickLoad(const vector<T>& listOfValues, float loadFactor) {
        size = static_cast<int>(listOfValues.size() / loadFactor);
        slots.resize(size);
        occupied.resize(size, false);
        
        for (const T& item : listOfValues) {
            add(item);
        }
    }

    void add(const T& item) {
        int index = hash(item);
        while (occupied[index]) {
            index = rehash(index);
        }
        slots[index] = item;
        occupied[index] = true;
    }

    bool get(const T& item) const {
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
};
