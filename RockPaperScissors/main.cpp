#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sysinfoapi.h>
using namespace std;

int main() {
	int choicePC, choicePlayer, wins = 0, losses = 0;
	system("title Rock, Paper, Scissors?");
	srand(GetTickCount64());
	cout << "Let's play Rock, Paper, Scissors.\n"
			"Wins: 0\n"
			"Losses: 0\n";
	while(true) {
		cout << "Rock (1), Paper (2), Scissors (3)?" << endl;
		cout << "Choose: ";
		cin >> choicePlayer;
		system("cls");
		switch (choicePlayer) {
			case 1:
				cout << "You chose Rock. ";
				break;
			case 2:
				cout << "You chose Paper. ";
				break;
			case 3:
				cout << "You chose Scissors! ";
				break;
			default:
				cout << "Try again." << endl;
				continue;
		}
		choicePC = rand() % 3 + 1;
		if (choicePlayer == 1) {
			if (choicePC == 1) {
				cout << "Computer chose Rock. It's a tie!" << endl;
			}
			else if (choicePC == 2) {
				cout << "Computer chose Scissors. You win!" << endl;
				++wins;
			}
			else if (choicePC == 3) {
				cout << "Computer chose Paper. You lose!" << endl;
				++losses;
			}
		}
		else if (choicePlayer == 2) {
			if (choicePC == 1) {
				cout << "Computer chose Rock. You win!" << endl;
				++wins;
			}
			else if (choicePC == 2) {
				cout << "Computer chose Paper. It's a tie!" << endl;
			}
			else if (choicePC == 3) {
				cout << "Computer chose Scissors. You lose!" << endl;
				++losses;
			}
		}
		else if (choicePlayer == 3) {
			if (choicePC == 1) {
				cout << "Computer chose Rock. You lose!" << endl;
				++losses;
			}
			else if (choicePC == 2) {
				cout << "Computer chose Paper. You win!" << endl;
				++wins;
			}
			else if (choicePC == 3) {
				cout << "Computer chose Scissors. It's a tie!" << endl;
			}
		}
		cout << "Wins: " << wins << endl;
		cout << "Losses: " << losses << endl;
	}
	return 0;
}