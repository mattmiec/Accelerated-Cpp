#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    const int size1 = 10;
    const int size2 = 20;

    //output square
    for (int n = 0; n != size1; ++n) {
        cout << string(size1,'*') << endl;
    }

    //blank line
    cout << endl;

    //output rectangle
    for (int n = 0; n != size1; ++n) {
        cout << string(size2,'*') << endl;
    }

    //blank line
    cout << endl;

    //output triangle
    for (int n = 0; n != size1; ++n) {
        cout << string(n + 1,'*') << endl;
    }

    return 0;
}
