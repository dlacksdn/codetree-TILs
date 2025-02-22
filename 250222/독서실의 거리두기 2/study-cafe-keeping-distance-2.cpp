#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int process(string test) {
	int min_num = 1000; // 1끼리 가장 작은 거리
	for (int i = 0; i < test.size(); i++) {
		if (test[i] == '0') continue;

		for (int j = i + 1; j < test.size(); j++) {
			if (test[j] == '1') {
				if (j - i < min_num) {
					min_num = j - i;
				}
				break;
			}
		}
	}

	return min_num;
}

int main() {
	int N;
	cin >> N;

	string str;
	cin >> str;

	int result = 0;

	int max_num = 0; // 가장 큰 1끼리의 거리
	int start = 0, end = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == '0') continue;
		
		for (int j = i + 1; j < N; j++) {
			if (str[j] == '1') {
				if (j - i > max_num) {
					max_num = j - i;
					start = i;
					end = j;
				}

				break;
			}
		}
	}

	string test = str;

	if (end != 0) {
		int target_index = (start + end) / 2;
		test[target_index] = '1';
		result = process(test);
	}
	
	if (str[0] == '0') {
		test = str;
		test[0] = '1';

		int num = process(test);
		result = max(result, num);
	}
	
	if (str[N - 1] == '0') {
		test = str;
		test[N - 1] = '1';

		int num = process(test);
		result = max(result, num);
	}

	cout << result;
}