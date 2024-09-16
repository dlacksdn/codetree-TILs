#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
	int height;
	int weight;
	int index;

	Process(int h, int w, int i) {
		height = h;
		weight = w;
		index = i;
	}
	Process() {}
};

bool isValue(const Process& a, const Process& b) {
	if (a.height != b.height) {
		return a.height > b.height;
	}
	else if (a.weight != b.weight) {
		return a.weight > b.weight;
	}
	else {
		return a.index < b.index;
	}
}

int main() {
	int n;
	cin >> n;

	int height;
	int weight;
	vector<Process> v(n);

	for (int i = 0; i < n; i++) {
		cin >> height >> weight;
		v[i] = Process(height, weight, i+1);
	}
	
	sort(v.begin(), v.end(), isValue);

	for (int i = 0; i < n; i++) {
		cout << v[i].height << " ";
		cout << v[i].weight << " ";
		cout << v[i].index << "\n";
	}
}