#include <iostream>
#include <string>
using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;

	int count = 0;
	for (int i = X; i <= Y; i++) {
		string str = to_string(i);

		bool flag = true;
		for (int i = 0; i < (int)(str.size() / 2); i++) {
			if (str[i] != str[str.size() - i - 1]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			count++;
		}
	}

	cout << count;
}

/*
12321
size = 5

0 / size - 0 - 1
1 / size - 1 - 1
2 / size - 2 - 1

123321
size = 6

0 / size - 0 - 1
1 / size - 1 - 1
2 / size - 2 - 1

*/