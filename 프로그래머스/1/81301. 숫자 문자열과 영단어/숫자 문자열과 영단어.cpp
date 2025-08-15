#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string, string> numMap = {
        {"zero","0"},{"one","1"},{"two","2"},{"three","3"},{"four","4"},
        {"five","5"},{"six","6"},{"seven","7"},{"eight","8"},{"nine","9"}
    };
    
    string converted = "";
    for(int i = 0; i<s.size(); i++)
    {
        if('0' <= s[i] && s[i]<= '9')
        {
            converted += s[i];
            continue;
        }
        
        for(int j = 3; j<=5; j++)
        {
            string sub = s.substr(i, j);
            if(numMap.count(sub))
            {
                converted += numMap[sub];
                i+=j-1;
                break;
            }
        }
    }
    
    answer = stoi(converted);
    
    return answer;
}