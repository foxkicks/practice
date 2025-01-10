#include "header.h"
#include "FileEditor.cpp"
#include <iomanip>
using namespace std;

FileEditor FE;

void static spinner(vector<string> vec, int result) {
	int timer = 50;
	for (int k = 0; k < 4; ++k) {
		for (int j = 0; j < 9; ++j) {
			for (int i = 0; i < 9; ++i) {
				cout << "[????????????]";
				if (i == j) cout << " <-----";
				cout << endl;
			}
			Sleep(timer);
			timer += 5;
			system("cls");
		}
	}
	
	for (int j = 0; j < 5; ++j) {
			for (int i = 0; i < 9; ++i) {
				cout << "[????????????]";
				if (i == j) cout << " <-----";
				cout << endl;
			}
			if (j == 4) break;
			timer += 200;
			Sleep(timer);
			system("cls");
	}
	Sleep(50);
	system("cls");
	cout <<	"[????????????]\n"
			"[????????????]\n"
			"[????????????]\n"
			"[????????????]\n"
			"[" << vec.at(result) << "] <-----\n"
			"[????????????]\n"
			"[????????????]\n"
			"[????????????]\n"
			"[????????????]\n";
	system("pause");
	system("cls");
}

void static spin() {
	int result = 0;
	int total = 0;
	string str;
	vector<string> vec;
	vec = FE.GetVector();
	FE.ShowList(vec);
	cout << endl;
	cout << "--------Menu--------\n[1] Spin the wheel!\n[2] Add an item.\n[3] Remove an item.\n[4] Sort the list.\n[5] Remove Duplicates" << endl << "\nChoose: ";
	int menu;
	string item;
	string fname = FE.GetFileName();
	cin >> menu;
	menu = menu;
	cin.ignore();
	cout << endl;
	switch (menu) {
	case 1:
		system("cls");
		break;
	case 2:
		cout << "Item: ";
		getline(cin, item);
		FE.AddItem(vec, item);
		cout << endl;
		FE.SaveList(vec, fname);
		system("cls");
		spin();
		break;
	case 3:
		int pos;
		cout << "Item #: ";
		cin >> pos;
		pos = pos - 1;
		while ((pos < 0) || (pos >= vec.size())) {
			cout << "Item does not exist.\n\nItem #: ";
			cin >> pos;
		}
		FE.RemoveItem(vec, pos);
		cout << endl;
		FE.SaveList(vec, fname);
		system("cls");
		spin();
		break;
	case 4:
		FE.SortList(vec);
		FE.SaveList(vec, fname);
		system("cls");
		cout << "List sorted." << endl << endl;
		spin();
		break;
	case 5:
		FE.RemoveDuplicates(vec);
		FE.SaveList(vec, fname);
		system("cls");
		cout << "Duplicates removed." << endl << endl;
		spin();
		break;
	default:
		system("cls");
		cout << "Try again." << endl << endl;
		spin();
		break;
	}
	srand(GetTickCount64());
	total = (int)vec.size();
	result = rand() % total;
	spinner(vec, result);
	cout << "The wheel landed on: " << vec.at(result) << endl << endl;
	spin();
}

int main() {
	system("title Spin The Wheel!");
	ifstream infile;
	string fname;
	cout << "Enter list name: ";
	getline(cin, fname);
	cout << endl;
	if (fname.find(".txt") == string::npos) fname = fname.append(".txt");
	infile.open(fname);
	if (infile) {
		cout << "Reading " << fname << endl << endl;
		infile.close();
		FE.SetFileName(fname);
		spin();
	}
	else {
		FE.MakeFile(fname);
		spin();
	}
}