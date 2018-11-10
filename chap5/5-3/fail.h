#ifndef GUARD_fail_h
#define GUARD_fail_h

// fail.h header file
#include <list>
#include "Student_info.h"
#include "grade.h"

typedef std::list<Student_info> student_container;

bool fgrade(const Student_info& s);
student_container extract_fails(student_container& students);

#endif
