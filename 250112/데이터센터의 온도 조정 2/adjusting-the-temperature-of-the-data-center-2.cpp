#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N; // 장비 개수
	int C, G, H; // 작업량

	cin >> N >> C >> G >> H;

	vector<pair<int, int>> v(N);
	int TaMin = 1000;
	int TbMax = 0;

	for (auto& p : v) {
		cin >> p.first >> p.second;

		if (p.first < TaMin) TaMin = p.first;
		if (p.second > TbMax) TbMax = p.second;
	}

	int result = 0;
	for (int i = TaMin - 1; i <= TbMax + 1; i++) {
		int value = 0;
		for (auto& p : v) {
			if (i < p.first) {
				value += C;
			}
			else if (p.first <= i && i <= p.second) {
				value += G;
			}
			else {
				value += H;
			}
		}

		result = max(result, value);
	}
	
	cout << result;
}