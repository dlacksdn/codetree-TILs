#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int find_diff(int i, int j, int k, vector<int> v) {
	int team1 = v[i] + v[j] + v[k];
	int team2 = 0;
	for (int a = 0; a < 6; a++) {
		team2 += v[a];
	}

	team2 -= team1;

	return abs(team2 - team1);
}

int main() {
	vector<int> v(6, 0);
	for (int i = 0; i < 6; i++) {
		cin >> v[i];
	}

	int result = INT_MAX;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			for (int k = j + 1; k < 6; k++) {
				int diff = find_diff(i, j, k, v);
				result = min(result, diff);
			}
		}
	}

	cout << result << "\n";
}