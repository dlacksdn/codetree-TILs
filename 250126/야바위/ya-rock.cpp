#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
	Process(int a_, int b_, int c_) {
		a = a_;
		b = b_;
		c = c_;
	}

	int a, b, c;
};

int main() {
	int N;
	cin >> N;

	vector<Process> v;
	vector<bool> location(4, false);

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Process(a, b, c));
	}

	int result = 0;
	for (int i = 1; i <= 3; i++) {
		location[i] = true;
		int count = 0;

		for (int j = 0; j < N; j++) {
			bool tmp = location[v[j].a];
			location[v[j].a] = location[v[j].b];
			location[v[j].b] = tmp;

			if (location[v[j].c]) {
				count++;
			}
		}

		result = max(result, count);
		fill(location.begin(), location.end(), false);

	}

	cout << result;

}