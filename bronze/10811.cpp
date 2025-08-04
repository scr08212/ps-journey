#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> baskets(n);
    iota(baskets.begin(), baskets.end(), 1);

    for(int i = 0; i<m; i++)
    {
        int from, to;
        cin >> from >> to;

        reverse(baskets.begin() + from - 1, baskets.begin() + to);
    }

    for(int b : baskets)
        cout << b << " ";
}