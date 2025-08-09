#include<iostream>
#include<string>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    string str;
    int n;

    cin >> str >> n;
    cout << str[n-1];
}