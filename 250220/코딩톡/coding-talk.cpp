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

        //if (i >= p) {
        //    // 메세지가 보내진 시간 or 그 이후에 메세지를 보낸 적이 있다 -> 봤다
        //    auto it = find(result.begin(), result.end(), message_info[i].first);
        //    if (it != result.end()) { // result에 찾는 원소가 존재한다
        //        result.erase(it);
        //    }

        //    // 메세지가 보내진 시간 or 그 이후에 u = 0인 때가 있다 -> 다 봤다
        //    if (i == p && message_info[i].second == 0) {
        //        return 0;
        //    }
        //}

        if (i == p && message_info[i].second == 0) {
            return 0;
        }

        if (message_info[i].second >= message_info[p].second) {
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

/*
6 6 5
D 0
C 1
B 2
B 2
A 2 <-
F 4


지정된 메세지의 u가 2인 상황
3, 4 번째 메세지도 u가 2인 상황

A B C D E F
누가 보지 않았는지 정확히 특정할 수 없지만 누가 봤는지는 일부 특정할 수 있다.
3 번째 B 2를 안 본 사람을 x, y라고 하자

4 번째 B 2를 안 본 사람은 3 번째와 바뀌지 않는다

3 번째를 본 사람을 A C라고 해보자
4 번째를 본 사람을 C D라고 가정해보자

A는 3 번째를 보지 않았다. 하지만 4 번째에서 명단에 빠짐으로서 A는 4 번째를 봤다.
이 문제는 중간에 톡방에 들어올 시 전에 보내진 메세지도 다 볼 수 있다고 하였다. 
즉, A는 4 번째를 봄과 동시에 3 번째를 반드시 보게 된다.
그러면 A는 3 번째 메세지를 봤기 때문에 3 번째 메세지 정보 B 2는 B 2가 아니라 B 1이어야 한다.
-> u가 유지될 때 안 본 사람의 명단에 적혀 있던 사람은 빠지면 안 되므로 같은 u의 메세지를 보낸 사람들은 해당 u의 메세지들을 반드시 봤다. 

*/