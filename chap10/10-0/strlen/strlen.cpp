#include <iostream>

std::size_t strlen(const char* p);

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "not enough command line arguments" << std::endl;
        return 1;
    }

    const char* s1 = "Hello";
    const char s2[] = "Hello";
    const char s3[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    std::cout << s1 << " has " << strlen(s1) << " characters" << std::endl;
    std::cout << s2 << " has " << strlen(s2) << " characters" << std::endl;
    std::cout << s3 << " has " << strlen(s3) << " characters" << std::endl;

    std::cout << argv[1] << " has " << strlen(argv[1]) << " characters" << std::endl;

    return 0;
}

std::size_t strlen(const char* p)
{
    std::size_t size = 0;
    while (*p++ != '\0')
        ++size;
    return size;
}
