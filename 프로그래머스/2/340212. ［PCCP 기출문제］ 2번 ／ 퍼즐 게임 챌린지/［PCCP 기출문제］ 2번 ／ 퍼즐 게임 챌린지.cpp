#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 100000;
    int level = 0;
    
    int l_level = 1;
    int r_level = *max_element(diffs.begin(), diffs.end());
    
    while(l_level <= r_level)
    {
        long long time = 0;
        level = (int)((l_level + r_level)/2);
        
        long long time_prev = 1;
        for(int i = 0; i<diffs.size(); i++)
        {
            int diff = diffs[i];
            long long time_cur = times[i];

            // logic
            if(diff > level)
            {
                int repeat = diff - level;
                time += (time_cur+time_prev) * repeat;
            }
            time += time_cur;
            time_prev = time_cur;
        }
        
        if(time <= limit)
        {
            r_level = level - 1;
            answer = min(answer, level);
        }
        else if(time > limit)
            l_level = level + 1;
    }
    
    return answer;
}