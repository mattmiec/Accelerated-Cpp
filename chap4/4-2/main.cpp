#include <iostream>
#include <iomanip>

using std::cout;
using std::setw;
using std::streamsize;
using std::endl;

int main()
{
    for (int i = 0; i <= 100; ++i) {
        streamsize width = cout.width();
        cout << setw(4)
             << i
             << setw(6)
             << i*i
             << setw(width)
             << endl;
    }
}
