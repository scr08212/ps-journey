#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 백준허브 테스트
long long solution(int dist_limit, int split_limit) {
    long long answer = 1; 
    
    for (int a = 0; a <= 30; a++) {
        for (int b = 0; b <= 20; b++) {
            
            long long current_split = 1;
            bool over_limit = false;
            for(int i=0; i<a; i++) {
                current_split *= 2;
                if(current_split > split_limit) { over_limit = true; break; }
            }
            for(int i=0; i<b; i++) {
                current_split *= 3;
                if(current_split > split_limit) { over_limit = true; break; }
            }
            if(over_limit) continue;
            
            long long current_leaves = 1;
            long long remain_dist = dist_limit;
            
            for (int i = 0; i < a; i++) {
                long long place_node = min(current_leaves, remain_dist);
                
                remain_dist -= place_node;
                current_leaves += place_node * (2 - 1); 
                
                if (remain_dist == 0) break;
            }
            
            for (int i = 0; i < b; i++) {
                if (remain_dist == 0) break;
                
                long long place_node = min(current_leaves, remain_dist);
                remain_dist -= place_node;
                current_leaves += place_node * (3 - 1); 
            }
            
            answer = max(answer, current_leaves);
        }
    }
    
    return answer;
}