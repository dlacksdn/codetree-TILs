#include <iostream>
using namespace std;

int main() {
	int m1, d1, m2, d2;
	cin >> m1 >> d1 >> m2 >> d2;

	int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string day[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
	string dayRe[7] = { "Mon", "Sun", "Sat", "Fri", "Thu", "Wed", "Tue" };

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

	if (start < end) {
		int dif = (end - start) % 7;
		cout << day[dif] << "\n";
	}
	else {
		int dif = (start - end) % 7;
		cout << dayRe[dif] << "\n";
	}

	
}