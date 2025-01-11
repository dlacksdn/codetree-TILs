#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	vector<int> list(101, 0);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a, b };
	}

	for (int i = 0; i < n; i++) {
		for (int j = v[i].first; j <= v[i].second; j++) {
			list[j]++;
		}
	}

	vector<int> base = list;

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				base = list;

				for (int r = v[i].first; r <= v[i].second; r++) {
					base[r]--;
				}

				for (int r = v[j].first; r <= v[j].second; r++) {
					base[r]--;
				}

				for (int r = v[k].first; r <= v[k].second; r++) {
					base[r]--;
				}

				bool flag = true;
				for (auto& num : base) {
					if (num >= 2) {
						flag = false;
						break;
					}
				}

				if (flag) {
					count++;
				}
			}
		}
	}

	cout << count;
}

