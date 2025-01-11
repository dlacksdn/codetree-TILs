#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;

	vector<vector<int>> v(K, vector<int>(N));

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			bool flag = true;

			for (int k = 0; k < K; k++) {
				int num1, num2;
				for (int l = 0; l < N; l++) {
					if (v[k][l] == i) {
						num1 = l;
					}
					if (v[k][l] == j) {
						num2 = l;
					}
				}
				if (num1 > num2) {
					flag = false;
					break;
				}
			}

			if (flag) {
				count++;
			}
		}
	}

	cout << count;
}