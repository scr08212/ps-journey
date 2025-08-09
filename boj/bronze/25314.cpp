#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int repeat = n/4;

    for(int i = 0; i < repeat; i++)
    {
        cout << "long ";
    }

    cout << "int";

    return 0;
}