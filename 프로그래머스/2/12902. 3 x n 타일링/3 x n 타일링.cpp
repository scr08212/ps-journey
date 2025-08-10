#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;

int solution(int n) {
    int answer = 0;
    vector<long long> dp(n+1); // dp 0-n;
    
    dp[0] = 1;
    dp[2] = 3;
    
    for(int i = 4; i<=n; i+=2)
    {
        dp[i] = (dp[i-2] % mod * 3) % mod;
        for(int j = 4; j<=i; j+=2)
        {
            dp[i] = (dp[i]%mod +  (dp[i-j]%mod * 2)%mod)%mod;
        }
    }
    answer = dp[n];
    return answer;
}