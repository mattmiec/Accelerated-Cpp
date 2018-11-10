#include <string>
#include <iostream>

using namespace std;

int main() {

    cout << "Enter a sequence of strings: ";

    string word;
    string::size_type max = 0, min = -1;

    while (cin >> word) {
        string::size_type size = word.size();
        if (size > max)
            max = size;
        if (size < min)
            min = size;
    }

    cout << "Longest word is " << max << " characters." << endl;
    cout << "Shortest word is " << min << " characters." << endl;

    return 0;

}
