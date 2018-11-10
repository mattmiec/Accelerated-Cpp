#include <string>
#include <vector>
#include <iostream>
#include "read.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Word
{
    string word;
    int count;
};

int main()
{
    vector<string> vec;
    read(cin, vec);
    cout << "Number of words in input: " << vec.size() << endl;

    vector<Word> Words;
    for (int i = 0; i < vec.size(); ++i) { 
        bool repeat = false;
        for (int j = 0; j < Words.size(); ++j) {
            if (vec[i] == Words[j].word) {
                Words[j].count += 1;
                repeat = true;
                break;
            }

        }
        if (repeat == false) {
            Word newWord;
            newWord.word = vec[i];
            newWord.count = 1;
            Words.push_back(newWord);
        }
    }

    for (int j = 0; j < Words.size(); j++) {
        cout << Words[j].word << " appeared " << Words[j].count << " times." << endl;
    }

    return 0;
}
