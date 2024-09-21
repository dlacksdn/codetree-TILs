#include <iostream>
#include <vector>
using namespace std;

#define OFFSET 100

int main() {
	int n;
	cin >> n;

	vector<vector<int>> v(201, vector<int>(201, 0));
	vector<int> x(n);
	vector<int> y(n);

	int xNum, yNum;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];

		x[i] += OFFSET;
		y[i] += OFFSET;
	}

	for (int i = 0; i < n; i++) {
		for (int j = x[i]; j < x[i] + 8; j++) {
			for (int k = y[i]; k < y[i] + 8; k++) {
				v[j][k] = 1;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < 201; i++) {
		for (int j = 0; j < 201; j++) {
			if (v[i][j] == 1) {
				count++;
			}
		}
	}

	cout << count;
}