#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> A_Location;
	vector<int> B_Location;
	A_Location.push_back(0); B_Location.push_back(0);
	int v, t;


	int A_index = 0;
	for (int i = 1; i <= N; i++) {
		cin >> v >> t;
		for (int j = 0; j < t; j++) {
			A_index += v;
			A_Location.push_back(A_index);
		}
	}

	int B_index = 0;
	for (int i = 0; i < M; i++) {
		cin >> v >> t;
		for (int j = 0; j < t; j++) {
			B_index += v;
			B_Location.push_back(B_index);
		}
	}

	int winner = 3; // A가 앞서면 0, B가 앞서면 1, 똑같으면 2
	int result = 0;
	for (int i = 1; i < A_Location.size(); i++) {
		if (A_Location[i] > B_Location[i]) {
			if (winner != 0) {
				result++;
			}
			winner = 0;
		}
		else if (A_Location[i] < B_Location[i]) {
			if (winner != 1) {
				result++;
			}
			winner = 1;
		}
		else {
			if (winner != 2) {
				result++;
			}
			winner = 2;
		}
	}
	cout << result;
}