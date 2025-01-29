#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	vector<int> v;

	int bigger, smaller;

	if (A > B) {
		bigger = A;
		smaller = B;
	}
	else {
		bigger = B;
		smaller = A;
	}

	for (int i = 0; ; i++) {
		int num = 0;

		num += bigger * i;
		if (num > C) break;

		while (num <= C) {
			num += smaller;
		}

		v.push_back(num - smaller);
	}

	auto it = max_element(v.begin(), v.end());

	cout << *it;
}