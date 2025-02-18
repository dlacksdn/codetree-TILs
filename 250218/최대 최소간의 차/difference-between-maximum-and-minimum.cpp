#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int min_num = *min_element(v.begin(), v.end());
    int max_num = *max_element(v.begin(), v.end());

    int result = INT_MAX;
    for (int i = min_num; i <= max_num; i++) { // i : 임의의 최소값
        int count = 0;

        for (int j = 0; j < N; j++) { // j : 벡터 v를 순회하는 인덱스
            if (!(i <= v[j] && v[j] <= i + K)) { // 해당 인덱스의 원소가 범위에 있지 않은 경우
                int dis = min(abs(v[j] - i), abs(v[j] - (i + K)));
                count += dis;
            }
        }

        result = min(result, count);
    }

    cout << result;
}