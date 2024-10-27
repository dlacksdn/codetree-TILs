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
	for (int i = 0; i < N - M + 1; i++) { // 시작 인덱스에서 M개를 봐야하니 i의 범위를 저렇게 산정
		vector<int> temp(A.begin() + i, A.begin() + i + M); // B와의 비교를 위해 A를 시작인덱스에서 M개를 짜름
		sort(temp.begin(), temp.end()); // 짤라서 만든 새로운 배열을 정렬해서 B와 비교하기 용이하게 세팅

		bool flag = true;

		for (int j = 0; j < M; j++) {
			if (B[j] != temp[j]) { // 하나라도 틀리면 다음은 볼 필요도 없음
				flag = false;
				break;
			}
		}

		if (flag) count++;
	}

	cout << count << "\n";
}