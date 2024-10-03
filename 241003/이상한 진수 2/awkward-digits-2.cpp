#include <iostream>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	int result = 0;
	for (int i = 1; i < str.size(); i++) { // 몇 번째 자리를 바꿀 것인가
		int sum = 0;
		str[i] = str[i] == '0' ? '1' : '0';
		for (int j = 0; j < str.size(); j++) {
			int num = str[j] - '0';
			sum = sum * 2 + num;
		}
		result = max(result, sum);
		str[i] = str[i] == '0' ? 1 : 0;
	}

	cout << result;
}