#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i<=n; i++)
    {
        cout << string(n-i, ' ') << string(2*i-1, '*') << '\n';
    }
    for(int i = n-1; i>= 1; i--)
    {
        cout << string(n-i, ' ') << string(2*i-1, '*') << '\n';
    }
}