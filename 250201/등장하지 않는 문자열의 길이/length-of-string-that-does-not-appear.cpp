#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	string str;
	cin >> str;

	for (int i = 2; i <= N; i++) { // i : 몇 개씩 문자들을 잡을 것인가
		bool flag = false;
		for (int j = 0; j <= N - i; j++) { // j : 시작 인덱스
			string sub = str.substr(j, i);

			
			for (int k = j + 1; k <= N - i; k++) { // k : 탐색 시작 인덱스
				string target = str.substr(k, i);
				if (sub == target) { // 여기에 걸린다는건 현재 i가 아니라는 소리
					flag = true;
					break;
				}
			}

			if (flag) {
				break;
			}
		}
		if (!flag) { // 여기에 걸린다는건 중복이 없다는 소리
			cout << i;
			return 0;
		}
	}
}