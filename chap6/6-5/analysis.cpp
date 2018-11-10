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
                    double analysis(const std::vector<Student_info>&), 
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
                   ", median(didnt) = " << analysis(didnt) << std::endl;
}

double median_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    std::transform(students.begin(), students.end(), std::back_inserter(grades), grade_aux);
    return median(grades);
}

double average_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    std::transform(students.begin(), students.end(), std::back_inserter(grades), average_grade);
    return median(grades);
}

double optimistic_median_analysis(const std::vector<Student_info>& students)
{
    std::vector<double> grades;
    std::transform(students.begin(), students.end(), std::back_inserter(grades), optimistic_median);
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
