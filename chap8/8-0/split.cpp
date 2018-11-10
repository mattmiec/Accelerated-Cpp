#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

using std::cin;
using std::cout;
using std::find_if;
using std::isspace;
using std::ostream_iterator;
using std::string;

template <class Out> void split(const string&, Out);
bool space(char);
bool not_space(char);

int main()
{
    string s;
    while (getline(cin, s))
        split(s, ostream_iterator<string>(cout, "\n"));
    return 0;
}

template <class Out>
void split(const string& str, Out os)
{
    
    typedef string::const_iterator iter;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy the characters in [i, j)
        if (i != str.end())
            *os++ = string(i, j);

        i = j;
    }
}

bool space(char c)
{
    return std::isspace(c);
}

bool not_space(char c)
{
    return !std::isspace(c);
}
