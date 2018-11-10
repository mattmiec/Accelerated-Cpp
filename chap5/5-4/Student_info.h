#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h
// header for Student_info-related functions
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

//typedef std::vector<Student_info> Student_container;
typedef std::list<Student_info> Student_container;

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

// overloaded sort function to sort either type of student_container
void sort(std::vector<Student_info>&);
void sort(std::list<Student_info>&);

#endif
