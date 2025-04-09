#include <iostream>
#include <vector>

using namespace std;

unsigned long long getInt(int numDigits = 10) {
  unsigned long long num = 0;

  num = rand() % 9 + 1;
  for (int i = 0; i < numDigits -1; i++) {
    num = num * 10 + rand() % 10;
  }
  return num;
}

vector<unsigned long long> unsortedVec(int size, int numDigits = 10) {
  vector<unsigned long long> vec(size);
  for (int i = )
}

int main() {

}
