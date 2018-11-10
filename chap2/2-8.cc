#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int product = 1;

    for (int i = 2; i < 10; ++i)
    {
        product *= i;
    }

    cout << "The product of integers [1, 10) is: ";
    cout << product << endl;

    return 0;
}
