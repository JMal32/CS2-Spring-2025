#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructors
    Fraction();
    Fraction(int num, int den);
    
    // Getters
    int getNumerator() const;
    int getDenominator() const;
    
    // Setters
    void setNumerator(int num);
    void setDenominator(int den);
    
    // Operators
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    
    // Helper methods
    void simplify();
    double toDouble() const;
};

#endif 