#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        vector<int> b;
        int n;
        cin >> n;
        for(int i = 0; i<n; i++)
        {
            int h;
        	cin >> h;
            b.push_back(h);
        }
        int result = 0;
        for(int i = 2;  i<n-2; i++)
        {
        	int h = b[i];
        	int m = max({ b[i-2], b[i-1], b[i+1], b[i+2] });
        	result += max(h - m, 0);
    	}
        cout << "#" << test_case << " "<< result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}