#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int process(int sum1, int sum2, vector<int> v) {
	int sum3 = 0;
	for (int i = 0; i < 5; i++) {
		sum3 += v[i];
	}
	sum3 = sum3 - (sum1 + sum2);

	if (sum1 == sum2 || sum1 == sum3 || sum2 == sum3) {
		return 999;
	}
	
	int maxNum = max(max(sum1, sum2), sum3);
	int minNum = min(min(sum1, sum2), sum3);

	return maxNum - minNum;
}

int main() {
	vector<int> v(5, 0);
	vector<int> answer;
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (j == i) continue;
			for (int k = j + 1; k < 5; k++) {
				if (k == i) continue;
				int sum2 = v[j] + v[k];
				int result = process(v[i], sum2, v);
				answer.push_back(result);
			}
		}
	}

	auto it = min_element(answer.begin(), answer.end());
	if (*it != 999) {
		cout << *it << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}