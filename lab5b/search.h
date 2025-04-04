#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

// Sequential search implementation
template<typename T>
bool sequentialSearch(const std::vector<T>& list, const T& target) {
    for (const T& item : list) {
        if (item == target) {
            return true;
        }
    }
    return false;
}

// Binary search implementation
template<typename T>
bool binarySearch(const std::vector<T>& list, const T& target) {
    int left = 0;
    int right = list.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (list[mid] == target) {
            return true;
        }
        
        if (list[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

// Function to generate random unique numbers (similar to Python's random.sample)
template<typename T>
std::vector<T> generateUniqueRandomNumbers(int size, T min, T max) {
    std::vector<T> numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis(min, max);
    
    // Create a vector of all possible numbers
    std::vector<T> allNumbers;
    for (T i = min; i <= max; ++i) {
        allNumbers.push_back(i);
    }
    
    // Shuffle and take first 'size' numbers
    std::shuffle(allNumbers.begin(), allNumbers.end(), gen);
    numbers.assign(allNumbers.begin(), allNumbers.begin() + size);
    
    return numbers;
}

// Timing function
template<typename Func, typename... Args>
double measureTime(Func func, Args... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(args...);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / 1000.0; // Convert to milliseconds
}

#endif // SEARCH_H 