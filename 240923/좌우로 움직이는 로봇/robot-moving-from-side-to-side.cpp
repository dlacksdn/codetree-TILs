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

	/*int rangeMin = 0;
	int rangeMax = 0;
	char flag = ' ';
	if (A_Location.size() > B_Location.size()) {
		rangeMin = B_Location.size();
		rangeMax = A_Location.size();
		flag = 'A';
	}
	else {
		rangeMin = A_Location.size();
		rangeMax = B_Location.size();
		flag = 'B';
	}*/

	int count = 0;
	for (int i = 1; i < A_Location.size(); i++) {
		if (A_Location[i - 1] != B_Location[i - 1] && A_Location[i] == B_Location[i]) {
			count++;
		}
	}

	/*if (flag == 'A') {
		int num = B_Location[rangeMin - 1];
		for (int i = rangeMin; i < rangeMax; i++) {
			if (A_Location[i - 1] != num && A_Location[i] == num) {
				count++;
			}
		}
	}
	else if(flag == 'B') {
		int num = A_Location[rangeMin - 1];
		for (int i = rangeMin; i < rangeMax; i++) {
			if (B_Location[i - 1] != num && B_Location[i] == num) {
				count++;
			}
		}
	}*/
	cout << count;

}