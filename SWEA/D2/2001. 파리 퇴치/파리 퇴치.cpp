#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << " ";
        // INPUT
        int n, m;
        cin >> n >> m;
        vector<vector<int>> area(n, vector<int>(n, 0));
        for(int y = 0; y<n; y++)
            for(int x = 0; x<n; x++)
                cin >> area[y][x];
        
        // BEGIN
        
        int max_area = 0;
        for(int y = 0; y<=n - m; y++)
        {
            for(int x = 0; x<=n - m; x++)
            {
                // get area
                int sum = 0;
                for(int i = y; i<y+m; i++)
                    for(int j = x; j<x+m; j++)
                        sum += area[i][j];
                
                // refresh max_area
                
                max_area = max(max_area, sum);
            }
        }
        cout << max_area << "\n";
        // END
    }
	return 0;
}