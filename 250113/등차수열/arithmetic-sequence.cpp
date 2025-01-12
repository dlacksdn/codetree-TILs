#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (auto& p : v) cin >> p;

	sort(v.begin(), v.end());

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((v[i] + v[j]) % 2 == 0) {
				count++;
			}
		}
	}

	cout << count;
}