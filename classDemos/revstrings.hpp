#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseString(const string s) {
  string stringcp = s;
  string stringrev(stringcp.begin(), stringcp.end());
  cout << stringrev;
}
/*
int main() {
  string s = "Hello, World!";
  cout << reverseString(s) << endl;
  return 0;
}
*/
