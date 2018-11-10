#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::string word;
    std::vector<std::string> words;

    while (std::cin >> word) {
        words.push_back(word);
    }

    std::string cat;

    for (std::vector<std::string>::const_iterator iter = words.begin(); iter != words.end(); ++iter) {
        std::copy(iter->begin(), iter->end(), std::back_inserter(cat));
    }

    std::cout << cat << std::endl;

}
