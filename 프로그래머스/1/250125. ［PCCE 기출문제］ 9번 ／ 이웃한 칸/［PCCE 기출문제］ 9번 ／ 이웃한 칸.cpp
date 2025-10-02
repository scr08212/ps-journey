#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int height = board.size();
    int width = board[0].size();
    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1}; // 동 서 남 북
    string color = board[h][w];
    
    for(int dir = 0; dir<4;dir++)
    {
        int nextX = w + dx[dir];
        int nextY = h + dy[dir];
        if (nextY < 0 || nextY >= height || nextX < 0 || nextX >= width)
            continue;
        if (board[nextY][nextX] != color)
            continue;
        
        answer++;
    }
    
    
    return answer;
}