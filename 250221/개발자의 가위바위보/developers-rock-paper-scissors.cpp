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

	int result = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first == 1 && v[i].second == 3 ||
			v[i].first == 2 && v[i].second == 1 ||
			v[i].first == 3 && v[i].second == 2)
		{
			count++;
		}
	}

	result = count;

	count = 0;

	for (int i = 0; i < N; i++) {
		if (v[i].first == 3 && v[i].second == 1 ||
			v[i].first == 1 && v[i].second == 2 ||
			v[i].first == 2 && v[i].second == 3)
		{
			count++;
		}
	}

	result = max(result, count);

	cout << result;
}