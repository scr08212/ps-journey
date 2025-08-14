#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> sorted(emergency);
    
    sort(sorted.begin(), sorted.end(), greater<int>());
    
    for(int item: emergency)
    {
        answer.push_back(distance(sorted.begin(), find(sorted.begin(), sorted.end(), item) + 1));
    }
    
    return answer;
}