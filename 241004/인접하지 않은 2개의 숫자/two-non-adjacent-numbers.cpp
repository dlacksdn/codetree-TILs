#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int result = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 2; j < n; j++) {
			int sum = v[i] + v[j];
			result = max(result, sum);
		}
	}

	cout << result;
}