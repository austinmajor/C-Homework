#include <iostream>

using namespace std;

// Money defined globally so all functions know what Money is
struct Money {
    int dollars;
    int cents;
};

Money setMoney(int d, int c);
void printMoney(const Money &m);
Money addMoney(const Money &left, const Money &right);

int main()
{
    Money money, other = {2, 25};   // Two declared, one initialized
    Money *mptr = &money;   // Pointer to a Money struct
    money = setMoney(3, 50);
    (*mptr).dollars = 7;    // Changing just the dollars through the pointer

    // Prints a single line that adds the two Money structs
    printMoney(money);
    cout << " + ";
    printMoney(other);
    cout << " = ";
    printMoney(addMoney(money, other));
    cout << endl;

    return 0;
}

Money setMoney(int d, int c)
{
    Money temp;
    temp.dollars = d;
    temp.cents = c;

    return temp;
}

void printMoney(const Money &m)
{
    /* Swap the commented out lines with those that have // at the end
     * to print the struct using the if/else block
     */
    char prev;  //
    prev = cout.fill('0');  //
    cout << "$" << m.dollars << ".";
    cout.width(2);  //
    cout << m.cents;//
    // if ( m.cents < 10 )
    //     cout << "0" << m.cents;
    // else
    //     cout << m.cents;
    cout.fill(prev);    //
}

Money addMoney(const Money &left, const Money &right)
{
    // A lot of logic is taken care of for us if we convert our Money
    // amounts to the number of pennies
    int leftCents = (left.dollars * 100) + left.cents;
    int rightCents = (right.dollars * 100) + right.cents;

    int sumCents = leftCents + rightCents;

    // We have to split our number of pennies back into dollars and cents
    Money temp;
    temp.dollars = sumCents / 100;
    temp.cents = sumCents % 100;

    return temp;
}
