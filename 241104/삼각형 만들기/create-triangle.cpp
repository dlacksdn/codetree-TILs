#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	vector<int> result;
	result.push_back(0);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {

				if (v[i].second == v[j].second) {
					if (v[i].first == v[k].first || v[j].first == v[k].first) {
						num1 = abs(v[j].first - v[i].first);
						num2 = abs(v[k].second - v[j].second);
						result.push_back(num1 * num2);
					}
				}
				else if (v[i].second == v[k].second) {
					if (v[i].first == v[j].first || v[j].first == v[k].first) {
						num1 = abs(v[k].first - v[i].first);
						num2 = abs(v[j].second - v[k].second);
						result.push_back(num1 * num2);
					}
				}
				else if (v[j].second == v[k].second) {
					if (v[i].first == v[j].first || v[i].first == v[k].first) {
						num1 = abs(v[k].first - v[j].first);
						num2 = abs(v[i].second - v[k].second);
						result.push_back(num1 * num2);
					}
				}
			}
		}
	}

	auto it = max_element(result.begin(), result.end());
	cout << *it << "\n";
}