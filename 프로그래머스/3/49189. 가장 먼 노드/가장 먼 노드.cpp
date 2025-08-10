#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1);
    vector<int> distance(n + 1);
    
    for(vector<int> item : edge)
    {
        int n1 = item[0];
        int n2 = item[1];
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    queue<int> q;
    q.push(1);
    distance[1] = 0;
    visited[1] = true;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int next: graph[cur])
        {
            if(visited[next])
                continue;
            visited[next] = true;
            distance[next] = distance[cur] + 1;
            q.push(next);
        }
    }

    int maxDistance = *max_element(distance.begin(), distance.end());
    answer = count(distance.begin(), distance.end(), maxDistance);
    return answer;
}