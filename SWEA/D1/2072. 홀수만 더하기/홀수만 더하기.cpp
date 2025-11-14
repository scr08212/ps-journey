#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int repeat = 10;
        int sum = 0;
        while(repeat--)
        {
            int n;
        	cin >> n;
        	if(n % 2 == 1)
       		    sum += n;
        }
        cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}