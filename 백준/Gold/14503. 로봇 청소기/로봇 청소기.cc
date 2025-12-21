#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int rotateCCW(int d, int n)
{
    return (4 + d - (n % 4)) % 4;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // BACKGROUND
    // 1. N x M 크기의 방
    // - 각 방은 빈 칸 or 벽
    // 2. 청소기는 바라보는 방향 존재
    // - 동, 서, 남, 북중 하나
    // 방은 (r, c)로 나타낼 수 있음.
    // (0, 0)은 좌측 상단
    // (N-1, M-1)은 우측 하단

    // LOGIC
    // 1. 현재 칸이 청소되지 않으면 청소
    // 2-1. 사방에 청소되지 않은 빈칸이 없다면 한칸 후진하고 1번으로
    // - 바라보는 방향의 뒤쪽 칸이 벽이라 후진이 불가하다면 작동 멈춤
    // 2-2. 사방에 청소되지 않은 빈칸이 있다면 반시계방향으로 90도 회전 (북->서, 서->남, 남->동, 동->북)
    // - 앞쪽칸이 청소되지 않은 빈칸이라면 전진 이후 1번으로, 아니라면 다시 회전 

    // CONSTRAINTS
    // 3 <= (N, M) <= 50
    // 최외곽은 항상 벽

    int N, M;
    int r, c, d;

    cin >> N >> M;
    cin >> r >> c >> d;
    vector<vector<int>> rooms(N, vector<int>(M, 0));

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> rooms[y][x];
        }
    }

    int dx[]{ 0, 1, 0, -1 };
    int dy[]{ -1, 0, 1, 0 };
    int answer = 0;
    while (true)
    {
        if (rooms[r][c] == 0)
        {
            // 1
            answer++;
            rooms[r][c] = 2;
        }

        int dirtyRoomsCnt = 0;
        for (int dir = 0; dir < 4; dir++) // 0:북 1:동 2:남 3:서
        {
            int nextR = r + dy[dir];
            int nextC = c + dx[dir];
            if (nextC < 0 || nextC > M || nextR < 0 || nextR > N)
                continue;
            if (rooms[nextR][nextC] != 0)
                continue;

            dirtyRoomsCnt++;
        }

        if (dirtyRoomsCnt == 0) // 2-1
        {
            int backward_d = rotateCCW(d, 2);
            int nextR = r + dy[backward_d];
            int nextC = c + dx[backward_d];
            if (rooms[nextR][nextC] != 1)
            {
                c = nextC;
                r = nextR;
                continue;
            }
            else if (rooms[nextR][nextC] == 1)
            {
                break;
            }
        }
        else if (dirtyRoomsCnt >= 1)
        {
            int nextD = d;
            for (int i = 0; i < 4; i++)
            {
                nextD = rotateCCW(nextD, 1);
                int nextR = r + dy[nextD];
                int nextC = c + dx[nextD];
                if (rooms[nextR][nextC] == 0)
                {
                    c = nextC;
                    r = nextR;
                    d = nextD;
                    break;
                }
            }
        }
    }

    cout << answer;
}