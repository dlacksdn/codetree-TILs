#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;





int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	
	int result = 0;
	int count = 0;
	// 1. 가위 2. 바위 3. 보
	for (int i = 0; i < N; i++) {
		if (v[i].first == 2 && v[i].second == 1 || 
			v[i].first == 1 && v[i].second == 3 || 
			v[i].first == 3 && v[i].second == 2)
		{
			count++;
		}
	}
	result = max(result, count);
	count = 0;

	// 1. 가위 2. 보 3. 바위
	for (int i = 0; i < N; i++) {
		if (v[i].first == 3 && v[i].second == 1 ||
			v[i].first == 1 && v[i].second == 2 ||
			v[i].first == 2 && v[i].second == 3)
		{
			count++;
		}
	}
	result = max(result, count);
	count = 0;

	// 1. 바위 2. 가위 3. 보
	for (int i = 0; i < N; i++) {
		if (v[i].first == 1 && v[i].second == 2 ||
			v[i].first == 2 && v[i].second == 3 ||
			v[i].first == 3 && v[i].second == 1)
		{
			count++;
		}
	}
	result = max(result, count);
	count = 0;

	// 1. 보 2. 가위 3. 바위
	for (int i = 0; i < N; i++) {
		if (v[i].first == 3 && v[i].second == 2 ||
			v[i].first == 2 && v[i].second == 1 ||
			v[i].first == 1 && v[i].second == 3)
		{
			count++;
		}
	}
	result = max(result, count);
	count = 0;

	// 1. 바위 2. 보 3. 가위
	for (int i = 0; i < N; i++) {
		if (v[i].first == 1 && v[i].second == 3 ||
			v[i].first == 3 && v[i].second == 2 ||
			v[i].first == 2 && v[i].second == 1)
		{
			count++;
		}
	}
	result = max(result, count);
	count = 0;

	// 1. 보 2. 바위 3. 가위
	for (int i = 0; i < N; i++) {
		if (v[i].first == 2 && v[i].second == 3 ||
			v[i].first == 3 && v[i].second == 1 ||
			v[i].first == 1 && v[i].second == 2)
		{
			count++;
		}
	}
	result = max(result, count);
	count = 0;

	cout << result;
}

/*
바위 가위
가위 보
보 바위


*/