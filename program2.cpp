/*
File Name: program2.cpp
Name: Austin Major
WSUID: N675Q967
HW#: 2
Description: Drawing with Loops
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  //TRIANGLE
  for (int line = 0; line < 4; line++) {
    for (int spaces = line; spaces > 0; spaces--) {
      cout << " ";
    }
    for (int hashes = (8 - (line * 2)); hashes > 0; hashes--) {
      cout << "#";
    }
    cout << "\n";
  }
  //END OF TRIANGLE

  cout << "\n\n";

  //DIAMOND
  int diamond;
  for (int line = 0; line < 7; line++) {
    for (int spaces = abs(line - 3); spaces > 0; spaces--) {
      cout << " ";
    }

    if (line > 3) diamond = 2 + (abs(line - 6) * 2);
    else diamond = 2 + (line * 2);

    for (int hashes = diamond; hashes > 0; hashes--) {
      cout << "#";
    }
    cout << "\n";
  }
  //END OF DIAMOND

  cout << "\n\n";

  //X
  for (int row = 1; row <= 7; row++) {
    for (int hashes = 1; hashes <= 7; hashes++) {
      if (row == hashes || (row + hashes) == (7 + 1))cout << "#";
      else cout << " ";
    }
    cout << "\n";
  }
  //END OF X

  cout << "\n\n";

  return 0;
}
