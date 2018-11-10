// source file for median and average functions
#include <algorithm> // to get declaration of sort
#include <stdexcept> // to get declaration of domain_error
#include <vector> // to get declaration of vector
#include <numeric> // for accumulate

using std::domain_error;
using std::sort;
using std::vector;
using std::accumulate;

double average(const vector<double>& v)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("average of an empty vector");

    return accumulate(v.begin(), v.end(), 0.0) / size;
}
