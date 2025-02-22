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
		int num1 = v[i];
		int num2 = v[i + 1];

		if (num1 > num2) {
			swap(v[i], v[i + 1]);
			i = -1;
			count++;
		}
	}

	for (char c : v) {
		cout << c << " ";
	}

	cout << count;
}
