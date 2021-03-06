/*
File Name: program8.cpp
Name: Austin Major
WSUID: N675Q967
HW#: 8
Description: Bubble, Bubble, Toil and Bubble Sort a Dynamically Allocated Array of Strings
*/

#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string *words, int num);

int main() {
	int count;
	string * placeholder;

	cout << "How many words will you be entering? ";
	cin >> count;

	placeholder = new (nothrow) string[count];
	for(int i = 0; i < count; i++) {
		cout << "Enter a word: ";
		cin >> placeholder[i];
	}

	bubbleSort(placeholder, count);

	cout << "Your sorted list is:";
	for(int i = 0; i < count; i++) {
		cout << " " << placeholder[i];
	}
	cout << "\n";

	return 0;
}

// Takes a pointer to a string array and bubble sorts it
void bubbleSort(string *words, int num) {
	bool finished = false;
	while(!finished) {
		finished = true;
		for(int i = 0; i < num-1; i++) {
			int cmp = words[i].compare(words[i+1]);

			if(cmp > 0) {
				string temp = words[i];
				words[i] = words[i + 1];
				words[i + 1] = temp;
				finished = false;
			}
			else {
				continue;
			}
		}
	}
}
