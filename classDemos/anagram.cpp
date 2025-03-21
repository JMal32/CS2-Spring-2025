#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool anag1(const string s1, const string s2) {
  vector<char> vlist;
  int pos1 = 0; bool stillOK = true;

  for (int i = 0; i < s2.length(); i++) {
    vlist.push_back(s2[i]);
  }
  while (pos1 < s1.size() && stillOK) {
    int pos2 = 0; bool found = false;
    while (pos2 < vlist.size() && !found) {
      if (s1[pos1] == vlist[pos2]) {
        found = true;
        vlist.erase(vlist.begin() + pos2);
      }
      pos2++;
    }
    if (found) {
      vlist.at(pos2) = ' ';
    } else
      stillOK = false;
    }
    pos1++;
  }
  return stillOK;
}
