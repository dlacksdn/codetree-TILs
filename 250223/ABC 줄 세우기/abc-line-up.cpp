#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<char> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int count = 0;
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
				count++;
			}
		}
	}

	cout << count;
}