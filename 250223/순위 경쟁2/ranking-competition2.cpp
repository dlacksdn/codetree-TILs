#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<char, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	int prev = 0;
	int present = 0;
	int A = 0, B = 0;

	int count = 0;
	for (int i = 0; i < N; i++) {
		(v[i].first == 'A') ? A += v[i].second : B += v[i].second;

		if (A > B)
			present = -1;
		else if (A == B)
			present = 0;
		else
			present = 1;

		if (prev != present)
			count++;

		prev = present;
	}

	cout << count;
}