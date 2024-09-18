#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	while (true) {
		if (n < 2) {
			v.push_back(n);
			break;
		}

		v.push_back(n % 2);
		n /= 2;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}