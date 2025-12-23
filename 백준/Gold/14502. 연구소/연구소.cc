#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;

int dx[]{ 1, -1, 0, 0 };
int dy[]{ 0, 0, 1, -1 };

vector<pair<int, int>> virusesPos;

constexpr int BLANK = 0;
constexpr int WALL = 1;
constexpr int VIRUS = 2;

vector<vector<int>> bfs(vector<vector<int>> board)
{
    queue<pair<int, int>> res;

    for (pair<int, int> virusPos : virusesPos)
        res.push(virusPos);


    while (!res.empty())
    {
        pair<int, int> curPos = res.front();
        res.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            pair<int, int> next = { curPos.first + dx[dir], curPos.second + dy[dir] };
            if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M)
                continue;
            if (board[next.first][next.second] != BLANK)
                continue;

            board[next.first][next.second] = VIRUS;
            res.push(next);
        }
    }

    return board;
}

int getBlankSpaces(vector<vector<int>>& board)
{
    int cnt = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (board[y][x] == BLANK)
                cnt++;
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == VIRUS)
            {
                virusesPos.push_back({ y, x });
            }
        }
    }

    int answer = 0;
    for (int w1 = 0; w1 < N * M; w1++)
    {
        pair<int, int> w1Pos = { w1 / M , (w1 % M) };
        if (board[w1Pos.first][w1Pos.second] != BLANK)
            continue;

        board[w1Pos.first][w1Pos.second] = WALL;

        for (int w2 = w1 + 1; w2 < N * M; w2++)
        {
            pair<int, int> w2Pos = { w2 / M , (w2 % M) };
            if (board[w2Pos.first][w2Pos.second] != BLANK)
                continue;

            board[w2Pos.first][w2Pos.second] = WALL;
            for (int w3 = w2 + 1; w3 < N * M; w3++) 
            {
                pair<int, int> w3Pos = { w3 / M , (w3 % M) };
                if (board[w3Pos.first][w3Pos.second] != BLANK)
                    continue;

                board[w3Pos.first][w3Pos.second] = WALL;

                auto bfsBoard = bfs(board);
                int safeSpace = getBlankSpaces(bfsBoard);
                answer = max(answer, safeSpace);

                board[w3Pos.first][w3Pos.second] = BLANK;
            }
            board[w2Pos.first][w2Pos.second] = BLANK;
        }
        board[w1Pos.first][w1Pos.second] = BLANK;
    }

    cout << answer;
}