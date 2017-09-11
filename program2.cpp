/*
File Name: hello.cpp
Name: Austin Major
WSUID: n675q967
HW#: 1
Description: Prints "For shapes"
*/

# include <iostream>
# include <cmath>

using namespace std;

int main(void)
{
  for (int i = -3; i <= 3; i++){
    for (int j = 1; j <= 4 - abs(i); j++) {
      cout << "#";
    }
    cout << "\n";
  }



  return 0;
}
