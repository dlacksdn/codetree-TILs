#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	string str;
	cin >> str;
	
	vector<int> v;

	for (int i = 0; i < N; i++) {
		if (str[i] == '1') {
			v.push_back(i);
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) { // i : 새로운 사람이 들어갈 인덱스
		if (str[i] == '1') continue;
		vector<int> copy = v;

		copy.push_back(i);
		sort(copy.begin(), copy.end());

		int index_count = 21;
		for (int j = 0; j < copy.size() - 1; j++) {
			int num = copy[j + 1] - copy[j];
			index_count = min(index_count, num);
		}

		result = max(result, index_count);
	}

	cout << result;
}