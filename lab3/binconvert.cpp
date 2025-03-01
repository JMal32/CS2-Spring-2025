#include <iostream>
#include <string>
#include "intStack.h"

using namespace std;

string dec2Bin(int decNumber) {
  int sz = 100;
  IntStack remstack(sz);

  while (decNumber > 0) {
    int rem = decNumber % 2;
    remstack.push(rem);
    decNumber = decNumber / 2;
  }

  string binString;
  while (!remstack.isEmpty()) {
    binString += to_string(remstack.pop());
  }

  return binString;
}

string dec2Base(int decNumber, int base) {
  const string digits = "0123456789ABCDEF";
  int sz = 100;
  IntStack remstack(sz);

  while (decNumber > 0) {
    int rem = decNumber % base;
    remstack.push(rem);
    decNumber = decNumber / base;
  }

  string newString;
  while (!remstack.isEmpty()) {
    newString += digits[remstack.pop()];
  }
  
  // I struggled with this function and, in particular, the handling of this string.
  // I kept getting bad output and had to get some help to remember this step...
  reverse(newString.begin(), newString.end());

  return newString;
}

int main(){
  int decNumber;
  int base;

  cout << "Enter a decimal number: ";
  cin >> decNumber;

  cout << "Binary representation: " << dec2Bin(decNumber) << endl;

  cout << "Enter a base (2-16): ";
  cin >> base;

  if (base >= 2 && base <=16) {
    cout << "Base " << base << " representation: " << dec2Base(decNumber, base) << endl;
  } else {
    cout << "Please enter a valid base, nerd." << endl;
  }

  return 0;
}
