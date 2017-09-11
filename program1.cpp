/*
File Name: program1.cpp
Author: Austin Major
ID: n675q967
Assignment: 1
Description: Basic Input and Arithmetic Calculator
Last Changed: August 28, 2017
*/

# include <iostream>

using namespace std;

int main() {
	int num1, num2, operation;

  //layout mimics EXACT HW format (with the exception of line 32)
  //beginning instructions
  cout << "This program will prompt for two integers and an operation and then display the result of applying the operation to the numbers.\n\n";
  //first input
	cout << "Enter the first integer: ";
	cin >> num1;
  //second input
	cout << "Enter the second integer: ";
	cin >> num2;
  //operation input
  cout << "\nThe available operations are:\n\t1. addition\n\t2. subtraction\n\t3. multiplication\n\t4. division\nEnter the number for your choice of operation: ";
  cin >> operation;
  //prints to avoid repetition below
  cout << "\nThe answer is: ";

//scenarios for entered operations and prints to screen
if (operation == 1) {
	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
} else if (operation == 2) {
	cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
} else if (operation == 3) {
	cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
} else if (operation == 4) {
    //checks for division error by 0
    if (num2 == 0) {
  	cout << num1 << " / " << num2 << " cannot be found because can’t divide by zero." << endl;
  } else
	  cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
} else
	cout << operation <<" is an invalid operation. Valid choices were 1, 2, 3 or 4. Quitting program." << endl;
	return 0;
}
