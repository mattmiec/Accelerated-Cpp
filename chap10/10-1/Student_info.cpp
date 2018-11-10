// Student_info.cpp
// source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"
#include <cstddef>

using std::istream;
using std::vector;

Student_info::Student_info(): midterm(0), final(0) { }

Student_info::Student_info(istream& is) { read(is); }

istream& Student_info::read(istream& is)
{
    is >> n >> midterm >> final;
    read_hw(is, homework);
    return is;
}

double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
}

std::string Student_info::letter_grade() const
{
    static const double numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
    static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};

    static const std::size_t ngrades = sizeof(numbers)/sizeof(*numbers);

    const double number_grade = grade();

    for (std::size_t i = 0; i < ngrades; ++i) {
        if (number_grade >= numbers[i])
            return letters[i];
    }

    return "?\?\?";
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
