#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    int fail_count = 0;

    for (int i = 1; i < argc; ++i) {
        std::ifstream infile(argv[i]);
        if (infile) {
            std::string s;
            while (std::getline(infile, s))
                std::cout << s << std::endl;
        } else {
            std::cerr << "cannot open file " << argv[i] << std::endl;
            ++fail_count;
        }
    }

    return fail_count;
}
