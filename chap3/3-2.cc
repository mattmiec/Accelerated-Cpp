#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter a sequence of integers, followed by end-of-file: ";
    vector<int> numbers;
    int n;
    while (cin >> n)
        numbers.push_back(n);
    sort(numbers.begin(), numbers.end());
    vector<int>::size_type size = numbers.size();
    for (int i = 0; i < 4; ++i) {
        for (int j = i * size/4; j < ((i+1) * size)/4; ++j)
            cout << numbers[j] << ' ';
        cout << endl;
    }

    return 0;
}
