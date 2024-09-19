#include <iostream>
#include <vector>
using namespace std;

#define OFFSET 100
int arr[201][201] = { 0, };

class Process {
public:
	int x1, y1, x2, y2;

	Process(int a, int b, int c, int d) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
	Process() {}
};

int result(const Process& process) {
	int count = 0;
	for (int i = process.x1; i < process.x2; i++) {
		for (int j = process.y1; j < process.y2; j++) {
			if (arr[i][j] == 0) {
				count++;
				arr[i][j] = 1;
			}
		}
	}

	return count;
}

int main() {
	int n;
	cin >> n;

	vector<Process> v(n);
	int x1, y1, x2, y2;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		v[i] = Process(x1 + OFFSET, y1 + OFFSET, x2 + OFFSET, y2 + OFFSET);
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += result(v[i]);
	}

	cout << sum;
}