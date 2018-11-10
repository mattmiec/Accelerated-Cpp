// source file for median and average functions
#include <algorithm> // to get declaration of sort
#include <stdexcept> // to get declaration of domain_error
#include <vector> // to get declaration of vector
#include <numeric> // for accumulate

using std::domain_error;
using std::sort;
using std::vector;
using std::accumulate;

typedef vector<double>::size_type vec_sz;

// compute the median of a vector<double>
double median(vector<double> vec)
{
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}


double average(const vector<double>& v)
{
    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("average of an empty vector");

    return accumulate(v.begin(), v.end(), 0.0) / size;
}
