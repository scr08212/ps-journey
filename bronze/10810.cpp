#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<int> bags(n);

    for (int i = 0; i<m; i++)
    {
        int from, to, num;
        cin >> from >> to >> num;

        for(int r = from - 1; r<to; r++)
            bags[r] = num;
    }


    for(int i = 0; i<n; i++)
    {
        cout << bags[i] << " "; 
    }

    return 0;
}