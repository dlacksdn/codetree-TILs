#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	string str;
	cin >> str;

	vector<int> index;

	for (int i = 0; i < N; i++) {
		if (str[i] == '1') {
			index.push_back(i);
		}
	}

	vector<int> test;
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == '1') continue; // 이미 사람이 있으니 넘어가기

		test = index;
		test.push_back(i);
		sort(test.begin(), test.end());

		int min_num = 1000;
		for (int i = 0; i < test.size() - 1; i++) {
			if (test[i + 1] - test[i] < min_num) {
				min_num = test[i + 1] - test[i];
			}
		}

		result = max(result, min_num);
	}

	cout << result;
}