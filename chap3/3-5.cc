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
    vector<double> grades;

    int count = 5;

    // loop over students
    while (true) {

        // ask for and read the student's name
        cout << "Please enter the students name or end-of-file to complete entry: ";
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
        cout << "Enter " << count << " homework grades: ";

        // the number and sum of grades read so far
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
        cout << names[i] << " ";
    }
    cout << endl;
    
    streamsize prec = cout.precision();
    cout << "Grades: " << setprecision(3);
    for (int i = 0; i < names.size(); ++i) {
        cout << grades[i] << " ";
    }
    cout << setprecision(prec) << endl;

    return 0;
}
