#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> baskets(n);
    iota(baskets.begin(), baskets.end(), 1);

    int n1, n2;
    for(int i = 0; i < m; i++)
    {
        cin >> n1 >> n2;
        swap(baskets[n1 - 1], baskets[n2 - 1]);
    }

    for(int i = 0; i<n; i++)
    {
        cout << baskets[i] << " ";
    }
}

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}