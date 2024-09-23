#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> A_Location;
	vector<int> B_Location;
	A_Location.push_back(0); B_Location.push_back(0);

	int A_index = 0;
	for (int i = 0; i < n; i++) {
		int t; char d;
		cin >> t >> d;

		if (d == 'L') {
			for (int j = 0; j < t; j++) {
				A_Location.push_back(--A_index);
			}
		}
		else {
			for (int j = 0; j < t; j++) {
				A_Location.push_back(++A_index);
			}
		}
	}

	int B_index = 0;
	for (int i = 0; i < m; i++) {
		int t; char d;
		cin >> t >> d;

		if (d == 'L') {
			for (int j = 0; j < t; j++) {
				B_Location.push_back(--B_index);
			}
		}
		else {
			for (int j = 0; j < t; j++) {
				B_Location.push_back(++B_index);
			}
		}
	}

	if (A_Location.size() > B_Location.size()) {
		for (int i = B_Location.size(); i < A_Location.size(); i++) {
			B_Location.push_back(B_Location[i - 1]);
		}
	}
	else if (A_Location.size() < B_Location.size()) {
		for (int i = A_Location.size(); i < B_Location.size(); i++) {
			A_Location.push_back(A_Location[i - 1]);
		}
	}

	int count = 0;
	for (int i = 1; i < A_Location.size(); i++) {
		if (A_Location[i - 1] != B_Location[i - 1] && A_Location[i] == B_Location[i]) {
			count++;
		}
	}
	cout << count;
}