#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool process(pair<int, char> left, pair<int, char> right) {
	return left.first < right.first;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, char>> v;

	for (int i = 0; i < N; i++) {
		int loc; char c;
		cin >> loc >> c;

		v.push_back({ loc, c });
	}

	sort(v.begin(), v.end(), process);
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {

			int gCount = 0, hCount = 0;
			for (int k = i; k <= j; k++) {
				// 범위 안에 G랑 H가 몇개 있는지 일단 세기
				v[k].second == 'G' ? gCount++ : hCount++;
			}

			if ((gCount == 0 || hCount == 0) || gCount == hCount) {
				int dis = v[j].first - v[i].first;
				result = max(result, dis);
			}
		}
	}
	cout << result << "\n";
}

/*
전략
사진 최대 크기 구하는거니까 가장 큰 것부터 시작
만족하는 거 걸리면 그게 제일 큰 거니까 종료

G랑 H를 세서 한 쪽이 0이거나 같으면 오케이
*/