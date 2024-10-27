#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N + 1, 0);
	
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {

			double avg = 0;
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += v[k];
			}

			avg = (double)(sum) / (j - i + 1);

			auto it = find(v.begin(), v.end(), avg);
			if (it != v.end()) count++;
		}
	}

	cout << count << "\n";
}