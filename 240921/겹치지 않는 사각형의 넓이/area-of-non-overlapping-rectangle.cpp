#include <iostream>
#include <vector>
using namespace std;

#define OFFSET 1000

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1 += OFFSET;
	y1 += OFFSET;
	x2 += OFFSET;
	y2 += OFFSET;

	vector<vector<int>> arr(2001, vector<int>(2001, 0));

	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			arr[i][j] = 1;
		}
	}

	cin >> x1 >> y1 >> x2 >> y2;
	x1 += OFFSET;
	y1 += OFFSET;
	x2 += OFFSET;
	y2 += OFFSET;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			arr[i][j] = 1;
		}
	}

	cin >> x1 >> y1 >> x2 >> y2;
	x1 += OFFSET;
	y1 += OFFSET;
	x2 += OFFSET;
	y2 += OFFSET;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			arr[i][j] = 0;
		}
	}

	int count = 0;
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			if (arr[i][j] == 1) {
				count++;
			}
		}
	}

	cout << count;
}