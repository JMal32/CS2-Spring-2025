/*
string reverseString(const string s) {
  string stringrev = s;  
  reverse(stringrev.begin(), stringrev.end());

  return stringrev;
}

int main() {
  cout << reverseString("Hello, World!") << endl;
  cout << reverseString("Goodbye, World!") << endl;
}*/

string mkRandString(unsigned int n) {
  string s;
  s.reserve(n);
  string stringres = "";
  for (unsigned int i = 0; i < n; i++) {
    char c = 'a' + (rand() % 26);
    stringres.push_back(c);
  }
  return stringres;
}

int main() {
  unsigned int n = 1000;
  string s = mkRandString(n);
  cout << "String length: " << s.length() << endl;
  cout << "String: " << s << endl;
  return 0;
}
