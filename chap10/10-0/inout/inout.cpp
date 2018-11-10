#include <fstream>
#include <string>

int main()
{
    std::ifstream infile("in.txt");
    std::ofstream outfile("out.txt");

    std::string s;

    while (std::getline(infile, s)) {
        outfile << s << std::endl;
    }

    return 0;

}
