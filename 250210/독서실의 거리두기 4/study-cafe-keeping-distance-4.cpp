#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	int result = 0;
	for (int i = 0; i < str.size(); i++) { // i : str을 순회하는 인덱스
		if (str[i] == '1') continue;

		for (int j = i + 1; j < str.size(); j++) { // j : str을 순회하는 인덱스
			string s = str;
			s[i] = '1';
			if (str[j] == '0') {
				s[j] = '1';

				int last = 0;
				int count = 0;
				vector<int> v(n);

				for (int k = 0; k < str.size(); k++) {
					if (s[k] == '1') {
						v[count++] = k;
					}
				}

				int distance = 101;
				for (int k = 1; k < count; k++) {
					int num = v[k] - v[k - 1];
					distance = min(distance, num);
				}

				result = max(result, distance);
			}
		}
	}

	cout << result;
}