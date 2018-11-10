#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h
// header for Student_info-related functions
#include <iostream>
#include <string>
#include <vector>

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&);
    double grade() const;
private:
    std::string n;
    double midterm, final, total_grade;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif
