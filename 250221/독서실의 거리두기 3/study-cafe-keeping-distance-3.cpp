#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	string str;
	cin >> str;

	vector<int> index; // str에서 요소가 1인 인덱스
	for (int i = 0; i < N; i++) { // i : str을 순회하는 인덱스
		if (str[i] == '1') {
			index.push_back(i);
		}
	}

	int start_index, end_index;
	int max_distance = 0;
	for (int i = 0; i < index.size() - 1; i++) {
		int dis = index[i + 1] - index[i];

		if (dis > max_distance) {
			max_distance = dis;
			start_index = index[i];
			end_index = index[i + 1];
		}
	}

	int target_index = (start_index + end_index) / 2;

	str[target_index] = '1';
	index.clear();

	for (int i = 0; i < N; i++) { // i : str을 순회하는 인덱스
		if (str[i] == '1') {
			index.push_back(i);
		}
	}

	int min_distance = 1001;
	for (int i = 0; i < index.size() - 1; i++) {
		int dis = index[i + 1] - index[i];

		if (dis < min_distance) {
			min_distance = dis;
		}
	}

	cout << min_distance;
}