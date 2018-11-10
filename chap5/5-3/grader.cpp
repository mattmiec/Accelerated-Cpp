#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "grade.h"
#include "Student_info.h"
#include "fail.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::list;

int main()
{
    student_container students;
    Student_info record;
    string::size_type maxlen = 0; // length of longest name

    // read and store all the students' data
    // invariant: students contains all the student records read so far
    //            maxlen contains the length of the longest name in students
    while (read(cin, record)) {
        // fine length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    // alphabetize the student records
    students.sort(compare);

    // separate failures
    student_container failures = extract_fails(students);

    // write the names and grades
    cout << "Passing students: " << endl;

    for (student_container::const_iterator iter = students.begin(); iter != students.end(); ++iter) {

        // write the name, padded on the right to maxlen + 1 characters
        cout << iter->name
             << string(maxlen + 1 - iter->name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    // write the names and grades of failures
    cout << endl << "Failing students: " << endl;

    for (student_container::const_iterator iter = failures.begin(); iter != failures.end(); ++iter) {

        // write the name, padded on the right to maxlen + 1 characters
        cout << iter->name
             << string(maxlen + 1 - iter->name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}
