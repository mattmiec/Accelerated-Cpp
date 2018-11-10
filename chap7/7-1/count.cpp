#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool compare(std::pair<std::string, int>, std::pair<std::string, int>);

int main()
{
    std::string s;
    std::map<std::string, int> counters; // store each word and an associated counter

    // read the input, keeping track of each word and how often we see it
    while (std::cin >> s)
        ++counters[s];

    std::vector<std::pair<std::string, int> > counters_sorted(counters.begin(), counters.end());
    std::sort(counters_sorted.begin(), counters_sorted.end(), compare);

    // write the words and associated counts
    for (std::vector<std::pair<std::string, int> >::const_iterator it = counters_sorted.begin(); it != counters_sorted.end(); ++it) {
        std::cout << it->first << "\t" << it->second << std::endl;
    }

    return 0;
}

bool compare(std::pair<std::string, int> pair1, std::pair<std::string, int> pair2)
{
    return pair1.second < pair2.second;
}

