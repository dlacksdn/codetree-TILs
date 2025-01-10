#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
	Person(int person_, int cheese_, int time_)
	: person(person_), cheese(cheese_), time(time_) {}

	int person;
	int cheese;
	int time;
};

struct process {
	bool operator() (const Person& a, const Person& b) const {
		if (a.person != b.person) {
			return a.person < b.person;
		}
		if (a.cheese != b.cheese) {
			return a.cheese < b.cheese;
		}
		return a.time > b.time;
	}
};

int main() {
	int N, cheese, eat, sick;
	cin >> N >> cheese >> eat >> sick;

	vector<Person> per;
	vector<pair<int, int>> si;
	vector<bool> isEat(cheese + 1, false); // true면 먹은 것
	vector<bool> isTime(cheese + 1, false); // true면 먹고나서 아팠다.
	vector<bool> chState1(cheese + 1, false); // true면 멀쩡한 치즈
	vector<bool> chState2(cheese + 1, false); // true면 멀쩡한 치즈
	vector<bool> chState(cheese + 1, false); // true면 멀쩡한 치즈

	for (int i = 0; i < eat; i++) {
		int person, cheese, time;
		cin >> person >> cheese >> time;
		per.push_back(Person(person, cheese, time));
	}

	sort(per.begin(), per.end(), process());

	for (int i = 0; i < sick; i++) {
		int p, t;
		cin >> p >> t;
		si.push_back({ p, t });
	}

	for (int i = 0; i < sick; i++) { // 1. 환자 리스트에 있는 사람이 어떤 치즈를 먹은 적이 없다면 그 치즈는 상한 치즈가 아니다.
		for (int j = 0; j < eat; j++) {
			if (si[i].first == per[j].person) {
				isEat[per[j].cheese] = true;
			}
		}

		for (int j = 1; j <= cheese; j++) {
			if (isEat[j] == false) {
				chState1[j] = true;
			}
		}

		for (int j = 0; j <= cheese; j++) {
			isEat[j] = false;
		}
	}

	

	

	for (int i = 0; i < sick; i++) { // 2. 아픈 후에 어떤 치즈를 먹었다면 그 치즈는 상한 치즈가 아니다.
		for (int j = 0; j < eat; j++) {
			bool flag = false; // true면 상했을 여지 있음
			if (si[i].first == per[j].person) { 
				if (j != eat - 1) {
					if (per[j].cheese != per[j + 1].cheese) { // 다음부터 다른 치즈
						if (si[i].second > per[j].time) {
							flag = true;
						}
						if (flag) {
							isTime[per[j].cheese] = true;
						}
						flag = false;
					}

					if (per[j].cheese == per[j + 1].cheese) { // 다음도 같은 치즈
						if (si[i].second > per[j].time) {
							flag = true;
						}
					}
				}
				else {
					if (si[i].second > per[j].time) {
						flag = true;
					}
					if (flag) {
						isTime[per[j].cheese] = true;
					}
					flag = false;
				}
			}
		}
	}

	for (int i = 1; i <= cheese; i++) {
		if (isTime[i] == false) {
			chState2[i] = true;
		}
	}



	int count = 0;
	int result = 0;

	for (int i = 1; i <= cheese; i++) {
		chState[i] = chState1[i] || chState2[i];
	}

	for (int i = 1; i <= cheese; i++) { // 최대값 찾기
		if (chState[i] == true) {
			continue;
		}

		for (int j = 0; j < eat; j++) {
			if (j != 0) {
				if (per[j].cheese == i && per[j].person != per[j - 1].person) {
					count++;
				}
			}
			else {
				if (per[j].cheese == i) {
					count++;
				}
			}
		}

		result = max(result, count);
		count = 0;
	}

	cout << result;
}

/*
각 사람마다 어떤 치즈를 언제 먹었는지 저장해야함. (사람마다 2가지 정보를 저장)
아픈 정보를 저장해야함
예제 설명을 보아하니 치즈마다 최대 몇 명의 사람을 아프게 할 수 있는지를 전부 탐색하고 최대값을 출력해야함

치즈가 상한 치즈인지 아닌지를 판단하는 알고리즘이 필요함
1. 환자 리스트에 있는 사람이 어떤 치즈를 먹은 적이 없다면 그 치즈는 상한 치즈가 아니다.
2. 아픈 후에 어떤 치즈를 먹었다면 그 치즈는 상한 치즈가 아니다.

먹은 적이 있고 아파지기 전에 먹었다면 상한 치즈라고 간주해야 한다.
그러면 그 치즈를 먹은 사람을 전부 count하면 된다

상한 치즈는 단 1개라는 사실에 주목해야 한다

상한 치즈가 아닌 리스트를 모은 다음 그거 제외하고 치즈 완전탐색해서 아프기 전에 먹은 사람수 count 한다 

3 4 7 2
1 1 1
1 1 3
1 3 4
1 2 2
3 1 3
2 1 5
2 2 7
1 3
2 8

1번 사람 1 2
2번 사람 1 2
3번 사람 1

*/

