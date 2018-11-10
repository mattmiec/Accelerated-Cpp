#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> u(10,100);
    std::vector<int> v;
    std::copy(u.begin(), u.end(), std::back_inserter(v));

    for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    return 0;
}
