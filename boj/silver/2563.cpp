#include<iostream>

using namespace std;

int main()
{
    bool arr[100][100]{false};
    int area = 0;
    int n;
    cin >> n;

    while(n--)
    {
        int x_left, y_bottom;
        cin >> x_left >> y_bottom;

        int x_right = x_left + 10;
        int y_top = y_bottom + 10;

        for(int y = y_bottom; y<y_top; y++)
        {
            for(int x = x_left; x< x_right; x++)
            {
                if(!arr[y][x])
                {
                    arr[y][x] = true;
                    area++;
                }
            }
        }
    }
    cout << area;
}