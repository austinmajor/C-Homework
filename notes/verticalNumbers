/* The goal of this program is to list integers vertically
 * We won't take input from the user until the that functionality works
 * So, the number 1234 should get printed as:
 * 1
 * 2
 * 3
 * 4
 *
 * The function must take an int as its parameter

 stack is referred to as LIFO (last in first out)
 */

 #include <iostream>

 using namespace std;

 void writeVertical(int num);

 int main()
 {
     writeVertical(2049);

     return 0;
 }

 void writeVertical(int num)
 {
    //  int tensInNum = 1;
    //  int leftRemaining = num;
    //  while (leftRemaining > 9) {
    //      leftRemaining /= 10;
    //      tensInNum *= 10;
    //  }

    //  for (int powerOf10 = tensInNum;
    //         powerOf10 > 0; powerOf10 /= 10) {
    //     cout << (num / powerOf10) << endl;
    //     num %= powerOf10;
    // }

    if (num < 10) {
        cout << num << endl;
    }
    else {
        writeVertical(num / 10);
        cout << (num % 10) << endl;
    }

 }












 
