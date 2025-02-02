#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 1; ; i++) { // i : 결과 값 후보
		int num = i;
		bool flag = true;

		for (int j = 0; j < N; j++) { // 곱하기 2를 몇 번 하느냐
			num *= 2;

			if (!(v[j].first <= num && num <= v[j].second)) {
				flag = false;
				break;
			}
		}
		
		if (flag) {
			cout << i;
			return 0;
		}
	}
}