#include <iostream>
#include <vector>
using namespace std;

class Clown {

public:
  double approxPi(int bears = 100) const;
  void flurry(int lvl = NULL);
  void rollFourDice();
  Clown();


private:
  int r;

};

void Clown::flurry(int lvl) {
  int rprod;
  rprod = rand() % 11 + 1;

  cout << endl;
  for (int i = 0; i < r * rprod; i++) {
    cout << "*";
  }
  cout << endl;

  if (lvl == NULL) {
    rprod = rand() % 11 + 1;

  }
  else {
    rprod = lvl;
  }
}

void Clown::rollFourDice() {
  vector<int> vec;
  int roll;

  for(int i = 0; i < 4; i++) {
    roll = rand() % 6 + 1;
    vec.push_back(roll);

  }
cout << "4-die Roll: ";
for (int i = 0; i < 4; i++) {
    cout << vec.at(i) << " ";

}
 cout << endl;

double Clown::approxPi() const {
  double x, y;
  int n, cnt, hands;
  // get # of handfuls of bearings
  cout << "Enter a number (of handfuls): ";
  cin >> hands;
  n = hands * 100 + r; // total # of bearings
  cnt = 0;
  for (int i = 0; i < n; i++) {
    x = ((double)rand()) / RAND_MAX;
    x = x * 2 - 1;

    y = ((double)rand()) / RAND_MAX * 2 - 1;
    if (sqrt(x * x + y * y) < 1) {
      cnt++;

    }
  }
return (4.0 * cnt / n);
}

Clown::Clown(){
  r = rand() % 11 + 1; // this occurs when the object is declared
}

int main() {
    Clown bozo;

    srand(time(0));

    bozo.flurry();
    cout << "The value of pi ia approximately: " << bozo.approxPi() << endl;
    bozo.flurry();
    bozo.rollFourDice();
    bozo.flurry();


  return 0;
}
