#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>
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
using std::vector;
using std::clock_t;
using std::clock;

int main()
{
    clock_t t1 = clock();

    vector<Student_info> students;
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
    sort(students.begin(), students.end(), compare);

    // separate failures
    vector<Student_info> failures = extract_fails(students);

    // write the names and grades
    cout << "Passing students: " << endl;

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    // write the names and grades of failures
    cout << endl << "Failing students: " << endl;

    for (vector<Student_info>::size_type i = 0; i != failures.size(); ++i) {

        // write the name, padded on the right to maxlen + 1 characters
        cout << failures[i].name
             << string(maxlen + 1 - failures[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(failures[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    cout << endl;

    clock_t t2 = clock();

    double elapsed_secs = double(t2 - t1) / CLOCKS_PER_SEC;

    cout << "ELASPED TIME: " << elapsed_secs << " secs" << endl;

    return 0;
}
