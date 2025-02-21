#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(3);

	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}

	if (v[0] + 1 == v[1] && v[2] - 1 == v[1]) { // 이미 완벽
		cout << 0;
	}
	else if (v[0] + 2 == v[1] || v[2] - 2 == v[1]) { // 한 번 옮기면 끝남
		cout << 1;
	}
	else
		cout << 2;
}