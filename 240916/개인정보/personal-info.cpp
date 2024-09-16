#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Process {
public:
	string name;
	int height;
	double weight;
	

	Process(string nm, int h, double w) {
		name = nm;
		height = h;
		weight = w;
	}
	Process() {}
};

bool isValueName(const Process& a, const Process& b) {
	return a.name < b.name;
}

bool isValueHeight(const Process& a, const Process& b) {
	return a.height > b.height;
}

int main() {
	int n = 5;

	string name;
	int height;
	double weight;
	vector<Process> v(n);

	for (int i = 0; i < n; i++) {
		cin >> name >> height >> weight;
		v[i] = Process(name, height, weight);
	}
	
	sort(v.begin(), v.end(), isValueName);

	cout << "name" << "\n";
	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(1);
		cout << v[i].name << " ";
		cout << v[i].height << " ";
		cout << v[i].weight << "\n";
	}

	sort(v.begin(), v.end(), isValueHeight);

	cout << "\nheight" << "\n";
	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(1);
		cout << v[i].name << " ";
		cout << v[i].height << " ";
		cout << v[i].weight << "\n";
	}
}