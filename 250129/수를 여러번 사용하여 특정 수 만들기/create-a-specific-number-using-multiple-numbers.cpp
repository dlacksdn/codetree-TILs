#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int result = 0;
	for (int i = 0; i * A <= C; i++) {
		int num = i * A;

		int remain = (C - num) / B;

		num += remain * B;

		result = max(result, num);
	}

	cout << result;
}