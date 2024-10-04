#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int result = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int num1 = v[i];
				int num2 = v[j];
				int num3 = v[k];

				while (true) {
					if ((num1 % 10 + num2 % 10 + num3 % 10) >= 10)
						break;

					num1 /= 10;
					num2 /= 10;
					num3 /= 10;

					if (num1 == 0 && num2 == 0 && num3 == 0) {
						result = max(result, v[i] + v[j] + v[k]);
						break;
					}
				}
			}
		}
	}

	cout << result;
}