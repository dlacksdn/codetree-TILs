#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	vector<int> result;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int num = pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2);
			result.push_back(num);
		}
	}

	auto it = min_element(result.begin(), result.end());
	cout << *it << "\n";
}