#include <vector>
#include <string>

class HashTable {
private:
    std::vector<int> slots;
    int size;
    int hash(int key);
    int rehash(int index);

public:
    HashTable(int initialSize = 1000);
    void add(int item);
    bool get(int item);
    void quickLoad(const std::vector<int>& listOfValues, double loadFactor);
}; 