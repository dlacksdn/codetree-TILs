#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

int main() {
	string arr[3];
	int count = 0;

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	set<char> s;
	vector<pair<char, char>> v;

	for (int i = 0; i < 3; i++) { // 가로줄
		for (int j = 0; j < 3; j++) {
			s.insert(arr[i][j]);
		}

		if (s.size() == 2) {
			bool flag = true;
			for (int k = 0; k < v.size(); k++) {
				if (*next(s.begin(), 0) == v[k].first && *next(s.begin(), 1) == v[k].second) {
					flag = false;
					break;
				}
			}

			if (flag) {
				count++;
				v.push_back({ *next(s.begin(), 0), *next(s.begin(), 1) });
			}
		}

		s.clear();
	}

	for (int i = 0; i < 3; i++) { // 세로줄
		for (int j = 0; j < 3; j++) {
			s.insert(arr[j][i]);
		}

		if (s.size() == 2) {
			bool flag = true;
			for (int k = 0; k < v.size(); k++) {
				if (*next(s.begin(), 0) == v[k].first && *next(s.begin(), 1) == v[k].second) {
					flag = false;
					break;
				}
			}

			if (flag) {
				count++;

				v.push_back({ *next(s.begin(), 0), *next(s.begin(), 1) });
			}
		}

		s.clear();
	}

	
	for (int j = 0; j < 3; j++) { // 대각선1
		s.insert(arr[j][j]);
	}

	if (s.size() == 2) {
		bool flag = true;
		for (int k = 0; k < v.size(); k++) {
			if (*next(s.begin(), 0) == v[k].first && *next(s.begin(), 1) == v[k].second) {
				flag = false;
				break;
			}
		}

		if (flag) {
			count++;

			v.push_back({ *next(s.begin(), 0), *next(s.begin(), 1) });
		}
	}

	s.clear();

	for (int j = 0; j < 3; j++) { // 대각선2
		s.insert(arr[2 - j][j]);
	}

	if (s.size() == 2) {
		bool flag = true;
		for (int k = 0; k < v.size(); k++) {
			if (*next(s.begin(), 0) == v[k].first && *next(s.begin(), 1) == v[k].second) {
				flag = false;
				break;
			}
		}

		if (flag) {
			count++;

			v.push_back({ *next(s.begin(), 0), *next(s.begin(), 1) });
		}
	}

	s.clear();

	cout << count;
	
}




/*
가로 세로 대각선
중복되는 팀이 있을 수 있으니 중복도 체크해야함
*/