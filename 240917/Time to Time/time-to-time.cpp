#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int start = a * 60 + b;
	int end = c * 60 + d;

	cout << end - start << "\n";
}