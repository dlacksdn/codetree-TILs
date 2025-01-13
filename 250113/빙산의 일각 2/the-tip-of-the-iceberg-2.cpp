#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> height(N);
	vector<bool> is_sink(N + 1);
	is_sink[N] = false;

	for (auto& p : height) cin >> p;

	int max_height = *max_element(height.begin(), height.end());

	int result = 1;
	for (int i = 1; i < max_height; i++) { // i는 해수면
		int count = 0;

		for (int j = 0; j < N; j++) {
			if (height[j] <= i) {
				is_sink[j] = false;
			}
			else is_sink[j] = true;
		}

		bool flag = true;

		for (int j = 0; j <= N; j++) {
			if (flag == true && is_sink[j] == true) {
				flag = false;
			}
			if (flag == false && is_sink[j] == false) {
				count++;
				flag = true;
			}
		}

		result = max(result, count);
	}

	cout << result;
}