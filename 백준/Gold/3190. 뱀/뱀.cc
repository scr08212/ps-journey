#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// board states
constexpr auto TOP = 0;
constexpr auto RIGHT = 1;
constexpr auto BOTTOM = 2;
constexpr auto LEFT = 3;
constexpr auto BLANK = 4;
constexpr auto WALL = 5;
constexpr auto APPLE = 6;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> board(N+2, vector<int>(N+2, BLANK));
    for (int i = 0; i < N+2; i++)
    {
        board[i][0] = board[0][i] = board[N + 1][i] = board[i][N + 1] = WALL;
    }

    for (int i = 0; i < K; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = APPLE;
    }

    int L;
    vector<char> commands(20000, 'N');
    
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int t;
        char cmd;
        cin >> t >> cmd;
        commands[t] = cmd;
    }

    int dx[4]{ 0, 1, 0, -1 }; // TOP RIGHT BOTTOM LEFT
    int dy[4]{ -1, 0, 1, 0 };
    int t = 0;
    pair<int, int> tailPos = { 1, 1 };
    pair<int, int> headPos = { 1, 1 };

    int headDir = RIGHT;
    while (true)
    {
        t++;
        // 1.  뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        board[headPos.first][headPos.second] = headDir;
        headPos = { headPos.first + dy[headDir], headPos.second + dx[headDir] };

        // 2. 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
        int headPosState = board[headPos.first][headPos.second];
        if (headPosState != BLANK && headPosState != APPLE)
            break;

        // 3. 만약 이동한 칸에 사과가 있다면, 
        // 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        else if (headPosState == APPLE)
        {
            board[headPos.first][headPos.second] = BLANK;
        }
        // 4. 만약 이동한 칸에 사과가 없다면, 
        // 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        else if (headPosState == BLANK)
        {
            int tailState = board[tailPos.first][tailPos.second];
            pair<int, int> nextTailPos = { tailPos.first + dy[tailState], tailPos.second + dx[tailState] };
            board[tailPos.first][tailPos.second] = BLANK;
            tailPos = nextTailPos;
        }

        char cmd = commands[t];
        if (cmd == 'L')
            headDir = (headDir + 3) % 4;
        else if (cmd == 'D')
            headDir = (headDir + 1) % 4;
    }

    cout << t;
}