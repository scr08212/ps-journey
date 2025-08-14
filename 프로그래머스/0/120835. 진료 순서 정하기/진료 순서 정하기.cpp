#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> sorted(emergency);
    map<int, int> m;
    
    sort(sorted.begin(), sorted.end(), greater<int>());
    
    for(int i = 0; i<sorted.size(); i++)
    {
        m[sorted[i]] = i+1;
    }
    
    for(int item: emergency)
    {
        answer.push_back(m[item]);
    }
    
    return answer;
}