#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int tc;
        cin >> tc;
        vector<int> scores(101, 0);
        for(int i = 0; i<1000; i++)
        {
            int score;
            cin >> score;
            scores[100 - score]++;
        }
        
        int idx = max_element(scores.begin(), scores.end()) - scores.begin();
        
        cout << "#" << tc << " "<< 100 - idx <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}