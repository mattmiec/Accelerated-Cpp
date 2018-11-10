#ifndef GUARD_medavg_h
#define GUARD_medavg_h

// medavg.h
#include <algorithm>
#include <stdexcept>
#include <vector>

template <class T> T median(std::vector<T>);
double average(const std::vector<double>&);

// compute the median of a vector<T>
template <class T>
T median(std::vector<T> vec)
{
    typedef typename std::vector<T>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");

    std::sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

#endif
