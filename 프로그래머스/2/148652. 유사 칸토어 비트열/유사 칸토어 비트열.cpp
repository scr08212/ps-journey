#include <string>
#include <cmath>
#include <vector>

using namespace std;

long long count_ones(int n, long long l, long long r, long long start, long long end)
{
    if(n == 0)
        return 1;
    
    long long len = end - start + 1;
    long long part = len/5;
    long long result = 0;
    for(int i = 0; i<5; i++)
    {
        long long s = start + part * i;
        long long e = s + part - 1;
        
        if(i == 2)
            continue;
        if(e < l || s > r)
            continue;
        
        result += count_ones(n - 1, l, r, s, e);
    }
    return result;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    answer = count_ones(n, l, r, 1, pow(5, n));
    
    return answer;
}