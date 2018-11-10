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
    std::istream& read(std::istream&);
    bool grade() const;
private:
    std::string n;
    double midterm, final;
    bool pf;
};

bool compare(const Student_info&, const Student_info&);
#endif
