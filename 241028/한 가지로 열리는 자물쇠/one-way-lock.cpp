#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if ((abs(v[0] - i) <= 2) || (abs(v[1] - j) <= 2) || (abs(v[2] - k) <= 2)) {
					count++;
				}
			}
		}
	}

	cout << count << "\n";
}