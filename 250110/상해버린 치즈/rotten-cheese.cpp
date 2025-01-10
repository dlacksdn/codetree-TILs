#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Sickness {
    int person;
    int time;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, cheese, eat, sick;
    cin >> N >> cheese >> eat >> sick;

    // 치즈별로 (사람, 시간) 저장
    // cheese_index는 1부터 cheese까지 사용
    vector<vector<pair<int, int>>> cheeseEaters(cheese + 1, vector<pair<int, int>>());

    for (int i = 0; i < eat; ++i) {
        int person, ch, time;
        cin >> person >> ch >> time;
        cheeseEaters[ch].emplace_back(person, time);
    }

    // 아픈 사람과 그들의 아픈 시간 저장
    vector<Sickness> sicknessList(sick, Sickness());
    for (int i = 0; i < sick; ++i) {
        cin >> sicknessList[i].person >> sicknessList[i].time;
    }

    // 가능한 상한 치즈 후보
    vector<int> possibleCheeses;

    // 각 치즈별로 모든 아픈 사람이 해당 치즈를 먹었고, 먹은 시간이 아픈 시간보다 이전인지 확인
    for (int ch = 1; ch <= cheese; ++ch) {
        bool isPossible = true;
        for (auto& sickPerson : sicknessList) {
            bool ateBeforeSick = false;
            for (auto& eatInfo : cheeseEaters[ch]) {
                if (eatInfo.first == sickPerson.person && eatInfo.second < sickPerson.time) {
                    ateBeforeSick = true;
                    break;
                }
            }
            if (!ateBeforeSick) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            possibleCheeses.push_back(ch);
        }
    }

    // 만약 가능한 상한 치즈가 없으면 결과는 0
    if (possibleCheeses.empty()) {
        cout << 0;
        return 0;
    }

    // 가능한 상한 치즈 중에서 최대 영향을 미친 사람 수 찾기
    int maxAffected = 0;

    for (auto& ch : possibleCheeses) {
        // 이 치즈를 먹은 사람 중 최소 아픈 시간 이전에 먹은 사람 수
        unordered_set<int> affected;
        for (auto& eatInfo : cheeseEaters[ch]) {
            // 해당 사람이 아픈 경우에만 카운트
            // 만약 사람이 여러 번 먹었을 경우, 아픈 시간 이전에 먹은 적이 있는지 확인
            // 이는 이미 상한 치즈 후보에 포함되었으므로 아픈 사람은 이 치즈를 먹었음
            affected.insert(eatInfo.first);
        }
        maxAffected = max(maxAffected, (int)affected.size());
    }

    cout << maxAffected;
}
