#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    double coords[] = {1.5, 2.5, 3.5};
    std::vector<double> vcoords;

    const std::size_t ndim = sizeof(coords)/sizeof(*coords);

    std::copy(coords, coords + ndim, back_inserter(vcoords));

    for (std::vector<double>::size_type i = 0; i < vcoords.size(); ++i) {
        std::cout << vcoords[i] << std::endl;
    }

    return 0;
}
