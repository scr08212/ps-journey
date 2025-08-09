#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<char>> arr(15);

    for(int i = 0; i<5; i++)
    {
        string str;
        cin >> str;

        for(int j = 0; j<str.size(); j++)
        {
            arr[j].push_back(str[j]);
        }
    }

    for(vector<char> v : arr)
    {
        for(char c : v)
        {
            cout<<c;
        }
    }
}