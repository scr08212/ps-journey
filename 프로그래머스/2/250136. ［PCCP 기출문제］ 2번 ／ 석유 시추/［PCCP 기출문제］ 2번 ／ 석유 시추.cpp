#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int height = land.size();
    int width = land[0].size();
    
    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, -1, 1};
    // 1. land 순회하면서 타일 매핑 및 넓이 계산(넓이는 배열에 따로 저장)
    // 2. 열 순회 및 최대 석유량 계산
    
    // -1 : 기름 없음 or 아직 방문 안함
    // 0~ : 기름 그룹 id
    vector<vector<int>> oil_group_state(height, vector<int>(width, -1));
    vector<int> oil_size_state(height * width, 0);
    int id = 0;
    
    for(int y = 0; y<height; y++)
    {
        for(int x = 0; x<width; x++)
        {
            if(land[y][x] == 0)
                continue;
            if (oil_group_state[y][x] != -1) 
                continue;
            
            int dimension = 0;
            // 순회
            queue<pair<int, int>> res;
            res.push({y, x});
            oil_group_state[y][x] = id;
            while(!res.empty())
            {
                auto cur = res.front(); 
                res.pop();
                int curY = cur.first;
                int curX = cur.second;
                dimension++;
                
                for(int dir = 0; dir<4; dir++)
                {
                    int nextY = curY + dy[dir];
                    int nextX = curX + dx[dir];
                    if(nextY < 0 || nextY >= height || nextX < 0 || nextX >= width)
                        continue;
                    if(land[nextY][nextX] == 0)
                        continue;
                    if(oil_group_state[nextY][nextX] != -1)
                        continue;
                    
                    oil_group_state[nextY][nextX] = id;
                    res.push({nextY, nextX});
                }
            }
            oil_size_state[id++] = dimension;
        }
    }
    
    for(int x = 0; x<width; x++)
    {
        int dimension = 0;
        vector<bool> calculated(oil_size_state.size(), false);
        for(int y = 0; y<height; y++)
        {
            int id = oil_group_state[y][x];
            if(id == -1)
                continue;
            if(calculated[id] == true)
                continue;
            dimension += oil_size_state[id];
            calculated[id] = true;
        }
        
        answer = max(answer, dimension);
    }
    
    return answer;
}