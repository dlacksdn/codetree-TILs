#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define plus 100

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	int arr[201] = { 0, };

	int left, right;
	for (int i = 0; i < n; i++) {
		cin >> left >> right;
		v[i].first = left + plus;
		v[i].second = right + plus - 1;
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i].first; j <= v[i].second; j++) {
			arr[j]++;
		}
	}

	auto result = max_element(arr, arr + 201);
	cout << *result;
}