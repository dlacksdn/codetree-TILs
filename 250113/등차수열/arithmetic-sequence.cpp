#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	

	for (auto& p : v) cin >> p;
	sort(v.begin(), v.end());

	int max = (v.back() + *v.begin()) / 2;

	vector<int> list(max + 1);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			for (int k = 1; k <= max; k++) {
				if ((v[i] + v[j]) % 2 != 0) break;

				if ((v[i] + v[j]) / 2 == k) {
					list[k]++;
				}
			}
		}
	}

	cout << *(max_element(list.begin(), list.end()));
}