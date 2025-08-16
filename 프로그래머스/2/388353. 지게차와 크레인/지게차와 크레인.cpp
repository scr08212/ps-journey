#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> bfs(vector<string>& storage, char target)
{
    vector<pair<int, int>> output;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int height = storage.size();
    int width = storage[0].size();
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    
    queue<pair<int,int>> reservation;
    for(int y = 0; y<height; y++)
    {
        for(int x = 0; x<width; x++)
        {
            if(x == 0 || x == width-1 || y == 0 || y == height -1)
            {
                if(storage[y][x] == '-')
                {
                    reservation.push({y,x});
                    visited[y][x] = true;
                }
                else if(storage[y][x] == target)
                {
                    output.push_back({y,x});
                    visited[y][x] = true;
                }
            }
        }
    }
    while(!reservation.empty())
    {
        pair<int, int> cur = reservation.front();
        reservation.pop();
        
        for(int dir = 0; dir<4; dir++)
        {
            int nextY = cur.first + dy[dir];
            int nextX = cur.second + dx[dir];
            if(nextX < 0 || nextX > width - 1 || nextY < 0 || nextY > height - 1)
                continue;      
            if(visited[nextY][nextX])
                continue;
            if(storage[nextY][nextX] != '-')
            {
                if(storage[nextY][nextX] == target)
                {
                    visited[nextY][nextX] = true;                
                    output.push_back({nextY, nextX});
                }
                continue;
            }

            visited[nextY][nextX] = true;
            reservation.push({nextY, nextX});
        }
    }
    
    return output;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int height = storage.size();
    int width = storage[0].size();
    
    for(auto& request: requests)
    {
        char target = request[0];
        
        if(request.size() == 2)
        {
            for(int y = 0; y<storage.size(); y++)
                for(int x = 0; x<storage[y].size(); x++)
                    if(storage[y][x] == target)
                        storage[y][x] = '-';
        }
        else
        {
            vector<pair<int, int>> sub = bfs(storage, target);
            for(pair<int, int> item: sub)
                storage[item.first][item.second] = '-';
        }

    }
    
    for(int y = 0; y<storage.size(); y++)
    {
        for(int x = 0; x<storage[y].size(); x++)
        {
            if(storage[y][x] != '-')
                answer++;
        }
    }
    
    return answer;
}