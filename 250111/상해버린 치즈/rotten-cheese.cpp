#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

struct Sick {
	int person;
	int time;
};

int main() {
	int N, cheese, eat, sick;
	cin >> N >> cheese >> eat >> sick;

	vector<vector<pair<int, int>>> v(cheese + 1, vector<pair<int, int>>());

	for (int i = 1; i <= eat; i++) {
		int p, m, t;
		cin >> p >> m >> t;
		
		v[m].emplace_back(p, t);
	}

	vector<Sick> sickV(sick);

	for (int i = 0; i < sick; i++) {
		cin >> sickV[i].person >> sickV[i].time;
	}

	vector<int> possibleCheese;

	for (int ch = 1; ch <= cheese; ch++) {
		bool isBad = true;
		for (auto& sickPerson : sickV) {
			bool possible = false;
			for (auto& cheeseValue : v[ch]) {
				if (sickPerson.person == cheeseValue.first && sickPerson.time > cheeseValue.second) {
					possible = true;
					break;
				}
			}
			if (!possible) {
				isBad = false;
				break;
			}
		}
		if (isBad) {
			possibleCheese.push_back(ch);
		}
	}

	int result = 0;
	for (auto& chNum : possibleCheese) {
		unordered_set<int> Set;
		for (auto& ch : v[chNum]) {
			Set.insert(ch.first);
		}

		result = max(result, (int)Set.size());
	}

	cout << result;
}