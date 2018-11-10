#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "medavg.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades and final exam grades
// does not copy its argument because median does so for us
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has no homework grades recorded");
    return grade(midterm, final, median(hw));
}

// grade from Student_info struct
double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

// for average analysis
double average_grade(const Student_info& s)
{
    if (s.homework.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, average(s.homework));
}

// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    std::remove_copy(s.homework.begin(), s.homework.end(), std::back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}
