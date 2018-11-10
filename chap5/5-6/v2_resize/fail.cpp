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
    vector<Student_info>::size_type i = 0, j = 0, n = students.size();

    // invariant: elements [0,j) of students represent passing grades
    //            elements [0,i) have been tested 
    while (i != n) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
        }
        else {
            students[j] = students[i];
            ++j;
        }
        ++i;
    }
    students.resize(j);

    return fail;
}
