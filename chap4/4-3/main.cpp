#include <iostream>
#include <iomanip>

using std::cout;
using std::setw;
using std::streamsize;
using std::endl;

int max = 10000;

int digits(int n)
{
    int digits = 0;
    while (n != 0)
    {
        n /= 10;
        digits += 1;
    }
    return digits;
}

int main()
{
    int dmax = digits(max); // digits in max
    int dmax2 = digits(max*max); // digits in max*max

    for (int i = 0; i <= max; ++i) {
        streamsize width = cout.width();
        cout << setw(dmax + 1)
             << i
             << setw(dmax2 + 1)
             << i*i
             << setw(width)
             << endl;
    }
}
