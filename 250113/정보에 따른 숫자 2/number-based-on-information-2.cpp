#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int T, a, b;
	cin >> T >> a >> b;

	vector<int> S_location;
	vector<int> N_location;

	for (int i = 0; i < T; i++) {
		char c;
		int n;

		cin >> c >> n;

		if (c == 'S') {
			S_location.push_back(n);
		}
		else if (c == 'N') {
			N_location.push_back(n);
		}
	}

	int count = 0;
	for (int target = a; target <= b; target++) {
		int S_near = INT_MAX;
		int N_near = INT_MAX;

		for (int i = 0; i < S_location.size(); i++) {
			int num = abs(target - S_location[i]);

			S_near = min(S_near, num);
		}

		for (int i = 0; i < N_location.size(); i++) {
			int num = abs(target - N_location[i]);

			N_near = min(N_near, num);
		}

		if (S_near <= N_near) count++;
	}

	cout << count;
}