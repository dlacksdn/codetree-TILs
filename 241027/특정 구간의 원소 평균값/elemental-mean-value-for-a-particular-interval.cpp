#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N + 1, 0);
	
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			double avg = 0;
			int sum = 0;

			for (int k = i; k <= j; k++) {
				sum += v[k];
			}

			avg = (double)(sum) / (j - i + 1);

			if (sum % (j - i + 1) == 0) { // 정수가 아니면 볼 필요도 없다
				auto it = find(v.begin() + i, v.begin() + j + 1, avg); // 끝 인덱스까지 보고 싶으면 +1 해야 된다.
				if (it != v.begin() + j + 1) count++;
			}
		}
	}

	cout << count << "\n";
}