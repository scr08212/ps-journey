#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> userInfo; // id - 닉네임
    vector<pair<string, string>> logs; // 행동 - id 
    // Enter: 0, Leave: 1
    
    for(string item:record)
    {
        stringstream ss(item);
        string action, uid, nickname;
        ss >> action >> uid >> nickname;
        
        if(action == "Enter")
        {
            logs.push_back({action, uid});
            userInfo[uid] = nickname;
        }
        else if(action == "Leave")
        {
            logs.push_back({action, uid});
        }
        else
            userInfo[uid] = nickname;
    }
    
    for(auto log: logs)
    {
        string str = userInfo[log.second] + "님이 ";
        if(log.first == "Enter")
            str += "들어왔습니다.";
        else if(log.first == "Leave")
            str += "나갔습니다.";
        
        answer.push_back(str);
    }
    
    return answer;
}