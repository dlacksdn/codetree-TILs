#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> A(N, 0);
	vector<int> B(M, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	sort(B.begin(), B.end());

	int count = 0;
	for (int i = 0; i < N - M + 1; i++) { // i : 시작 인덱스
		vector<int> temp(A.begin() + i, A.begin() + i + M); // A를 시작과 끝으로 짜른 새로운 배열
		sort(temp.begin(), temp.end());

		bool flag = true;

		for (int j = 0; j < M; j++) {
			if (B[j] != temp[j]) {
				flag = false;
				break;
			}
		}

		if (flag) count++;
	}

	cout << count << "\n";
}

/*
vector를 하나 또 만들어서 수열 B의 값이 있으면 그걸 저장하는 배열로 쓰는거지
왜냐면 요소가 같은 게 있을 수도 있으니까 인덱스가 겹치면 그냥 넘어가는거지

그냥 정렬시키면 되는것 아닌가?
*/