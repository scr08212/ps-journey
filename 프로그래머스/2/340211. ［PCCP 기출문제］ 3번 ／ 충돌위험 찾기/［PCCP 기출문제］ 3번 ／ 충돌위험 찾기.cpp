#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> getFastestRoute(vector<vector<int>>& points, vector<int>& route) 
{
    vector<vector<int>> result;
    vector<int> from, to;
    from = points[route[0]-1];
    result.push_back(from);

    for(int i = 1; i < route.size(); i++) 
    {
        to = points[route[i]-1];
        while(from[0] != to[0]) 
        {
            if(from[0] > to[0]) 
                from[0]--;
            else 
                from[0]++;
            result.push_back(from);
        }
        while(from[1] != to[1]) 
        {
            if(from[1] > to[1]) 
                from[1]--;
            else 
                from[1]++;
            result.push_back(from);
        }
    }
    return result;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) 
{
    int answer = 0;
    unsigned long max_move_size = 0;
    vector<vector<vector<int>>> moves;

    // 각 로봇의 이동 경로 계산
    for(int i = 0; i < routes.size(); i++) 
    {
        auto fastest_route = getFastestRoute(points, routes[i]);
        max_move_size = max(max_move_size, fastest_route.size());
        moves.push_back(fastest_route);
    }

    // 시뮬레이션
    for(int t = 0; t < max_move_size; t++) 
    {
        unordered_map<string, int> counter;
        for(auto& move : moves) 
        {
            if(t < move.size()) 
            {
                auto cur = move[t];
                string key = to_string(cur[0]) + "," + to_string(cur[1]);
                counter[key]++;
            }
        }
        for(auto& kv : counter) 
        {
            if(kv.second >= 2) answer++;
        }
    }
    return answer;
}
