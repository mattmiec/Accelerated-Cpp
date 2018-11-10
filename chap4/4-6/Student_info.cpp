// Student_info.cpp
// source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
        // read and store the student's name and midterm and final grades
        double midterm, final;
        vector<double> homework;
        is >> s.name >> midterm >> final;

        read_hw(is, homework); // read and store all the student's homework grades
        s.grade = grade(midterm, final, homework);
        return is;
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
