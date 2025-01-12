#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	vector<int> v;

	int count = 0;
	for (int i = a; i <= b; i++) {
		int arr[10] = { 0, };
		int num = i;
		int total_num = 0;

		while (num != 0) {
			arr[num % 10]++;
			total_num++;
			num /= 10;
		}

		bool flag = false;
		for (int j = 0; j <= 9; j++) {
			if (arr[j] == total_num - 1) {
				flag = true;
				break;
			}
		}

		if (flag) {
			count++;
			v.push_back(i);
		}
	}

	cout << count;
}