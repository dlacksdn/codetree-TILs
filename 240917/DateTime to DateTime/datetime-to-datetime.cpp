#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a == 11) {
		if (b < 11 || (b == 11 && c < 11)) {
			cout << -1 << "\n";
			return 0;
		}
	}
	
	int start = 11 * (24 * 60) + 11 * 60 + 11;
	int end = a * (24 * 60) + b * 60 + c;

	cout << end - start << "\n";
}