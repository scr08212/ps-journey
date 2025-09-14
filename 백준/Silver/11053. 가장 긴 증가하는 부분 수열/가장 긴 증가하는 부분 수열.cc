#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solve(vector<int> arr)
{
    int answer = 0;
    int n = arr.size();
    vector<int> dp(n, 1);
    
    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    answer = *max_element(dp.begin(), dp.end());
    
    return answer;
}

int main()
{
    int n;
    vector<int> arr;
    
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    
    cout << solve(arr);
}