#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v.push_back({ x, y });
	}

	int result = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int xLo = abs(v[j].first - v[i].first);
			int yLo = abs(v[j].second - v[i].second);

			int dis = pow(xLo, 2) + pow(yLo, 2);

			result = min(result, dis);
		}
	}

	cout << result << "\n";
}