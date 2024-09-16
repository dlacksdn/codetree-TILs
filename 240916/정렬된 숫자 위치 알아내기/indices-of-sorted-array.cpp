#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
	int value;
	int originIndex;
	int changeIndex;

	Process(int a, int b) {
		value = a;
		originIndex = b;
		changeIndex = 0;
	}

	Process() {}
};

bool isValue(Process a, Process b) {
	if (a.value != b.value) {
		return a.value < b.value;
	}
	return a.originIndex < b.originIndex;
}

bool isValueOrigin(Process a, Process b) {
	return a.originIndex < b.originIndex;
}

int main() {
	int n;
	cin >> n;

	int value;
	int originIndex;
	int changeIndex;
	vector<Process> v(n);

	for (int i = 0; i < n; i++) {
		cin >> value;
		v[i] = Process(value, i + 1);
	}

	sort(v.begin(), v.end(), isValue);

	for (int i = 0; i < n; i++) {
		v[i].changeIndex = i + 1;
	}

	sort(v.begin(), v.end(), isValueOrigin);

	for (int i = 0; i < n; i++) {
		cout << v[i].changeIndex << " ";
	}
}