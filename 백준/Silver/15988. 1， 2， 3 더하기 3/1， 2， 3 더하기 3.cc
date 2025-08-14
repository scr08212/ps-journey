#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define MOD 1000000009

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long int dp[1000001]{0};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    while(n--)
    {
        int num;
        cin >> num;
        if(dp[num] == 0)
        {
            for(int i = 4; i<=num; i++)
            {
                dp[i] = ((dp[i-1] + dp[i-2]) % MOD + dp[i-3]) % MOD;
            }           
        }
        cout << dp[num] << "\n";
    }
}