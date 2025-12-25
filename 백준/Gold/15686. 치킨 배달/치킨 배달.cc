#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

constexpr auto BLANK = 0;
constexpr auto HOUSE = 1;
constexpr auto CHICKEN = 2;

int N, M;
int answer = INT_MAX;
vector<pair<int, int>> houses, chickens;
vector<int> selected;

void solve(int idx, int cnt)
{
	if (cnt == M)
	{
		int sum = 0;
		for (int i = 0; i<houses.size(); i++)
		{
			auto house = houses[i];
			int distance = INT_MAX;
            for(auto idx : selected)
            {
                auto chicken = chickens[idx];
                distance = min(distance, abs(house.first - chicken.first) + abs(house.second - chicken.second));
            }
			sum += distance;
		}
		answer = min(sum, answer);
		return;
	}

	for (int i = idx; i < chickens.size(); i++)
	{
		selected.push_back(i);
		solve(i + 1, cnt + 1);
		selected.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int input;
			cin >> input;
			if (input == HOUSE)
				houses.push_back({ y, x });
			else if (input == CHICKEN)
				chickens.push_back({ y, x });
		}
	}

	solve(0, 0);

	cout << answer;
}