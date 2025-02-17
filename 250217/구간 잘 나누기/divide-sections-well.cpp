#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 1; ; i++) { // i : 임의의 구간 합 최대값
        int section = 1; // 설정한 최대값에서 구간이 몇 개나 나눠졌는지
        int count = 0; // 누적합
        bool is_divide = true; // 현재 구간 합 최대값으로 구간을 나눌 수 있는가?

        for (int j = 0; j < N; j++) { // j : 벡터 v를 순회하는 인덱스
            if (v[j] > i) { // 원소 하나가 구간 합 최대값보다 큰 상황 -> 말이 안 됨
                is_divide = false;
                break;
            }

            if (count + v[j] > i) { // 누적합에 현재 인덱스를 더했더니 구간 합 최대값을 넘긴 상황 -> 현재 인덱스부터 새로운 구간
                section++;
                count = 0;
            }

            count += v[j];
        }

        if (is_divide && section <= M) { // section <= M인 이유는 M개보다 적게 구간을 나눴음에도 현재 설정한 구간 합 최대값을 만족시켰다면 최대값이 나오지 않은 구간을 더 쪼개서 M개로 맞출 수 있기 때문이다
            cout << i;
            return 0;
        }
    }
}