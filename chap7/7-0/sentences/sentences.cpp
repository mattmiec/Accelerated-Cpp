#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

std::vector<std::string> gen_sentence(const Grammar& g);
void gen_aux(const Grammar& g, const std::string& word, std::vector<std::string>& ret);
bool bracketed(const std::string& s);
int nrand(int n);
Grammar read_grammar(std::istream&);
std::vector<std::string> split(const std::string& s);

int main()
{
    // generate the sentence
    std::vector<std::string> sentence = gen_sentence(read_grammar(std::cin));

    // write the first word, if any
    std::vector<std::string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        std::cout << *it;
        ++it;
    }

    // write the rest of the words, each preceded by a space
    while (it != sentence.end()) {
        std::cout << " " << *it;
        ++it;
    }

    std::cout << std::endl;
    return 0;
}

std::vector<std::string> gen_sentence(const Grammar& g)
{
    std::vector<std::string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

void gen_aux(const Grammar& g, const std::string& word, std::vector<std::string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw std::logic_error("empty rule");

        // fetch the set of possible rules
        const Rule_collection& c = it->second;

        // from which we select one at random
        const Rule& r = c[nrand(c.size())];

        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

bool bracketed(const std::string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// return a random integer in the range [0, n)
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw std::domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = std::rand() / bucket_size;
    while (r >= n);

    return r;
}

// read a grammar from a given input stream
Grammar read_grammar(std::istream& in)
{
    Grammar ret;
    std::string line;

    // read the input
    while (std::getline(in, line)) {

        // split the input into words
        std::vector<std::string> entry = split(line);

        if (!entry.empty())
            // use the category to store associated rule
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
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
