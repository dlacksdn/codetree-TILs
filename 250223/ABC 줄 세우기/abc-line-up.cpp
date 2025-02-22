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
	for (int i = 0; i < N - 1; i++) {
		if (v[i] > v[i + 1]) {
			swap(v[i], v[i + 1]);
			count++;
		}
	}

	cout << count;
}