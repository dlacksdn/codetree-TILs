#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool process(pair<int, int> left, pair<int, int> right) {
	if (left.second == right.second) {
		return left.first < right.first;
	}
	else return left.second < right.second;
}

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	vector<int> result;
	result.push_back(0);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), process);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i].second != v[j].second) continue;
			for (int k = j + 1; k < n; k++) {
				if (v[j].first != v[k].first) continue;

				int num1 = v[j].first - v[i].first;
				int num2 = v[k].second - v[j].second;
				result.push_back(num1 * num2);
			}
		}
	}

	auto it = max_element(result.begin(), result.end());
	cout << *it << "\n";
}