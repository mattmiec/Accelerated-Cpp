#ifndef GUARD_analysis_h
#define GUARD_analysis_h

// analysis.h

#include "Student_info.h"

#include <iostream>
#include <vector>

void write_analysis(std::ostream&,
                    const std::string&,
                    double(const std::vector<Student_info>&), 
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);
double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);
double grade_aux(const Student_info&);

#endif
