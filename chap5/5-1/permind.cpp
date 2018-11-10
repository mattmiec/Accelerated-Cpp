#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;
using std::sort;
using std::streamsize;
using std::setw;
using std::max;

struct permutation {
    vector<string> seq;
    int r;
};

vector<string> split(const string&);
permutation permute(const vector<string>&, int);
bool compare(const permutation&, const permutation&);
string::size_type width(const vector<string>& v);

int main()
{
    vector<permutation> perms;
    vector<string> phrase;
    string s;

    // read line into phrases, make rotations
    while(getline(cin, s)) {
        phrase = split(s);
        for (int r = 0; r != phrase.size(); ++r)
            perms.push_back(permute(phrase, r));
    }

    sort(perms.begin(), perms.end(), compare);

    // split phrases into left and right
    vector<string> left, right;
    left.resize(perms.size());
    right.resize(perms.size());
    for (int i = 0; i != perms.size(); ++i) {
        int n = perms[i].seq.size();
        int r = perms[i].r;
        for (int j = 0; j != n; ++j) {
            string nextword = perms[i].seq[(n - r + j) % n];
            if (j < r) {
                left[i] += nextword;
                if (j != r - 1)
                    left[i] += " ";
            }
            else {
                right[i] += nextword;
                if (j != n - 1)
                    right[i] += " ";
            }
        }
    }

// either of the below formatting schemes work

    string::size_type w = width(left);
    cout << endl;
    for (int i = 0; i != left.size(); ++i) {
        streamsize wid = cout.width();
        cout << setw(w) << left[i] << setw(wid);
        cout << string(4,' ');
        cout << right[i];
        cout << endl;
    }
    cout << endl;

//    string::size_type w = width(left);
//    cout << endl;
//    for (int i = 0; i != left.size(); ++i) {
//        cout << string(w - left[i].size(), ' ');
//        cout << left[i];
//        cout << string(4, ' ');
//        cout << right[i];
//        cout << endl;
//    }
//    cout << endl;

    return 0;
}

vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size()) {
        // ignore leading blanks
        // invariant characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            ++j;

        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i fand taking j - i characters
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

permutation permute(const vector<string>& phrase, int r)
{
    // vector to hold rotated phrase
    vector<string> rotated;
    int n = phrase.size();

    for (int i = 0; i != n; ++i) {
        rotated.push_back(phrase[(i + r)%n]);
    }

    permutation p;
    p.seq = rotated;
    p.r = r;
    return p;
}

bool compare(const permutation& p1, const permutation& p2)
{
    return p1.seq[0] < p2.seq[0];
}

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen,v[i].size());
    return maxlen;
}
