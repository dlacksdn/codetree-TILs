#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Process {
    bool operator() (pair<int, int> left, pair<int, int> right) {
        if (left.second != right.second) {
            return left.second >= right.second;
        }
        
        return left.first >= right.first;
    }
};

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
                if (bomb_num[i].second == false) { // 폭탄이 터진 적이 없다면 == 점수 산정을 한 적이 없다면
                    m[bomb_num[i].first]++;
                    bomb_num[i].second = true;
                }

                if (bomb_num[i + j].second == false) { // 폭탄이 터진 적이 없다면 == 점수 산정을 한 적이 없다면
                    m[bomb_num[i + j].first]++;
                    bomb_num[i + j].second = true;
                }
            }
        }
    }

    vector<pair<int, int>> result(m.begin(), m.end());
    if (result.size() == 0) {
        cout << 0;
    }
    else {
        sort(result.begin(), result.end(), Process());
        cout << result[0].first;
    }

}