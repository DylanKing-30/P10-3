//	P10-3.cpp	-	Dylan King	-	November 4, 2026
//
//	Description:	Program generates a sequence of 20 random six-side die tosses,
//					determines whether or not a run is present and prints out this information,
//					and prints all the die values, marking the runs by including them in parentheses.

#include <iostream>
using namespace std;

void displayRun(int values[], int size);
bool hasRun(int values[], int size);

int main() {

	srand(time(0));

	int values[20];

	for (int i = 0; i < 20; i++) {
		values[i] = (rand() % 6) + 1;
	}
	while (hasRun(values, 20) == false) {
		cout << "no run: ";
		displayRun(values, 20);
		cout << endl;
	}
	cout << "has run: ";
	displayRun(values, 20);
}

bool hasRun(int values[], int size) {
	for (int i = 0; i < size; i++) {
		if (values[i] == values[i + 1]) {
			return true;
		}
	}
	return false;
}

void displayRun(int values[], int size) {
	bool run = false;
	for (int i = 0; i < size; i++) {

		if (values[i] == values[i + 1] && run == false && i != 0) {
			cout << " (";
			run = true;
		}
		else if (values[i] == values[i + 1] && run == false && i == 0) {
			cout << "(";
			run = true;
		}
		else if (i != 0) {
			cout << " ";
		}

		cout << values[i];

		if (values[i] != values[i + 1] && run == true) {
			cout << ")";
			run = false;
		}
	}
}