#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define WHITE 1
#define BLACK 2
#define GRAY 3

int main() {
	int n;
	cin >> n;

	map<int, int> m; // <인덱스, 지나간 횟수>
	map<int, int> color; // <인덱스, 색깔>
	vector<pair<int, char>> v(n); // 이동 거리, 방향

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].first; j++) {
			if (v[i].second == 'R') { // 검은색으로
				if (color[index] != GRAY) {
					m[index]++;
					color[index] = BLACK;

					if (m[index] >= 4) {
						color[index] = GRAY;
					}
					index++;
				}
				else {
					index++;
				}
			}
			else if (v[i].second == 'L') { // 흰색으로
				if (color[index] != GRAY) {
					m[index]++;
					color[index] = WHITE;

					if (m[index] >= 4) {
						color[index] = GRAY;
					}
					index--;
				}
				else {
					index--;
				}
			}
		}

		if (v[i].second == 'R') { // 검은색으로
			index--;
		}
		else if (v[i].second == 'L') { // 흰색으로
			index++;
		}
	}

	int whiteNum = 0;
	int blackNum = 0;
	int grayNum = 0;
	for (const auto& pair : color) {
		if (pair.second == WHITE) {
			whiteNum++;
		}
		else if (pair.second == BLACK) {
			blackNum++;
		}
		else if (pair.second == GRAY) {
			grayNum++;
		}
	}

	cout << whiteNum << " " << blackNum << " " << grayNum << "\n";

}