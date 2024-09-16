#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
	string name;
	int one;
	int two;
	int three;

	Process(string nm, int on, int tw, int thr) : name(nm), one(on), two(tw), three(thr)
	{}
	Process() {}
};

bool isValue(const Process& a, const Process& b) {
	return a.one + a.two + a.three < b.one + b.two + b.three;
}

int main() {
	int n;
	cin >> n;

	string name;
	int one;
	int two;
	int three;
	vector<Process> v(n);

	for (int i = 0; i < n; i++) {
		cin >> name >> one >> two >> three;
		v[i] = Process(name, one, two, three);
	}
	
	sort(v.begin(), v.end(), isValue);

	for (int i = 0; i < n; i++) {
		cout << v[i].name << " ";
		cout << v[i].one << " ";
		cout << v[i].two << " ";
		cout << v[i].three << "\n";
	}
}