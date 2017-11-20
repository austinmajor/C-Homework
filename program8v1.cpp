/*
File Name: program8.cpp
Name: Austin Major
WSUID: N675Q967
HW#: 8
Description: Bubble, Bubble, Toil and Bubble Sort a Dynamically Allocated Array of Strings
*/
#include <iostream>

using namespace std;

void bubbleSort(string words[], int num)
{
string temp;
for (int j = 0; j<num-1; j++)
{
for (int i=j+1; i<num; i++)
{
if (words[j] > words[i])
{
temp = words[j];
words[j]= words[i];
words[i] = temp;
}
}
}
cout << "Your sorted list is: ";
for(int i = 0; i < num; i++)
cout << words[i] <<" ";
}

int main()
{
int size;
cout << "How many words will you be entering? ";
cin >> size;
string names[size];
for(int i = 0; i < size; i++){
cout << "Enter a word: ";
cin >> names[i];
}
bubbleSort(names, size);
return 0;
}
