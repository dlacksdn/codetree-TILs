#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	int x_arr[11] = { 0, };
	int y_arr[11] = { 0, };

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		x_arr[x]++;
		y_arr[y]++;
	}

	vector<int> v;

	for (int i = 0; i < 11; i++) {
		v.push_back(x_arr[i]);
	}
	for (int i = 0; i < 11; i++) {
		v.push_back(y_arr[i]);
	}

	bool flag = false;
	for (int i = 0; i < 22; i++) {
		for (int j = i + 1; j < 22; j++) {
			for (int k = j + 1; k < 22; k++) {
				int value = v[i] + v[j] + v[k];

				if (value >= N) {
					cout << 1;
					return 0;
				}
			}
		}
	}

	cout << 0;
}