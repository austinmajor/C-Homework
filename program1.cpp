/*
File Name: hello.cpp
Author: Austin Major
Student ID: n675q967
Assignment Number: 1
Description: Prints "Hello, world"
Last Changed: August 28, 2017
*/

# include <iostream>

using namespace std;

int main() {
	int num1;
	int operation;
	int num2;

	cout << "Enter a number number:";
	cin >> num1;

	cout << "Enter a operator: 1)Addition 2)Subtraction 3)Multiplication 4)Division:";
	cin >> operation;

	cout << "Enter another number:";
	cin >> num2;

//scenarios for entered operation: 1-4 
if (operation == 1) {
	cout << "The answer is: " << num1 + num2 << endl;
} else if (operation == 2) {
	cout << "The answer is: " << num1 - num2 << endl;
} else if (operation == 3) {
	cout << "The answer is: " << num1 * num2 << endl;
} else if (operation == 4) {
	cout << "The answer is: " << num1 / num2 << endl;
} else
	cout << "Error, please choose another operation" << endl;
	return 0;
}
