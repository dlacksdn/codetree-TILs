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

    vector<char> result(N); // 안 봤을 가능성이 있는 사람들

    for (int i = 0; i < N; i++) {
        result[i] = 'A' + i;
    }

    for (int i = 1; i <= M; i++) { // i : message_info를 순회하는 인덱스

        if (i >= p) {
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
        else if (message_info[i].second == message_info[p].second) {
            // 보낸 사람이 바뀌었는데 안 본 사람의 수가 같다 -> 톡방에 들어오면 전의 대화도 봐지기 때문에 u가 같은 메세지 정보의 사람끼리는 무조건 같은 u의 메세지를 봤다  
            // 즉, 제시된 메세지 번호의 u와 일치하는 메세지를 보낸 사람은 제시된 메세지를 반드시 봤다 
            
            auto it = find(result.begin(), result.end(), message_info[i].first);
            if (it != result.end()) { // 존재한다
                result.erase(it);
            }
        }

    }

    for (char c : result) {
        cout << c << " ";
    }
}