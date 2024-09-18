#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;
	string n;
	cin >> a >> b >> n;

	int num = 0;
	for (int i = 0; i < n.size(); i++) {
		num = num * a + (n[i] - '0');
	}

	vector<int> v;
	while (true) {
		if (num < b) {
			v.push_back(num);
			break;
		}

		v.push_back(num % b);
		num /= b;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}