#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;

int main()
{
    vector<string> names;
    vector<int> grades;

    int count = 5;

    // loop over students
    while (true) {

        // ask for and read the student's name
        cout << "Please enter the students name or leave blank to complete entry: ";
        string name;
        cin >> name;
        if (name.size() == 0)
            break;
        names.push_back(name);

        // ask for and read the midterm and final grades
        cout << "Please enter midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;
    
        // ask for the homework grades
        cout << "Enter " << count << " homework grades, "
                "followed by end-of-file: ";

        // the number and sum of grades read so far
        int count = 0;
        double sum = 0;

        // a variable into which to read
        double x;

        // invariant:
        //    we have read count grades so far, and
        //    sum is the sum of the first count grades
        for (int i = 0; i < count; ++i) {
            cin >> x;
            sum += x;
        }

        grades.push_back(0.2 * midterm + 0.4 * final + 0.4 * sum / count);

    }

    cout << "Students: ";
    for (int i = 0; i < names.size(); ++i) {
        cout << names[i];
    }
    cout << endl;
    
    cout << "Grades: ";
    for (int i = 0; i < names.size(); ++i) {
        cout << grades[i];
    }
    cout << endl;

    return 0;
}
