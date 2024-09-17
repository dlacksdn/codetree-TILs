#include <iostream>
using namespace std;

int main() {
	int m1, d1, m2, d2;
	cin >> m1 >> d1 >> m2 >> d2;

	string target;
	cin >> target;

	int arr[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string day[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

	int start = 0;
	for (int i = 1; i < m1; i++) {
		start += arr[i];
	}
	start += d1;

	int end = 0;
	for (int i = 1; i < m2; i++) {
		end += arr[i];
	}
	end += d2;

	int num = 0;
	for (int i = 0; i < 7; i++) {
		if (day[i] == target) {
			num = i;
			break;
		}
	}

	int result = end - start - num;
	if (result < 0) {
		cout << 0;
		return 0;
	}
	cout << result / 7 + 1;

	
}