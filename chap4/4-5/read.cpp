// source for read function
#include "read.h"

using std::string;
using std::vector;
using std::cin;
using std::istream;

istream& read(istream& is, vector<string>& vec)
{
    string word;
    while(is >> word)
    {
        vec.push_back(word);
    }
}
