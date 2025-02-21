#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, x, y;
	cin >> A >> B >> x >> y;
	
	int start = min(A, B);
	int end = max(A, B);

	int direct = end - start; // 텔포 x

	int tp_s = min(x, y);
	int tp_e = max(x, y);

	int tp = (start - tp_s) + (end - tp_e);

	cout << min(direct, tp);
}