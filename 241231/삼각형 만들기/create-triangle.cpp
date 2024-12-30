#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int process(pair<int, int> center, pair<int, int> n1, pair<int, int> n2) {
	int row = abs(center.first - n1.first);
	int col = abs(center.second - n2.second);

	return row * col;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	int result = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int value = 0;
				if (v[i].first == v[j].first) { // 첫번째랑 두번째의 x좌표가 동일한데
					if (v[i].second == v[k].second) { // 첫번째랑 세번째의 y좌표가 동일 = 첫번째가 센터
						value = process(v[i], v[k], v[j]);
					}
					else if (v[j].second == v[k].second) { // 두번째랑 세번째의 y좌표가 동일 = 두번째가 센터
						value = process(v[j], v[k], v[i]);
					}
				}

				else if (v[i].first == v[k].first) { // 첫번째랑 세번째의 x좌표가 동일한데
					if (v[i].second == v[j].second) { // 첫번째랑 두번째의 y좌표가 동일 = 첫번째가 센터
						value = process(v[i], v[j], v[k]);
					}
					else if (v[k].second == v[j].second) { // 세번째랑 두번째의 y좌표가 동일 = 세번째가 센터
						value = process(v[k], v[j], v[i]);
					}
				}

				else if (v[j].first == v[k].first) { // 두번째랑 세번째의 x좌표가 동일한데
					if (v[j].second == v[i].second) { // 두번째랑 첫번째의 y좌표가 동일 = 두번째가 센터
						value = process(v[j], v[i], v[k]);
					}
					else if (v[k].second == v[i].second) { // 세번째랑 첫번째의 y좌표가 동일 = 세번째가 센터
						value = process(v[k], v[i], v[j]);
					}
				}
				
				result = max(result, value);
			}
		}
	}

	cout << result << "\n";
}