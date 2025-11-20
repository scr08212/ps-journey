#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
    int N;
    cin >> N;
    
    for(int i = 1; i<= N; i++)
    {   
        int count = 0;
        string i_str = to_string(i);
    	for(char c : i_str)
        {
            int num = c - '0';
            if(num == 3 || num == 6 || num == 9)
            {
                cout <<"-";
				count++;
            }
        }
        if(count == 0)
            cout << i;
        cout <<" ";
    }
	return 0;
}