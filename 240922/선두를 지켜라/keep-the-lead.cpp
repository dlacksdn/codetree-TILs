#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> A(N); // <속도, 시간>
	vector<pair<int, int>> B(M);
	vector<int> A_Location;
	vector<int> B_Location;
	A_Location.push_back(0); B_Location.push_back(0);

	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}

	for (int i = 0; i < M; i++) {
		cin >> B[i].first >> B[i].second;
	}

	int A_index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < A[i].second; j++) {
			A_index += A[i].first;
			A_Location.push_back(A_index);
		}
	}

	int B_index = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < B[i].second; j++) {
			B_index += B[i].first;
			B_Location.push_back(B_index);
		}
	}

	int count = 0;
	int firstIndex = 0;
	int index = 0;
	char arr[2] = { 'A', 'B' }; // 현재 인덱스가 선두라는 뜻
	for (int i = 1; i < A_Location.size(); i++) {
		if (A_Location[i] != B_Location[i]) {
			count++;
			firstIndex = i + 1;
			if (A_Location[i] > B_Location[i]) {
				index = 0;
			}
			else {
				index = 1;
			}
			break;
		}
	}

	for (int i = firstIndex; i < A_Location.size(); i++) {
		if (arr[index] == 'A' && A_Location[i] < B_Location[i]) {
			count++;
			++index %= 2;
		}
		else if (arr[index] == 'B' && A_Location[i] > B_Location[i]) {
			count++;
			++index &= 2;
		}
	}

	cout << count;
}