#include "frame.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;

int main()
{
    vector<string> lines;
    string s;

    while (getline(cin, s))
        lines.push_back(s);

    vector<string> pic = frame(lines);

    for (vector<string>::size_type i = 0; i != pic.size(); ++i) {
        cout << pic[i] << endl;
    }
        
    return 0;  
}
