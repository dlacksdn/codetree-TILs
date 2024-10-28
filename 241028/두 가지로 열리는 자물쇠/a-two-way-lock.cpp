#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_diff(int a, int b, int N) {
	int num1 = abs(a - b);
	a > b ? b += N : a += N;

	int num2 = abs(a - b);

	return min(num1, num2);
}

int main() {
	int N;
	cin >> N;

	vector<int> first(3, 0);
	vector<int> second(3, 0);

	for (int i = 0; i < 3; i++) {
		cin >> first[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> second[i];
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (find_diff(i, first[0], N) <= 2 && find_diff(j, first[1], N) <= 2 &&
					find_diff(k, first[2], N) <= 2) {
					result++;
				}
				else if (find_diff(i, second[0], N) <= 2 && find_diff(j, second[1], N) <= 2 &&
					find_diff(k, second[2], N) <= 2) {
					result++;
				}


			}
		}
	}

	cout << result << "\n";
}

/*
N = 9일 때 해당 문제의 자물쇠는 원형이므로 1과 9는 붙어 있다고 간주한다.
2, 4일 때 abs(2 - 4)
1, 9일 때 (1 + 9) - 9 = 1 / 9 - 1 = 8
1, 8일 때 (1 + 9) - 8 = 2 / 8 - 1 = 7
3, 9일 때 (3 + 9) - 9 = 3 / 9 - 3 = 6

6, 7일 때 (6 + 9) - 7 = 8 / 7 - 6 = 1

min(한 바퀴 돌렸을 때 , 그냥 직선상에서의 거리 )

*/