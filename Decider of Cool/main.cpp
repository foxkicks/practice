#include <iostream>
#include <random>
#include <windows.h>
using namespace std;

int main() {
    srand(time(NULL));
    int roll;
    string name;
    cout << "What is your name? ";
    cin >> name;
    cout << "Calculating coolness factor for " << name << "." << endl;
    for (int i = 0; i < 5; ++i) {
        Sleep(1000);
        cout << ".";
    }
    cout << endl;
    roll = rand() % 100 + 1;
    cout << "You are ";
    if (name == "Jace" || name == "Josh" || name == "Taylor" || name == "Nick") roll = 100;
    if (name == "Walter") roll = 1;
    if (roll >= 50) cout << "cool ";
    else cout << "uncool ";
    cout << "by a factor of " << roll << "/100 cool points." << endl;
    system("pause");
    return 0;
}