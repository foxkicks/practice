#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
	int dice, roll;
	bool valid = false;
	string dump;
	system("title Roll Any Dice");
	srand(time(nullptr));
	do {
		cout << "Enter dice sides: ";
		cin >> dice;
		if (cin.good()) valid = true;
		else {
			cout << "Numbers only, please." << endl;
			cin.clear();
			getline(cin, dump);
		}
	} while (!valid);
	roll = rand() % dice + 1;
	cout << "You rolled " << roll << endl;
	main();
}