#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int process(int sum3, vector<int> rest) {
	int allSum = 0;
	for (int i = 0; i < 4; i++) {
		allSum += rest[i];
	}

	int result = INT_MAX;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			sum1 = rest[i] + rest[j];
			sum2 = allSum - sum1;

			int sumMin = min(min(sum1, sum2), sum3);
			int sumMax = max(max(sum1, sum2), sum3);
			result = min(result, sumMax - sumMin);
		}
	}

	return result;
}

int main() {
	vector<int> v(6, 0);

	for (int i = 0; i < 6; i++) {
		cin >> v[i];
	}

	vector<int> rest;
	vector<int> result;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			int firstSum = v[i] + v[j];

			for (int k = 0; k < 6; k++) {
				if (k != i && k != j) {
					rest.push_back(v[k]);
				}
			}
			result.push_back(process(firstSum, rest));
			rest.clear();
		}
	}

	auto answer = min_element(result.begin(), result.end());
	cout << *answer << "\n";
}

/*
한 팀을 먼저 잡아서 fix를 시키면

두 팀이 남게 되니 똑같이 하면 된다.

그러면 fix를 시키고 남은 구성원을 빼오는 작업을 어떻게 코드로 구현할까?
*/