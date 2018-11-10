#include <iostream>

int main()
{
    int x = 5;

    int* p = &x;
    std::cout << "x = " << x << std::endl;

    *p = 6;
    std::cout << "x = " << x << std::endl;

    return 0;
}
