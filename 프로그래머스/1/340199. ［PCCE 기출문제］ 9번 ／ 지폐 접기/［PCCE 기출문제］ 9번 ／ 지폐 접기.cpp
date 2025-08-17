#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(true)
    {
        if(*max_element(wallet.begin(), wallet.end()) >= *max_element(bill.begin(), bill.end())
          && *min_element(wallet.begin(), wallet.end()) >= *min_element(bill.begin(), bill.end()))
           break;
        
        if(bill[0] > bill[1])
            bill[0]/=2;
        else
            bill[1]/=2;
        
        answer++;
    }
    return answer;
}