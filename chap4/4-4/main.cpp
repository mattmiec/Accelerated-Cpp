#include <iostream>
#include <iomanip>

using std::cout;
using std::setw;
using std::streamsize;
using std::endl;

double max = 1000;

int digits(double d)
{
    int digits = 0;
    while (d >= 1)
    {
        d /= 10;
        digits += 1;
    }
    return digits;
}

int main()
{
    int dmax = digits(max); // digits in max
    int dmax2 = digits(max*max); // digits in max*max

    for (double d = 0.0; d <= max; d += 1.0) {
        streamsize width = cout.width();
        cout << setw(dmax + 1)
             << d
             << setw(dmax2 + 1)
             << d*d
             << setw(width)
             << endl;
    }
}
