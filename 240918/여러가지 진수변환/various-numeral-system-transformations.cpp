#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, B;
	cin >> N >> B;

	vector<int> v;

	while (true) {
		if (N < B) {
			v.push_back(N);
			break;
		}

		v.push_back(N % B);
		N /= B;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}