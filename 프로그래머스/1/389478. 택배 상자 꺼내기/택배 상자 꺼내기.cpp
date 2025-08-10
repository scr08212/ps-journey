#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) 
{
    int row = (num - 1) / w;
    int col = (num - 1) % w;
    if (row % 2 != 0) 
        col = w - 1 - col;

    int max_row = (n - 1) / w;
    int answer = 1;

    for (int r = row + 1; r <= max_row; r++) 
    {
        int idx;
        if (r % 2 == 0) 
        {
            idx = r * w + col + 1;
        } 
        else 
        {
            idx = r * w + (w - 1 - col) + 1;
        }
        if (idx <= n) 
            answer++;
    }

    return answer;
}