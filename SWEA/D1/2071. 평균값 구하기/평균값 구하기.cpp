#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << " ";
        // BEGIN
        int sum = 0;
        for(int i = 0; i<10;i++)
        {
            int n;
            cin >> n;
            sum += n;
        }
        sum = round(sum / 10.0);
        cout << sum << "\n";
        // END
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}