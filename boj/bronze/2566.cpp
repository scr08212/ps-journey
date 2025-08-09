#include<iostream>

using namespace std;

int main()
{
    int c, r, v = 0;
    for(int column = 1; column<=9; column++)
    {
        for(int raw = 1; raw<=9; raw++)
        {
            int value;
            cin >> value;
            if(v <= value)
            {
                v = value;
                c = column;
                r = raw;
            }
        }
    }

    cout << v << "\n" << c << " " << r; 
}