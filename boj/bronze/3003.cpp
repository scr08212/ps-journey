#include<iostream>

using namespace std;

int main()
{
    int pieces[6] { 1, 1, 2, 2, 2, 8};
    for(int piece : pieces)
    {
        int i;
        cin >> i;
        cout << piece - i << " ";
    }
}