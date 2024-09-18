#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		int n = str[i] - '0';
		num = num * 2 + n;
	}
	cout << num;

}