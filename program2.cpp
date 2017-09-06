/*
File Name: hello.cpp
Author: Austin Major
Student ID: n675q967
Assignment Number: 1
Description: Prints "For shapes"
Last Changed: August 28, 2017
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
