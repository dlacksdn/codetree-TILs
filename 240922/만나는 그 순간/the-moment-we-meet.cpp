#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<char, int>> A(N); // <방향, 거리>
	vector<pair<char, int>> B(M);
	vector<int> A_Location;
	vector<int> B_Location;
	A_Location.push_back(0);
	B_Location.push_back(0);

	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}

	for (int i = 0; i < M; i++) {
		cin >> B[i].first >> B[i].second;
	}

	int A_index = 0;
	for (int i = 0; i < N; i++) {
		if (A[i].first == 'L') {
			for (int j = 0; j < A[i].second; j++) {
				A_Location.push_back(--A_index);
			}
		}
		else if (A[i].first == 'R') {
			for (int j = 0; j < A[i].second; j++) {
				A_Location.push_back(++A_index);
			}
		}
	}

	int B_index = 0;
	for (int i = 0; i < M; i++) {
		if (B[i].first == 'L') {
			for (int j = 0; j < B[i].second; j++) {
				B_Location.push_back(--B_index);
			}
		}
		else if (B[i].first == 'R') {
			for (int j = 0; j < B[i].second; j++) {
				B_Location.push_back(++B_index);
			}
		}
	}

	bool flag = true;
	for (int i = 1; i < A_Location.size(); i++) {
		if (A_Location[i] == B_Location[i]) {
			cout << i;
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << -1;
	}
}

/*
그 순간의 인덱스를 저장하라는 뜻이었구나
*/