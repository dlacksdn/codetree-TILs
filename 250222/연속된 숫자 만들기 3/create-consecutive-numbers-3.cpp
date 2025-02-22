#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(3);

	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}

	int count = 0;
	while (true) {
		if (v[1] == v[0] + 1 && v[1] == v[2] - 1) { // 연속이다
			break;
		}

		int left = v[1] - v[0];
		int right = v[2] - v[1];

		if (left <= right) { //  왼쪽이 차이가 더 작다 -> 왼쪽 값이 이동
			v[0] = v[1];
			v[1] = v[0] + 1;
			count++;
		}
		else {
			v[2] = v[1];
			v[1] = v[2] - 1;
			count++;
		}
	}

	cout << count;
}