/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T; 
    cin >> T;

    for(int test_case=1; test_case<=T; test_case++)
    {
        int n;
        cin >> n;

        vector<vector<int>> snail(n, vector<int>(n, 0));

        int dx[4] = {1, 0, -1, 0}; // 오른쪽, 아래, 왼쪽, 위
        int dy[4] = {0, 1, 0, -1};

        int dir = 0;    // 방향 index
        int x = 0, y = 0;
        int num = 1;

        for(int i=0; i<n*n; i++)
        {
            snail[y][x] = num++;

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n || snail[ny][nx] != 0)
                dir = (dir + 1) % 4;

            x += dx[dir];
            y += dy[dir];
        }

        cout << "#" << test_case << "\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout << snail[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}