#include <iostream>

using namespace std;

int rfactorial(int num);
int ifactorial(int num);

int main()
{
    int num = 5;

    cout << rfactorial(num) << endl << ifactorial(num) << endl;

    return 0;
}

int rfactorial(int num)
{
    if (num <= 1)
        return 1;
    else
        return num * rfactorial(num - 1);
}

int ifactorial(int num)
{
    int f = 1;
    for (int i = 1; i <= num; i++)
        f *= i;

    return f;
}
