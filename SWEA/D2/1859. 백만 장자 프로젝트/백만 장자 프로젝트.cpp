#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long solve(vector<int> prices)
{
    int n = prices.size();
    int max_price = prices[n-1];
    long long profit = 0;
    
    for(int i = n-2; i>=0; i--)
    {
        int price = prices[i];
        if(price > max_price)
        {
            max_price = price;
            continue;
        }
        if(price < max_price)
            profit += max_price - price;
    }
    
    return profit;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        vector<int> prices;
        while(n--)
        {
            int k;
            cin >> k;
            prices.push_back(k);
        }
        cout << "#"<<test_case<<" "<<solve(prices)<<"\n";
	}
	return 0;
}