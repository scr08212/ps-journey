#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a, vector<int> b) {
        if(a[1] != b[1])
            return a[1] > b[1];
        if(a[0] != b[0])
            return a[0] > b[0];
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    int elapsed = 0;
    int idx = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    sort(jobs.begin(), jobs.end());
    
    while(idx < size || !pq.empty())
    {
        while(idx < size && jobs[idx][0] <= elapsed)
        {
            pq.push(jobs[idx]);
            idx++;
        }
        
        if (!pq.empty()) {
            auto job = pq.top();
            pq.pop();
            elapsed += job[1];
            answer += elapsed - job[0];
        }
        else
        {
            elapsed = jobs[idx][0];
        }
    }
    
    return answer / size;
}