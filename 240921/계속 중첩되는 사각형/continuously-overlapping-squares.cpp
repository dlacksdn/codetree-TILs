#include <iostream>
#include <vector>
using namespace std;

#define OFFSET 100

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(201, vector<int>(201, 3));
	vector<int> x1(n); vector<int> y1(n);
	vector<int> x2(n); vector<int> y2(n);

	for (int i = 0; i < n; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

		x1[i] += OFFSET; y1[i] += OFFSET;
		x2[i] += OFFSET; y2[i] += OFFSET;
	}

	int value = 0;
	for (int i = 0; i < n; i++) {
		value %= 2;
		for (int j = x1[i]; j < x2[i]; j++) {
			for (int k = y1[i]; k < y2[i]; k++) {
				arr[j][k] = value;
			}
		}
		value++;
	}

	int count = 0;
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			if (arr[i][j] == 1) {
				count++;
			}
		}
	}

	cout << count;
}

/*
빨간색 = 0
파란색 = 1
*/