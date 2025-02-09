#include <iostream>
#include <vector>
#include <algorithm>
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

    int result = 0;
    for (int i = min_num; i <= max_num; i++) { // i : 숫자 범위의 최솟값
        int count = 0;

        for (int j = 0; j < N; j++) { // 벡터 v의 모든 요소 탐색
            if (i <= v[j] && v[j] <= i + K) {
                count++;
            }
        }

        result = max(result, count);
    }

    cout << result;
}