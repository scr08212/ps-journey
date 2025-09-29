#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    unordered_map<string, int> header_idx_map = {
        {"code", 0},
        {"date", 1},
        {"maximum", 2},
        {"remain", 3}
    };
    
    for(auto item: data)
    {
        int idx = header_idx_map[ext];
        if(item[idx] < val_ext)
        {
            answer.push_back(item);
            continue;
        }
    }
    
    int idx = header_idx_map[sort_by];
    
    sort(answer.begin(), answer.end(), [&](const vector<int> a, const vector<int> b){
       return a[idx] < b[idx]; 
    });
    
    return answer;
}