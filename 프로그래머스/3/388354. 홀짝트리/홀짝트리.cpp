#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int find_node_type(int node_num, int child_num)
{
    if(node_num % 2 == 1)
    {
        if(child_num % 2 == 1)
            return 0;
        else
            return 2;
    }
    else
    {
        if(child_num %2 ==0)
            return 1;
        else
            return 3;
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    
    // 1. 그래프 전처리
    vector<vector<int>> graph(1000001);
    for(auto edge: edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    // 2. dfs, but dfs중 방문한 노드는 스킵. 이후 trees에 넣음
    vector<vector<int>> trees;
    vector<bool> visited(1000001, false);
    for(int node: nodes)
    {
        if(visited[node])
            continue;
        vector<int> cur_tree;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int cur_node = q.front(); q.pop();
            vector<int> cur_edge = graph[cur_node];
            visited[cur_node] = true;
            cur_tree.push_back(cur_node);
            for(auto child: cur_edge)
            {
                if(visited[child])
                    continue;
                q.push(child);
            }
        }
        trees.push_back(cur_tree);
    }
    
    // 3. 트리 순회
    for(auto tree: trees)
    {
        vector<int> v(4,0);
        // 4. 노드 순회
        for(int node:tree)
        {
            // 루트 아닐시 기준으로 두고 v에 넣음
            int child_num = graph[node].size();
            v[find_node_type(node, child_num - 1)]++;
        }
    
        // 5. 노드 순회 -> answer 채우기 
        for(int node:tree)
        {
            int child_num = graph[node].size();
            vector<int> v_copy(v);
            v_copy[find_node_type(node, child_num - 1)]--;
            v_copy[find_node_type(node, child_num)]++;
        
            if( (v_copy[0]>0 || v_copy[1]>0) && v_copy[2] == 0 && v_copy[3]==0)
                answer[0]++;
            else if( (v_copy[2]>0 || v_copy[3]>0) && v_copy[0] == 0 && v_copy[1]==0)
                answer[1]++;
        }
    }

    return answer;
}