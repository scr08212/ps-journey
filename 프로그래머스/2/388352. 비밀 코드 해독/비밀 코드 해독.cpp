#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int n, int num, vector<int>& cur, vector<vector<int>>& q, vector<int>& ans, int& answer)
{
    if(cur.size() == 5)
    {
        // validation        
        for(int i = 0; i<q.size(); i++)
        {
            int check = 0;
            for(int target: cur)
            {
                for(int c:q[i])
                {
                    if(target == c)
                        check++;
                }
            }
            
            if(check != ans[i])
                return;
        }
        answer++;
        return;
    }
    
    for(int i = num; i<=n; i++)
    {
        cur.push_back(i);
        dfs(n, i+1,cur, q, ans, answer);
        cur.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> cur;
    dfs(n, 1, cur, q, ans, answer);
    
    return answer;
}