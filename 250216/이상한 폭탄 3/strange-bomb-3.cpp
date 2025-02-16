#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void markExplosion(vector<pair<int, bool>>& bomb_num, unordered_map<int, int>& m, int index) {
    if (!bomb_num[index].second) {
        m[bomb_num[index].first]++;
        bomb_num[index].second = true;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, bool>> bomb_num(N, { 0, false }); // 폭탄의 번호와 점수 산정 유무
    unordered_map<int, int> m; // <정수, 터진 횟수>

    for (int i = 0; i < N; i++) {
        cin >> bomb_num[i].first;
    }

    for (int i = 0; i <= N - K - 1; i++) { // i : 기준 폭탄의 인덱스
        for (int j = 1; j <= K; j++) { // j : 기준 폭탄에서의 거리
            if (bomb_num[i].first == bomb_num[i + j].first) { // 주어진 거리내의 폭탄이 번호가 같은 상황
                markExplosion(bomb_num, m, i);
                markExplosion(bomb_num, m, i + j);
            }
        }
    }
   
    if (m.size() == 0) {
        cout << 0;
    }
    else {
        int max = 0;
        int result = 0;

        for (auto it = m.begin(); it != m.end(); it++) {
            if (max < it->second) {
                max = it->second;
                result = it->first;
            }
        }

        cout << result;
    }

}