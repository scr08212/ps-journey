#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> mat(n * m);

    for(int i = 0; i<n * m; i++)
    {
        cin >> mat[i]; 
    }

    for(int i = 0; i<n * m; i++)
    {
        int value;
        cin >> value;
        mat[i] += value;

        if((i % m) + 1 == 0)
        {
            cout << "\n";
        }

        cout << mat[i] <<" ";
    }
}