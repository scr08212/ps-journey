#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        string str;
        cin >> str;
        cout << str.front() << str.back() << "\n";
    }
}