#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int result = 100;
	for (int i = 2; i <= 100; i += 2) { // x선
		for (int j = 2; j <= 100; j += 2) { // y선
			int arr[4] = { 0, };

			for (int k = 0; k < N; k++) {
				if (i > v[k].first && j < v[k].second) {
					arr[0]++;
				}
				else if (i < v[k].first && j < v[k].second) {
					arr[1]++;
				}
				else if (i < v[k].first && j > v[k].second) {
					arr[2]++;
				}
				else if (i > v[k].first && j > v[k].second) {
					arr[3]++;
				}
			}

			auto it = max_element(arr, arr + 4);
			result = min(result, *it);
		}
	}

	cout << result;
}