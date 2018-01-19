#include <iostream>

using namespace std;

int main()
{
    double number1, number2;
    int operation;

    cout << "This program will prompt for two integers and an operation and then display the result of applying the operation to the numbers.\n\n";

    cout << "Enter the first integer: \n";
    cin >> number1;

    cout << "Enter the second integer: \n";
    cin >> number2;

    cout << "The availble operations are: \n";
    cout << "\t 1. addition\n";
    cout << "\t 2. subtraction\n";
    cout << "\t 3. multiplication\n";
    cout << "\t 4. division\n";
    cout << "Enter the number for your choice of operation: \n";
    cin >> operation;

    cout << "The answer is: \n";

    // switch(operation) {
    //     case 0: operation == 1;
    //     cout << number1 << " + " << number2 << " = " << number1 + number2 << endl;
    //     break;
    //     case 1: operation == 2;
    //     cout << number1 << " - " << number2 << " = " << number1 - number2 << endl;
    //     break;
    //     cout 2: operation == 3;
    //     cout << number1 << " * " << number2 << " = " << number1 * number2 << endl;
    //     break;
    //     cout 3: operation == 4;
    //     cout << number1 << " \ " << number2 << " = " << number1 / number2 << endl;
    //     break;
    // }

    if (operation == 1) {
        cout << number1 << " + " << number2 << " = " << number1 + number2 << endl;
    } else if (operation == 2) {
        cout << number1 << " - " << number2 << " = " << number1 - number2 << endl;
    } else if (operation == 3) {
        cout << number1 << " * " << number2 << " = " << number1 * number2 << endl;
    } else if (operation == 4) {
        if (number2 == 0) {
            cout << number1 << " / " << number2 << " Division by 0 error"
        } else {
        cout << number1 << " / " << number2 << " = " << number1 / number2 << endl;
        }
    } else {
        cout << operation << " is an invalid operation. Valid choices were 1, 2, 3 or 4. Quitting program."
    }

}