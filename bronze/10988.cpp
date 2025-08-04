#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;

    cout << (str == string(str.rbegin(), str.rend()));
}