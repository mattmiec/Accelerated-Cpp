#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string&);
std::map<std::string, std::vector<int> >
    xref(std::istream&, std::vector<std::string>(const std::string&) = split);

int main()
{
    // call xref using split by default
    std::map<std::string, std::vector<int> > ret = xref(std::cin);

    // write the results
    for (std::map<std::string, std::vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        // write the word
        std::cout << it->first << " occurs on line(s): ";

        // followed by one or more line numbers
        std::vector<int>::const_iterator line_it = it->second.begin();
        std::cout << *line_it;

        ++line_it;
        // write the rest of the line numbers, if any
        while (line_it != it->second.end()) {
            std::cout << ", " << *line_it;
            ++line_it;
        }

        // write a new line to separate each word from the next
        std::cout << std::endl;
    }
    return 0;
}

std::map<std::string, std::vector<int> >
    xref(std::istream& in, std::vector<std::string> find_words(const std::string&))
{
    std::string line;
    int line_number = 0;
    std::map<std::string, std::vector<int> > ret;

    // read the next line
    while (std::getline(in, line)) {
        ++line_number;

        // break the input line into words
        std::vector<std::string> words = find_words(line);

        // remember that each word occurs on the current line
        for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it) {
            std::vector<int>& lines = ret[*it];
            if (!lines.empty()) {
                if (!(lines[lines.size() - 1] == line_number))
                    lines.push_back(line_number);
            } else {
                lines.push_back(line_number);
            }
        }
    }
    return ret;
}

std::vector<std::string> split(const std::string& s)
{
    std::vector<std::string> ret;
    typedef std::string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size()) {
        // ignore leading blanks
        // invariant characters in range [original i, current i) are all spaces
        while (i != s.size() && std::isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != s.size() && !std::isspace(s[j]))
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
