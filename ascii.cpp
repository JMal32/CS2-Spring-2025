
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function that prints to output device all on one line, space separated sequence of 
// integer ascii values for each character in the s param
void printAscii(const string s) {
  for (char c : s) {
    cout << (int)c << " ";
  }
  cout << endl;
}
int main() {
  // Call printAscii with a string of your choice
  printAscii("Hello, World!");
  printAscii("This is test number two.");
}

