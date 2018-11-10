// fail.cpp source file
#include "fail.h"

using std::list;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
    return grade(s) < 60.0;
}

// separate passing and failing student recrods: first try
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end())
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;

    return fail;
}
