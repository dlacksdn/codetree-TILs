#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
	string name;
	int language;
	int english;
	int math;

	Process(string nm, int lang, int eng, int ma) {
		name = nm;
		language = lang;
		english = eng;
		math = ma;
	}
	Process() {}
};

bool isValue(const Process& left, const Process& right) {
	if (left.language != right.language) {
		return left.language > right.language;
	}
	else if (left.english != right.english) {
		return left.english > right.english;
	}
	else {
		return left.math > right.math;
	}
	
}

int main() {
	int n;
	cin >> n;

	string name;
	int language;
	int english;
	int math;
	vector<Process> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> name >> language >> english >> math;
		v[i] = Process(name, language, english, math);
	}

	sort(v.begin(), v.end(), isValue);

	for (int i = 0; i < n; i++) {
		cout << v[i].name << " " << v[i].language << " " << v[i].english << " " << v[i].math << "\n";
	}
}