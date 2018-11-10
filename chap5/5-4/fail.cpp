// fail.cpp source file
#include "fail.h"

using std::list;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
    return grade(s) < 60.0;
}

// separate passing and failing student recrods: first try
Student_container extract_fails(Student_container& students)
{
    Student_container fail;
    Student_container::iterator iter = students.begin();

    while (iter != students.end())
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;

    return fail;
}
