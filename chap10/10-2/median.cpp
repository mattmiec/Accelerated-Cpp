#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template <class T, class I> T median(I, I);

int main()
{
    std::cout << std::endl;
    std::cout << "Calling median with double[]:" << std::endl;

    double array[] = {8.0, 1.0, 3.0, 9.0, 4.0, 2.0, 7.0, 5.0, 6.0};

    std::size_t n = sizeof(array)/sizeof(*array);

    std::cout << "Before taking median, array = ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Median is: " << median<double>(array, array + n) << std::endl;

    std::cout << "After taking median, array = ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Calling median with std::vector<double>:" << std::endl;

    std::vector<double> arrayv(array, array + n);

    std::size_t nv = arrayv.size(); //sizeof(arrayv)/sizeof(arrayv[0]);

    std::cout << "Before taking median, array = ";
    for (std::size_t i = 0; i < nv; ++i) {
        std::cout << arrayv[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Median is: " << median<double>(arrayv.begin(), arrayv.end()) << std::endl;

    std::cout << "After taking median, array = ";
    for (std::size_t i = 0; i < nv; ++i) {
        std::cout << arrayv[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

template <class T, class I>
T median(I ptr, I end)
{

    std::ptrdiff_t size = end - ptr;

    if (size < 0)
        throw std::domain_error("negative pointer range");
    if (size == 0)
        throw std::domain_error("median of empty container");

    T* array = new T[size];

    std::copy(ptr, end, array);

    std::sort(array, array + size);

    std::cout << "In median function, size = " << size << std::endl;
    std::cout << "In median function, sorted array = ";
    for (T* i = array; i != array + size; ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    std::size_t mid = size/2;

    return size % 2 == 0 ? (array[mid] + array[mid - 1])/2.0 : array[mid];

    delete[] array;
}
