#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int grade[]{6,6,5,4,3,2,1};
    vector<bool> nums(46, false);
    for(int n:win_nums)
        nums[n] = true;
    
    int same = 0;
    int p = 0;
    for(int n: lottos)
    {
        if(nums[n])
            same++;
        if(n == 0)
            p++;
    }
    answer.push_back(grade[same+p]);
    answer.push_back(grade[same]);
    
    
    
    return answer;
}