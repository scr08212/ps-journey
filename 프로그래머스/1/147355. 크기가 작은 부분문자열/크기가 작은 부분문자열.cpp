#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int window = p.size();
    
    for(int i = 0; i + window <= t.size(); i++)
    {
        string sub = t.substr(i, window);
        bool flag = true;
        for(int j = 0; j< p.size(); j++)
        {
            if(sub[j] > p[j])
            {
                flag = false;
                break;
            }
            else if(sub[j] < p[j])
                break;
        }
        if(flag)
            answer++;
    }
    
    return answer;
}