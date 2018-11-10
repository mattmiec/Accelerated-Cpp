// fail.cpp source file
#include "fail.h"

using std::vector;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
    return grade(s) < 60.0;
}

// separate passing and failing student recrods: first try
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;

    // invariant: elements [0,i) of students represent passing grades
    while (i != students.size())
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else
            ++i;

    return fail;
}
