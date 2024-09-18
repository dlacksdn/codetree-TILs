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

	map<int, int> color; // <인덱스, 현재 색깔>
	map<int, int> white; // <인덱스, 흰색 count>
	map<int, int> black; // <인덱스, 검은색 count>
	vector<pair<int, char>> v(n); // 이동 거리, 방향

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].first; j++) {
			if (v[i].second == 'R') { // 검은색으로
				if (color[index] != GRAY) { // gray가 아니라면
					color[index] = BLACK;
					black[index]++;

					if (white[index] >= 2 && black[index] >= 2) {
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
					color[index] = WHITE;
					white[index]++;

					if (white[index] >= 2 && black[index] >= 2) {
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