#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h
// header for Student_info-related functions
#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double grade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif
