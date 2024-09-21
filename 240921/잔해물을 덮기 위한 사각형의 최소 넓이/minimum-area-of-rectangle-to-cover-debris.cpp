#include <iostream>
#include <vector>
using namespace std;

#define OFFSET 1000

int main() {
	vector<int> x1(2); vector<int> y1(2);
	vector<int> x2(2); vector<int> y2(2);

	vector<vector<int>> arr(2001, vector<int>(2001, 0));

	for (int i = 0; i < 2; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

		x1[i] += OFFSET; y1[i] += OFFSET;
		x2[i] += OFFSET; y2[i] += OFFSET;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = x1[i]; j < x2[i]; j++) {
			for (int k = y1[i]; k < y2[i]; k++) {
				arr[j][k] = i + 1;
			}
		}
	}

	int xMin = 10000; int xMax = 0;
	int yMin = 10000; int yMax = 0;

	bool flag = false;
	for (int i = x1[0]; i <= x2[0]; i++) {
		for (int j = y1[0]; j <= y2[0]; j++) {
			if (arr[i][j] == 1) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}

	if (!flag) {
		cout << 0;
		return 0;
	}

	for (int i = x1[0]; i <= x2[0]; i++) {
		for (int j = y1[0]; j <= y2[0]; j++) {
			if (arr[i][j] == 1) {
				if (i < xMin) {
					xMin = i;
				}
				if (i > xMax) {
					xMax = i;
				}
				if (j > yMax) {
					yMax = j;
				}
				if (j < yMin) {
					yMin = j;
				}
			}
		}
	}

	cout << ((xMax - xMin) + 1) * ((yMax - yMin) + 1);


}


/*
x가 최소, y가 최대
*/