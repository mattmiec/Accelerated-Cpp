#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "Enter a sequence of strings: ";
    string nextword;
    vector<string> words;
    vector<int> words_count;
    int index = 0;
    while (cin >> nextword) {
        bool word_is_new = true;
        for (int i = 0; i != words.size(); ++i) {
            if (nextword == words[i]) {
                ++words_count[i];
                word_is_new = false;
                break;
            }
        }
        if (word_is_new) {
            words.push_back(nextword);
            words_count.push_back(1);
        }
    }
    for (int i = 0; i != words.size(); ++i) {
        cout << "The word \'" + words[i] + "\' appears ";
        cout << words_count[i];
        cout << " times." << endl;
    }

    return 0;

}
