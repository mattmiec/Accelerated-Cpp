// Student_info.cpp
// source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::vector;

Student_info::Student_info(): midterm(0), final(0) { }

Student_info::Student_info(istream& is) { read(is); }

istream& Student_info::read(istream& is)
{
    is >> n >> midterm >> final;
    double x;
    if (is) {
        while (is >> x);
        is.clear();
    }
    pf = ::pfgrade(midterm, final);
    return is;
}

bool Student_info::grade() const
{
    return pf;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return (x.grade() == true) && (y.grade() == false);
}
