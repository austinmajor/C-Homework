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

int main() {
	for (int j = 1; j <= 5; j++) {
		for (int i = 1; i <= (6 - j); i++) {
			cout << "#";
		}
		cout << "/n";
	}

	return 0;
}
