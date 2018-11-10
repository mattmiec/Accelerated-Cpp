#include "frame.h"
#include "concat.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;

int main()
{
    vector<string> unframed;
    string s;

    while (getline(cin, s))
        unframed.push_back(s);

    vector<string> framed = frame(unframed);

    vector<string> vc = vcat(unframed, framed);
    vector<string> hc = hcat(unframed, framed);

    cout << endl << "VCAT:" << endl;
    for (vector<string>::size_type i = 0; i != vc.size(); ++i) {
        cout << vc[i] << endl;
    }

    cout << endl << "HCAT:" << endl;
    for (vector<string>::size_type i = 0; i != hc.size(); ++i) {
        cout << hc[i] << endl;
    }
        
    return 0;  
}
