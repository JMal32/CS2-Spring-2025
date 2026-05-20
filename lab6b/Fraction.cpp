#include "Fraction.h"
#include <algorithm>
#include <cmath>

// Helper function to find GCD
int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    
    // Ensure denominator is positive
    if (den < 0) {
        num = -num;
        den = -den;
    }
    
    numerator = num;
    denominator = den;
    simplify();
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int num) {
    numerator = num;
    simplify();
}

void Fraction::setDenominator(int den) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    denominator = den;
    simplify();
}

bool Fraction::operator<(const Fraction& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator>(const Fraction& other) const {
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator==(const Fraction& other) const {
    return (numerator * other.denominator) == (other.numerator * denominator);
}

void Fraction::simplify() {
    int divisor = gcd(numerator, denominator);
    if (divisor != 0) {
        numerator /= divisor;
        denominator /= divisor;
    }
}

double Fraction::toDouble() const {
    return static_cast<double>(numerator) / denominator;
} 