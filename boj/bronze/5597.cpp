#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    bool attendance[31] = {false};

    for(int i = 0 ; i<28; i++)
    {
        int num;
        cin >> num;
        attendance[num] = true;
    }

    for(int i = 1; i<31; i++)
    {
        if(attendance[i] == false)
            cout << i << "\n";
    }
}