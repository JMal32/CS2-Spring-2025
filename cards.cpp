
#include <iostream>
#include <string>

using namespace std;

enum CardSuit {CS_CLUB, CS_DIAMOND, CS_HEART, CS_SPADE};

enum CardRank {CR_ACE, CR_TWO, CR_THREE, CR_FOUR, CR_FIVE, CR_SIX, CR_SEVEN, CR_EIGHT, CR_NINE, CR_TEN, CR_JACK, CR_QUEEN, CR_KING};

class Card {
public:
    Card(CardSuit s = CS_CLUB, CardRank r = CR_ACE);
    string getStr() const;
    
private:
    static string toSuitStr(CardSuit s);
    static string toRankStr(CardRank r);

    CardSuit suit;
    CardRank rank;
};

Card::Card(CardSuit s, CardRank r) {
    suit = s; rank = r;
 }

string Card::getStr() const {
    return toRankStr(rank) + " of " + toSuitStr(suit);
}

/* Converts from CardSuit to string using a switch statement */
string Card::toSuitStr(CardSuit s) {
    string ans;

    switch (s) {
    case CS_CLUB:
        ans = "Clubs";
        break;
    case CS_DIAMOND:
        ans = "Diamonds";
        break;
    case CS_HEART:
        ans = "Hearts";
        break;
    case CS_SPADE:
        ans = "Spades";
        break;
    }
    return ans;
}


/* Converts from CardRank to string using a switch statement */
string Card::toRankStr(CardRank r) {
    string ans;

    switch (r) {
    case CR_ACE:
        ans = "Ace";
        break;
    case CR_TWO:
        ans = "Two";
        break;
    case CR_THREE:
        ans = "Three";
        break;
    case CR_FOUR:
        ans = "Four";
        break;
    case CR_FIVE:
        ans = "Five";
        break;
    case CR_SIX:
        ans = "Six";
        break;
    case CR_SEVEN:
        ans = "Seven";
        break;
    case CR_EIGHT:
        ans = "Eight";
        break;
    case CR_NINE:
        ans = "Nine";
        break;
    case CR_TEN:
        ans = "Ten";
        break;
    case CR_JACK:
        ans = "Jack";
        break;
    case CR_QUEEN:
        ans = "Queen";
        break;
    case CR_KING:
        ans = "King";
        break;
    }
    return ans;
}


/* Converts from integer to CardSuit using a switch statement*/ 
CardSuit itoCardSuit(int s) {
    switch (s) {
    case 0:
        return CS_CLUB;
    case 1:
        return CS_DIAMOND;
    case 2:
        return CS_HEART;
    case 3:
        return CS_SPADE;
    default:
        return CS_CLUB;
    
    }
}
/* Converts from integer to CardRank using a switch statement */
CardRank itoCardRank(int r) {
    switch (r) {
            case 0:
                return CR_ACE;
            case 1:
                return CR_TWO;
            case 2:
                return CR_THREE;
            case 3:
                return CR_FOUR;
            case 4:
                return CR_FIVE;
            case 5:
                return CR_SIX;
            case 6:
                return CR_SEVEN;
            case 7:
                return CR_EIGHT;
            case 8:
                return CR_NINE;
            case 9:            
                return CR_TEN;
            case 10:
                return CR_JACK;
            case 11:
                return CR_QUEEN;
            case 12:
                return CR_KING;
            default:
                return CR_ACE;
    }
}

int main() {
    
    Card c1(CS_SPADE, CR_ACE);
    


    cout << c1.getStr() << endl;
    cout << endl << endl << endl;

    Card c;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            c = Card (itoCardSuit(suit), itoCardRank(rank));
            cout << c.getStr() << "    ";
        }
        cout << endl;
    }

}

/*
class Fraction {
public:
  Fraction(int num=0, int den=1);
  void Print();
  int getNum() const;
  int getDen() const;
  double getVal() const;
  Fraction operator*(Fraction rhs);
  Fraction operator/(Fraction rhs);
  Fraction operator-(Fraction rhs);
  Fraction operator+(Fraction rhs);
  bool operator==(Fraction rhs);
  bool operator!=(Fraction rhs);
private:
  int gcd(int m, int n);
  int numerator;
  int denominator;
};

Fraction::Fraction (int num, int den) {
  this.numerator = n; this.denominator = d;
}

void Fraction::Print() {
    
    friend ostream& operator<<(ostream& os, const Fraction& f);
    os << f.numerator << " / " << f.denominator;
    return os;

   cout << numerator << " / " << denominator << endl;
}

int Fraction::getNum() const {
  return numerator;
}

int Fraction::gcd(int m, int n){
//Look at powerpoint slides for this
}

int main() {
  Fraction f(2, 7);

  f.Print();
  cout << f.getNum() << endl;
  
}
*/
