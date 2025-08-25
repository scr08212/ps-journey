#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int cur_health = health;
    int cur_t = 1;
    int skill_t = bandage[0];
    int heal_per_t = bandage[1];
    int extra_heal = bandage[2];
    
    int streak = 0;
    for(auto& attack: attacks)
    {
        int attack_t = attack[0];
        int dmg = attack[1];
        
        while(cur_t < attack_t)
        {
            int heal_amount = heal_per_t;
            streak++;
            if(streak == skill_t)
            {
                heal_amount += extra_heal;
                streak = 0;
            }
            
            cur_health = min(health, cur_health+heal_amount);
            cur_t++;
            cout <<endl;
        }
        
        cur_health -= dmg;
        if(cur_health <= 0)
            return -1;
        cur_t = attack_t + 1;
        streak = 0;
        cout <<endl;
    }
    
    answer = cur_health;
    
    return answer;
}