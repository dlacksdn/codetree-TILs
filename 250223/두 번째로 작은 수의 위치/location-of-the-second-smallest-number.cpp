#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iterator>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector<int> target = v;

	sort(target.begin(), target.end());

	unordered_set<int> s(target.begin(), target.end());

	// set으로 바꿔봤는데 size가 1 -> -1

	if (s.size() == 1) {
		cout << -1;
	}
	else {
		int second_min = *next(s.begin(), 1);
		auto it = find(target.begin(), target.end(), second_min); // 두 번째 최솟값이 처음 나오는 반복자

		int result = distance(v.begin(), find(v.begin(), v.end(), second_min));
		int index = distance(target.begin(), it); // 두 번째 최솟값이 처음 나오는 인덱스

		if (it == target.end() - 1) { // 나오는게 마지막 인덱스 -> 하나라서 위치 출력
			cout << result + 1;
		}
		else if (*(it + 1) == *it) { // 여러 개 있음 -> -1
			cout << -1;
		}
		else {
			cout << result + 1;
		}
	}
}