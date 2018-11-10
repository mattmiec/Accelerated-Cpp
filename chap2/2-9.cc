#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a,b;
    cout << "Enter first integer to compare: ";
    cin >> a;
    cout << "Enter second integer to compare: ";
    cin >> b;

    if (a < b) {
        cout << "The integer ";
        cout << a;
        cout << " is less than the integer ";
        cout << b;
        cout << "." << endl;
    } else {
        if (a > b) {
            cout << "The integer ";
            cout << b;
            cout << " is less than the integer ";
            cout << a;
            cout << "." << endl;
        } else {
            cout << "The integer ";
            cout << a;
            cout << " is is equal to the integer ";
            cout << b;
            cout << "." << endl;
        }
    }

    return 0;
}
            

