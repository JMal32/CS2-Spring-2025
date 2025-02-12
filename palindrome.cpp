#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Checking if a string is a palindrome
bool isPalindrome(const std::string& str) {
  int n = str.size();
  for (int i = 0; i < n / 2; ++i) {
    if (str[i] != str[n - i - 1]) {
      return false;
    }
  }
  return true;
}

// Function to make palindrome from given string
string makePalindrome(const std::string& input) {
  //Empty Strings
  if (input.empty()) {
    return "";
  }
  // Returning string if it's already a palindrome
  if (isPalindrome(input)) {
    return input;
  }
  
  int len = input.size();
  int half = len / 2;

  string left = input.substr(0, half);
  string palindrome;

  if (len % 2 == 0) {
    // Even length
    string rightHalf = leftHalf;
    reverse(rightHalf.begin(), rightHalf.end());
    palindrome = leftHalf + rightHalf;
  } else {
    // Odd length
    char middleChar = input[half];
    sstring rightHalf = leftHalf;
    reverse(rightHalf.begin(), rightHalf.end());
    palindrome = leftHalf + middleChar + rightHalf;
  }
  return palindrome;
}
int main() {
  string input;
  cout << "Enter a string: ";
  cin >> input;

  string palindrome = makePalindrome(input);
  cout << "Palindrome: " << palindrome << endl;

  return 0;
}


