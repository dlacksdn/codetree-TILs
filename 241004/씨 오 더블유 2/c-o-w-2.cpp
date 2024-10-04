#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	int result = 0;
	for (int i = 0; i < n - 2; i++) {
		if (str[i] != 'C')
			continue;
		for (int j = i + 1; j < n - 1; j++) {
			if (str[j] != 'O')
				continue;
			for (int k = j + 1; k < n; k++) {
				if (str[k] != 'W')
					continue;

				result++;
			}
		}
	}

	cout << result;
}