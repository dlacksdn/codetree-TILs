#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct process {
	bool operator() (const pair<int, int>& left, const pair<int, int>& right) {
		return left.first + left.second < right.first + right.second;
	}
};

int main() {
	int N, B;
	cin >> N >> B;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), process());

	int result = 0;
	for (int i = 0; i < N; i++) {
		v[i].first /= 2;
		int sum = 0;
		int count = 0;

		for (int j = 0; j < N; j++) {
			sum += v[j].first + v[j].second;
			count++;

			if (sum > B) {
				count--;
				break;
			}
		}

		result = max(result, count);
		v[i].first *= 2;
	}

	cout << result;
}