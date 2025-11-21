#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bf(const vector<pair<int, int>>& ingredients, int idx, int max_cal, int cur_cal, int score)
{
    if (idx == ingredients.size()) {
        return score;
    }
    int score_without_item = bf(ingredients, idx + 1, max_cal, cur_cal, score);
    int score_with_item = 0;
    
    int next_cal = cur_cal + ingredients[idx].second;
    int item_score = ingredients[idx].first;
    
    if (next_cal <= max_cal) {
        score_with_item = bf(ingredients, idx + 1, max_cal, next_cal, score + item_score);
    } 
    return max(score_without_item, score_with_item);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 0/1 배낭 or 브루트포스
        // N=20이면 브루트포스도 될듯
        
        // Declare variables
        int n, max_cal;
        vector<pair<int, int>> ingredients;
        
        // Get input
        cin >> n >> max_cal;
        for(int i = 0; i<n; i++)
        {
            int score, cal;
            cin >> score >> cal;
            ingredients.push_back({score, cal});
        }
        
        // Solve
        int answer = 0;
        
        answer = bf(ingredients, 0, max_cal, 0, 0);
        
        // Print
        cout << "#" << test_case << " " << answer <<"\n"; 
	}
	return 0;
}