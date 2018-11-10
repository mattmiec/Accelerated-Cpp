#include "findurls.h"
#include <iostream>
#include <iomanip>

using std::string;
using std::vector;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string text;
    getline(cin, text);

    vector<string> urls = find_urls(text);

    for (vector<string>::const_iterator iter = urls.begin(); iter != urls.end(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}
