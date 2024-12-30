#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int num1 = (v[i].first * v[j].second) + (v[j].first * v[k].second) + (v[k].first * v[i].second);
				int num2 = (v[j].first * v[i].second) + (v[k].first * v[j].second) + (v[i].first * v[k].second);

				result = max(result, num1 - num2);
			}
		}
	}

	cout << result << "\n";
}