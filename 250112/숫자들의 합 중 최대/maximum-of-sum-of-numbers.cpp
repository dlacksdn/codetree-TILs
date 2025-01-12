#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int result = 0;
	for (int i = a; i <= b; i++) {
		int target = i;
		int sum = 0;
		while (target != 0) {
			sum += target % 10;
			target /= 10;
		}

		result = max(result, sum);
	}
	
	cout << result;
}