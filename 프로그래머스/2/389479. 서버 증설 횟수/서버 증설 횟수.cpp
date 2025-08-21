#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int n = 0;
    vector<int> exp_end_time(25,0);
    for(int i = 0; i<24; i++)
    {
        n -= exp_end_time[i];
        
        int player = players[i];
        int need = player / m;
        if(need > n)
        {
            int expansion = need - n;
            answer+=expansion;
            exp_end_time[min(24, i+k)] += expansion;
            n = need;
        }
    }
    return answer;
}