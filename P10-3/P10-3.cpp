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
	int values1[3] = { 1,2,3 };
	displayRun(values1, 3);
	cout << "        " << hasRun(values1, 3) << endl;
	int values2[2] = { 2,2 };
	displayRun(values2, 2);
	cout << "        " << hasRun(values2, 2) << endl;
	int values3[3] = { 4,4,1 };
	displayRun(values3, 3);
	cout << "        " << hasRun(values3, 3) << endl;
	int values4[3] = { 1,5,5 };
	displayRun(values4, 3);
	cout << "        " << hasRun(values4, 3) << endl;
	int values5[5] = { 6,6,6,3,3 };
	displayRun(values5, 5);
	cout << "        " << hasRun(values5, 5) << endl;
	int values6[4] = { 1,2,5,2 };
	displayRun(values6, 4);
	cout << "     " << hasRun(values1, 3);
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