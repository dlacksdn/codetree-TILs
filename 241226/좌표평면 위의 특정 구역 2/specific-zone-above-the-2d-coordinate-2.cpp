#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
		int xMin = 40000;
		int xMax = 1;
		int yMin = 40000;
		int yMax = 1;

		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}

			if (v[j].first < xMin) {
				xMin = v[j].first;
			}
			if (v[j].first > xMax) {
				xMax = v[j].first;
			}
			if (v[j].second < yMin) {
				yMin = v[j].second;
			}
			if (v[j].second > yMax) {
				yMax = v[j].second;
			}
		}

		int row = yMax - yMin;
		int col = xMax - xMin;

		result = min(result, row * col);
	}

	cout << result;
}