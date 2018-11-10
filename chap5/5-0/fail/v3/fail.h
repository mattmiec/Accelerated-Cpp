#ifndef GUARD_fail_h
#define GUARD_fail_h

// fail.h header file
#include <vector>
#include "Student_info.h"
#include "grade.h"

bool fgrade(const Student_info& s);
std::vector<Student_info> extract_fails(std::vector<Student_info>& students);

#endif
