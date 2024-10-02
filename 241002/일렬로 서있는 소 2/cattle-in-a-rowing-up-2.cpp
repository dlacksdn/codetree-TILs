#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (v[i] <= v[j] && v[j] <= v[k]) {
					count++;
				}
			}
		}
	}

	cout << count;
}