#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> x(N);
	vector<int> y(N);
	vector<int> result;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N; i++) { // 어떤 인덱스를 제외시킬것인가
		int maxX = 0;
		int minX = 40000;
		int maxY = 0;
		int minY = 40000;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (x[j] > maxX) {
				maxX = x[j];
			}
			if (x[j] < minX) {
				minX = x[j];
			}
			if (y[j] > maxY) {
				maxY = y[j];
			}
			if (y[j] < minY) {
				minY = y[j];
			}
		}

		int num = (maxX - minX) * (maxY - minY);
		result.push_back(num);
	}

	auto it = min_element(result.begin(), result.end());
	cout << *it << "\n";
}