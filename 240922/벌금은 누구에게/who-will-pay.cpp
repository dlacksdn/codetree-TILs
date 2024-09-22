#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> count(N + 1, 0);

	
	int result = -1;
	int num = 0;
	for (int i = 0; i < M; i++) {
		cin >> num;
		count[num]++;
		if (count[num] >= K) {
			result = num;
			break;
		}
	}

	cout << result;
}