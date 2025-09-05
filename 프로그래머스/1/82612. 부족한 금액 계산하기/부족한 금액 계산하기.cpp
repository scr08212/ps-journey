#include <algorithm>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    // f(n) = price + price*2 + price*3 + ... + price * n
    //      = price * (1+2+3+...+n)
    //      = price * (n*(n+1)/2)
    // answer = max(0, f(n) - money)
    
    long long fn = (long long)price * (long long)(count * (count+1)/2);
    answer = max(0LL, fn-money);

    return answer;
}