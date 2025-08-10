#include <string>
#include <vector>

using namespace std;

int to_minute(int time)
{
    int h = time/100;
    int m = time%100;
    return h * 60 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int j = 0; j < schedules.size(); j++)
    {
        bool is_late = false;
        
        int schedule = schedules[j];
        int schedule_minute = to_minute(schedule);
        for(int i = 0; i<7; i++)
        {
            int day = (startday - 1 + i) % 7;
            if(day >= 5)
                continue;
        
            int time = timelogs[j][i];
            if(to_minute(time) > schedule_minute + 10)
            {
                is_late = true;
                break;
            }
        }
        if(!is_late)
            answer ++;
    }

    return answer;
}