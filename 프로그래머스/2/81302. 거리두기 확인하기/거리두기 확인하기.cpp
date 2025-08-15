#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check(vector<string> place)
{
    int deltaX[] {1, -1, 0, 0};
    int deltaY[] {0, 0, -1, 1};
    
    vector<pair<int, int>> candidates; // {y, x}
    for(int y = 0; y< place.size(); y++)
    {
        for(int x = 0; x<place[y].size(); x++)
        {
            if(place[y][x] == 'P')
            {
                candidates.push_back({y, x});
            }
        }
    }
    
    for(pair<int, int> candidate: candidates)
    {
        int dist[5][5]{0};
        queue<pair<int, int>> reservation;
        reservation.push(candidate);
        while(!reservation.empty())
        {
            pair<int, int> cur = reservation.front();
            reservation.pop();
            int y = cur.first;
            int x = cur.second;
            
            for(int dir = 0; dir<4; dir++)
            {
                int nextY = y + deltaY[dir];
                int nextX = x + deltaX[dir];
                
                if(nextX < 0 || nextX > 4 || nextY < 0 || nextY > 4)
                    continue;
                if(nextY == candidate.first && nextX == candidate.second)
                    continue;
                if(place[nextY][nextX] == 'X')
                    continue;
                if(dist[nextY][nextX] != 0)
                    continue;
                dist[nextY][nextX] = dist[y][x] + 1;
                if(dist[nextY][nextX] > 2)
                    continue;
                
                if(place[nextY][nextX] == 'P')
                    return false;
                
                reservation.push({nextY, nextX});
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // bfs
    
    for(auto place : places)
    {
        answer.push_back(check(place));
    }
    
    return answer;
}