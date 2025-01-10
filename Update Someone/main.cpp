#include <iostream>
#include <random>
#include <string>
#include <synchapi.h>
using namespace std;

int main() {
    string name;
    int wait_time;
    int load_time;
    int pct = 0;
    srand(time(NULL));

    cout << "Who would you like to update?\n"
            "Name: ";
    getline(cin, name);
    
    cout << "\nPlease wait while we update " << name << "." ;
    wait_time = (rand() % 5 + 1) * 1000;
    Sleep(wait_time);
    while (pct < 100) {
        pct += rand() % 10 + 1;
        cout << endl << "Update is at " << pct << "%.";
        load_time = (rand() % 5 + 1) * 1000;
        Sleep(load_time);
    }
    cout  << "\nUpdate is at 100%" << endl << endl;

    cout << "Thank you for updating!" << endl << endl;

    system("pause");

    return 0;
}