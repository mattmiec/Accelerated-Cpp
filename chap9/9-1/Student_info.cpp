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
    read_hw(is, homework);
    total_grade = ::grade(midterm, final, homework);
    return is;
}

double Student_info::grade() const
{
    return total_grade;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}
