#include <iostream>
#include <string>
using namespace std;

int main() {
    string in;
    char c;
    int val;

    cout << "ASCII CHARACTER FINDER\n"
            "----------------------\n"
            "ENTER ANYTHING: ";
    getline(cin, in);
    for (int i = 0; i < in.length(); ++i){
        c = in[i];
        val =  static_cast<int>(c);
        cout << "----------------------\n"
                "THE ASCII VALUE OF " << c << " IS " << val << endl;
    }
    cout << "----------------------" << endl;
    system("pause");
    system("cls");
    main();
    return 0;
}