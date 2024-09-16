#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
	int height;
	int weight;
	int index;

	Process(int a, int b, int c) {
		height = a;
		weight = b;
		index = c;
	}
	Process() {}
};

bool isValue(Process a, Process b) {
	if (a.height != b.height) {
		return a.height < b.height;
	}
	return a.weight > b.weight;

}

int main() {
	int n;
	cin >> n;

	int height;
	int weight;
	vector<Process> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> height >> weight;
		v[i] = Process(height, weight, i + 1);
	}

	sort(v.begin(), v.end(), isValue);

	for (int i = 0; i < n; i++) {
		cout << v[i].height << " ";
		cout << v[i].weight << " ";
		cout << v[i].index << "\n";
	}
}