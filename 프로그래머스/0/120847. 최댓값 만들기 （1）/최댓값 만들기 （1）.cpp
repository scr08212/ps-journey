#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    int n1 = 0;
    int n2 = 0;
    
    for(int num : numbers)
    {
        if(n1 <= num)
        {
            n2 = n1;
            n1 = num;
        }
        else if(n2 < num)
        {
            n2 = num;
        }
    }
    answer = n1 * n2;
    return answer;
}