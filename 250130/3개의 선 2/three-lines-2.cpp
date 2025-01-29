#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int N;
	cin >> N;

	vector<int> x_arr;
	vector<int> y_arr;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		auto it_x = find(x_arr.begin(), x_arr.end(), x);
		auto it_y = find(y_arr.begin(), y_arr.end(), y);

		if (it_x != x_arr.end() && it_y != y_arr.end()) {
			x_arr.push_back(x);
			y_arr.push_back(y);
		}
	}

	cout << (x_arr.size() <= 3) ? 1 : 0;
}