#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
  Fraction(int num = 0, int den = 1);
  string getString() const;
  void Print() const;
  int getNum() const;
  int getDen() const;
  double getVal() const;
  Fraction operator*(Fraction rhs);
  Fraction operator/(Fraction rhs);
  Fraction operator-(Fraction rhs);
  Fraction operator+(Fraction rhs);
  bool operator==(Fraction rhs);
  bool operator!=(Fraction rhs);
  bool operator<(Fraction rhs) const;
  bool operator>(Fraction rhs) const;
  bool operator<=(Fraction rhs) const;
  bool operator>=(Fraction rhs) const;
  friend ostream &operator<<(ostream &os, const Fraction &f);

private:
  int gcd(int m, int n);
  int numerator;
  int denominator;
};

Fraction::Fraction(int num, int den) {
  numerator = num;
  denominator = den;
}

string Fraction::getString() const {
  return to_string(numerator) + " / " + to_string(denominator);
}
void Fraction::Print() const {
  cout << numerator << " / " << denominator << endl;
}

int Fraction::getNum() const { return numerator; }

int Fraction::getDen() const { return denominator; }

double Fraction::getVal() const {
  return static_cast<double>(numerator) /
         denominator; // I read up on static_cast and I guess it's a "safer" way
                      // to cast variables
}
// I implemnted the fraction reduction in each operator overload. In hindsight,
// I should have made a separate function for it, or at least I think that would
// have been the better way. Guess I could always time it and see if there's a
// difference haha.
Fraction Fraction::operator*(Fraction rhs) {
  Fraction result;
  result.numerator = numerator * rhs.numerator;
  result.denominator = denominator * rhs.denominator;
  int common = gcd(abs(result.numerator), abs(result.denominator));
  result.numerator /= common;
  result.denominator /= common;
  return result;
}
Fraction Fraction::operator/(Fraction rhs) {
  Fraction result;
  result.numerator = numerator * rhs.denominator;
  result.denominator = denominator * rhs.numerator;
  int common = gcd(abs(result.numerator), abs(result.denominator));
  result.numerator /= common;
  result.denominator /= common;
  return result;
}
Fraction Fraction::operator-(Fraction rhs) {
  Fraction result;
  result.numerator = numerator * rhs.denominator - denominator * rhs.numerator;
  result.denominator = denominator * rhs.denominator;
  int common = gcd(abs(result.numerator), abs(result.denominator));
  result.numerator /= common;
  result.denominator /= common;
  return result;
}
Fraction Fraction::operator+(Fraction rhs) {
  Fraction result;
  result.numerator = numerator * rhs.denominator + denominator * rhs.numerator;
  result.denominator = denominator * rhs.denominator;
  int cd = gcd(abs(result.numerator), abs(result.denominator));
  result.numerator /= cd;
  result.denominator /= cd;
  return result;
}
// I implemented the equality and inequality operators by multiplying the
// numerators and denominators of the two fractions and comparing them.
bool Fraction::operator==(Fraction rhs) {
  return numerator * rhs.denominator == denominator * rhs.numerator;
}

bool Fraction::operator!=(Fraction rhs) {
  return numerator * rhs.denominator != denominator * rhs.numerator;
}

bool Fraction::operator<(Fraction rhs) const {
  return numerator * rhs.denominator < rhs.numerator * denominator;
}

bool Fraction::operator>(Fraction rhs) const {
  return numerator * rhs.denominator > rhs.numerator * denominator;
}

bool Fraction::operator<=(Fraction rhs) const { return !(*this > rhs); }

bool Fraction::operator>=(Fraction rhs) const { return !(*this < rhs); }
// This is the gcd function that was from the powerpoint. I don't think I
// changed anything in it.
int Fraction::gcd(int m, int n) {
  int oldm, oldn;

  while (m % n != 0) {
    oldm = m;
    oldn = n;
    m = oldn;
    n = oldm % oldn;
  }
  return n;
}

// This is the ostream overload. We built this one in class.
ostream &operator<<(ostream &os, const Fraction &f) {
  os << f.numerator << " / " << f.denominator;
  return os;
}

/*
int main() {
  Fraction f1(55, 16); // Made 3 fractions to test the overloads
  Fraction f2(6, 12);
  Fraction f3(9, 5);

  cout << "Fraction 1: " << f1 << endl;
  cout << "Fraction 2: " << f2 << endl;
  cout << "Fraction 3: " << f3 << endl;
  cout << endl;

  // Tests for all of the different overloads

  // Multiplication
  Fraction mult1 = f1 * f2;
  Fraction mult2 = f2 * f3;
  cout << f1 << " * " << f2 << " = " << mult1 << endl;
  cout << f2 << " * " << f3 << " = " << mult2 << endl;

  // Division
  Fraction div1 = f1 / f3;
  Fraction div2 = f2 / f3;
  cout << f1 << " / " << f3 << " = " << div1 << endl;
  cout << f2 << " / " << f3 << " = " << div2 << endl;

  // Subtraction
  Fraction sub1 = f1 - f2;
  Fraction sub2 = f2 - f3;
  cout << f1 << " - " << f2 << " = " << sub1 << endl;
  cout << f2 << " - " << f3 << " = " << sub2 << endl;

  // Addition
  Fraction add1 = f1 + f2;
  Fraction add2 = f2 + f3;
  cout << f1 << " + " << f2 << " = " << add1 << endl;
  cout << f2 << " + " << f3 << " = " << add2 << endl;

  // Equality
  cout << "(" << f1 << ") == (" << f1 << ") is "
       << (f1 == f1 ? "true" : "false") << endl;
  cout << "(" << f1 << ") == (" << f2 << ") is "
       << (f1 == f2 ? "true" : "false") << endl;
  cout << "(" << f1 << ") != (" << f2 << ") is "
       << (f1 != f2 ? "true" : "false") << endl;
  cout << "(" << f1 << ") != (" << f1 << ") is "
       << (f1 != f1 ? "true" : "false") << endl;
  cout << endl;

  // Greater than (>) and less than (<)
  cout << "(" << f1 << ") > (" << f2 << ") is " << (f1 > f2 ? "true" : "false")
       << endl;
  cout << "(" << f1 << ") > (" << f3 << ") is " << (f1 > f3 ? "true" : "false")
       << endl;
  cout << "(" << f2 << ") < (" << f1 << ") is " << (f2 < f1 ? "true" : "false")
       << endl;
  cout << "(" << f3 << ") < (" << f1 << ") is " << (f3 < f1 ? "true" : "false")
       << endl;
  cout << endl;

  // Greater than or equal (>=) and less than or equal (<=)
  cout << "(" << f1 << ") >= (" << f1 << ") is "
       << (f1 >= f1 ? "true" : "false") << endl;
  cout << "(" << f1 << ") >= (" << f2 << ") is "
       << (f1 >= f2 ? "true" : "false") << endl;
  cout << "(" << f2 << ") <= (" << f1 << ") is "
       << (f2 <= f1 ? "true" : "false") << endl;
  cout << "(" << f3 << ") <= (" << f1 << ") is "
       << (f3 <= f1 ? "true" : "false") << endl;
  cout << endl;

  return 0;
} */
