// analysis.cpp

#include "analysis.h"
#include "Student_info.h"
#include "grade.h"
#include "medavg.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

void write_analysis(std::ostream& out,
                    const std::string& name,
                    double gradefunc(const Student_info&), 
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did, gradefunc) <<
                   ", median(didnt) = " << analysis(didnt, gradefunc) << std::endl;
}

double analysis(const std::vector<Student_info>& students, double gradefunc(const Student_info& s))
{
    std::vector<double> grades;
    std::transform(students.begin(), students.end(), std::back_inserter(grades), gradefunc);
    return median(grades);
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (std::domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}
