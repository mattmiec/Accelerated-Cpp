#include <iostream>
#include <string>

template <class Bi> void reverse(Bi, Bi);
template <class T> void swap(T&, T&);

int main()
{
    std::string str;
    getline(std::cin, str);
    reverse(str.begin(), str.end());
    std::cout << str << std::endl;
}

template <class Bi> void reverse(Bi begin, Bi end)
{
    while (begin != end) {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

template <class T> void swap(T& t1, T& t2)
{
    T tmp = t1;
    t1 = t2;
    t2 = tmp;
    return;
}
