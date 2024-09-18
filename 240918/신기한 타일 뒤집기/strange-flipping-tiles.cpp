#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define WHITE 0
#define BLACK 1

int main() {
	int n;
	cin >> n;

	vector<pair<int, char>> v(n); // <이동 거리, 방향>
	map<int, int> m; // <인덱스, 현재 색깔>
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].first; j++) {
			if (v[i].second == 'R') { // 검은색으로
				m[index++] = BLACK;
				
			}
			else if (v[i].second == 'L') { // 흰색으로
				m[index--] = WHITE;
			}
		}

		if (v[i].second == 'R') { 
			index--;
		}
		else if (v[i].second == 'L') { 
			index++;
		}
	}

	int blackCount = 0;
	int whiteCount = 0;
	for (const auto& pair : m) {
		if (pair.second == BLACK) {
			blackCount++;
		}
		else if (pair.second == WHITE) {
			whiteCount++;
		}
	}

	cout << whiteCount << " " << blackCount << "\n";
}