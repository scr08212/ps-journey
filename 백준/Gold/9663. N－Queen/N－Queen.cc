#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ans = 0, n = 0;
vector<int> col;

bool isValid(int currentY)
{
    for (int y = 0; y < currentY; y++)
    {
        if (col[y] == col[currentY] || currentY - y == abs(col[currentY] - col[y]))
            return false;
    }
    return true;
}

void solve(int y)
{
    if (y == n)
    {
        ans++;
        return;
    }

    // back tracking
    for (int x = 0; x < n; x++)
    {
        col[y] = x;
        if (isValid(y))
            solve(y + 1);
    }
}

int main()
{
    cin >> n;
    col = vector<int>(n, 0);
    solve(0);
    cout << ans;
}