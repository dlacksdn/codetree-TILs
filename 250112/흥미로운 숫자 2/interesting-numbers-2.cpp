#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int count = 0;
	for (int i = a; i <= b; i++) {
		string str = to_string(i);

		if (str[0] == str[str.size() - 1]) {
			int c = 0;
			for (int j = 0; j < str.size(); j++) {
				if (str[0] != str[j]) c++;
			}
			if (c == 1) count++;
		}
		else if (str[0] == str[1]) {
			int c = 0;
			for (int j = 0; j < str.size(); j++) {
				if (str[0] != str[j]) c++;
			}
			if (c == 1) count++;

		}
		else if (str[1] == str[str.size() - 1]) {
			int c = 0;
			for (int j = 0; j < str.size(); j++) {
				if (str[1] != str[j]) c++;
			}
			if (c == 1) count++;
		}
	}

	cout << count;
}

/*

if(첫 번째 == 마지막)
	-> 숫자 쭉 돌면서 첫 번째랑 다른게 하나 있으면 count
else if(첫 번째 == 두 번째)
	-> 숫자 쭉 돌면서 첫 번째랑 다른게 하나 있으면 count
else if(두 번째 == 마지막)
	-> 숫자 쭉 돌면서 두 번째랑 다른게 하나 있으면 count

-> 세 개 다 아니면 될 수가 없음
*/