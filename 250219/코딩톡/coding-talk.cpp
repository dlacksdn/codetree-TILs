#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; // 사람이 몇 명인지
    int M; // 메세지 수
    int p; // 기준 메세지 번호
    cin >> N >> M >> p;

    vector<pair<char, int>> message_info(M + 1);
    message_info[0] = { ' ', -1 };

    for (int i = 1; i <= M; i++) {
        cin >> message_info[i].first >> message_info[i].second;
    }

    vector<char> result(N);

    for (int i = 0; i < N; i++) {
        result[i] = 'A' + i;
    }

    for (int i = p; i <= M; i++) { // i : message_info를 순회하는 인덱스

        // 메세지가 보내진 시간 or 그 이후에 메세지를 보낸 적이 있다 -> 봤다
        auto it = find(result.begin(), result.end(), message_info[i].first);
        if (it != result.end()) { // result에 찾는 원소가 존재한다
            result.erase(it);
        }

        // 메세지가 보내진 시간 or 그 이후에 u = 0인 때가 있다 -> 다 봤다
        if (message_info[i].second == 0) {
            return 0;
        }
    }

    for (char c : result) {
        cout << c << " ";
    }
}