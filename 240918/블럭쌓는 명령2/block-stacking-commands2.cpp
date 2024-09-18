#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(N + 1, 0);

	while (K--) {
		int x, y;
		cin >> x >> y;

		for (int i = x; i <= y; i++) {
			v[i]++;
		}
	}

	auto num = max_element(v.begin(), v.end());
	cout << *num;
}