#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> score;
    score['R'] = score['T'] = score['C'] = score['F'] = score['J'] = score['M'] = score['A'] = score['N'] = 0;
    
    int size = survey.size();
    for(int i = 0; i<size; i++)
    {
        char negative = survey[i][0];
        char positive = survey[i][1];
        int choice = choices[i] - 4;
        
        if(choice < 0)
            score[negative] += abs(choice);
        else if(choice > 0)
            score[positive] += abs(choice);
    }
    
    answer += score['R'] >= score['T'] ? "R" : "T";
    answer += score['C'] >= score['F'] ? "C" : "F";
    answer += score['J'] >= score['M'] ? "J" : "M";
    answer += score['A'] >= score['N'] ? "A" : "N";
    
    return answer;
}