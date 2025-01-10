#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sysinfoapi.h>
#include <string>
using namespace std;

static void results(int roll) {
	cout << "You shake the ball." << endl;
	Sleep(3000);
	cout << "It says: ";
	switch (roll) {
	case 1:
		cout << "Yes";
		break;
	case 2:
		cout << "Of course";
		break;
	case 3:
		cout << "Indeed";
		break;
	case 4:
		cout << "There is no other way";
		break;
	case 5:
		cout << "It is certain";
		break;
	case 6:
		cout << "Most likely";
		break;
	case 7:
		cout << "Looks good";
		break;
	case 8:
		cout << "Perhaps";
		break;
	case 9:
		cout << "Well, yeah";
		break;
	case 10:
		cout << "Indubitably";
		break;
	case 11:
		cout << "That's a tough one";
		break;
	case 12:
		cout << "Who knows?";
		break;
	case 13:
		cout << "Maybe";
		break;
	case 14:
		cout << "Unsure";
		break;
	case 15:
		cout << "Run that by me again?";
		break;
	case 16:
		cout << "No";
		break;
	case 17:
		cout << "Not happening";
		break;
	case 18:
		cout << "Don't think so";
		break;
	case 19:
		cout << "Never";
		break;
	case 20:
		cout << "Not this time";
		break;
	}
	cout << endl;
	Sleep(5000);
	system("cls");
}

int main() {
	int roll;
	string dump;
	system("title Magic 8-Ball");
	srand(GetTickCount64());
	roll = rand() % 20 + 1;
	cout << "Ask any 'yes or no' question: ";
	getline(cin, dump);
	results(roll);
	main();
}