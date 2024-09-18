#include <iostream>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		num = num * 2 + (str[i] - '0');
	}

	num *= 17;

	vector<int> v;

	while (true) {
		if (num < 2) {
			v.push_back(num);
			break;
		}

		v.push_back(num % 2);
		num /= 2;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}

//10110100101
//101000011