/*
Filename: program5.cpp
Name: Austin Major
WSUID: N675Q967
HW#: 5
Description: Lyrics to the song B-I-N-G-O.
 */

#include <iostream>

using namespace std;

void printArray(const char arr[]);

const int SIZE = 5;
const char dog[SIZE] = {'B', 'I', 'N', 'G', 'O'};

int main() {
	//Loop 6 blocks
	for(int i = 0; i <= SIZE; i++) {
		cout << "There was a farmer had a dog\nand ";
		printArray(dog);
		cout << "was his name-o\n";

		//Loop 3 occurences of B-I-N-G-O per verse
		for(int count = 0; count < 3; count++) {
			for(int star = 0; star < i; star++) {
				cout << "* ";
			}
			for(int letter = i; letter < SIZE; letter++) {
				cout << dog[letter] << " ";
			}
			cout << "\n";
		}

		cout << "And ";
		printArray(dog);
		cout << "was his name-o\n\n";
	}

	return 0;
}

//Print array
void printArray(const char *arr) {
	for(unsigned int i = 0; i <= (sizeof(arr)/sizeof(*arr)); i++) {
		cout << arr[i] << " ";
	}
}
