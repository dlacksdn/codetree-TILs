#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
	int X;
	int Y;
	int index;

	Process(int a, int b, int i) {
		X = a;
		Y = b;
		index = i;
	}
	Process() {}
};

bool isValue(Process a, Process b) {
	int numA = abs(a.X) + abs(a.Y);
	int numB = abs(b.X) + abs(b.Y);

	if (numA != numB) {
		return numA < numB;
	}
	return a.index < b.index;
}

int main() {
	int N;
	cin >> N;

	vector<Process> v(N);
	int x, y;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v[i] = Process(x, y, i+1);
	}

	sort(v.begin(), v.end(), isValue);

	for (int i = 0; i < N; i++) {
		cout << v[i].index << "\n";
	}
}