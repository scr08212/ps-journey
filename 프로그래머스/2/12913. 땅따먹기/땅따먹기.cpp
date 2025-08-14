#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[2][4]{0};
    for(int i = 0; i<4; i++)
    {
        dp[0][i] = land[0][i];
    }
    // 점화식: dp[i][j] = land[i][j] + max(dp[i-1][k]) k!=j
    for(int i = 1; i<land.size(); i++)
    {
        for(int j = 0; j<4; j++)
        {
            int prev_max = 0;
            for(int k = 0; k<4; k++)
            {
                if(j != k)
                {
                    prev_max = max(prev_max, dp[0][k]);
                }
            }
            dp[1][j] = land[i][j] + prev_max;
        }
        
        for(int j = 0; j<4; j++)
        {
            dp[0][j] = dp[1][j];
        }
    }
    
    for(int i = 0; i<4; i++)
    {
        answer = max(answer, dp[0][i]);
    }
    return answer;
}