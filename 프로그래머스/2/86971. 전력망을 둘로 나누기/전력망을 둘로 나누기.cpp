#include <string>
#include <vector>
#include <cmath>

using namespace std;


void func(int node, vector<vector<int>>& edges, vector<int>& visited, vector<int>& num_childs)
{
   for(auto next : edges[node])
   {
       if(visited[next])
           continue;
       visited[next] = true;
       func(next, edges, visited, num_childs);
       num_childs[node] += num_childs[next];
   }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    vector<vector<int>> edges(n+1);
    vector<int> visited(n+1, false);
    vector<int> num_childs(n+1, 1);
    
    for(auto wire: wires)
    {
        edges[wire[0]].push_back(wire[1]);
        edges[wire[1]].push_back(wire[0]);
    }
    
    func(1, edges, visited, num_childs);
    
    answer = n;
    for(int i = 1; i<=n; i++)
    {
        int gap = abs(n-2*num_childs[i]);
        if(gap < answer)
            answer = gap;
    }
    
    return answer;
}