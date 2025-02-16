#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // m 구간이면 m-1개의 분할점(칸막이)을 선택
    int k = m - 1;

    // 누적합(prefix sum) 계산: prefix[i+1] = sum(arr[0]..arr[i])
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // 초기 조합: 첫 k개의 인덱스
    vector<int> comb(k);
    for (int i = 0; i < k; i++) {
        comb[i] = i;
    }

    int best = 1e9;
    while (true) {
        int currentMax = 0;
        int prev = -1;
        // 분할점에 따른 각 구간의 합을 계산 (누적합을 이용)
        for (int idx = 0; idx < k; idx++) {
            int pos = comb[idx];
            int sum = prefix[pos + 1] - prefix[prev + 1];
            currentMax = max(currentMax, sum);
            if (currentMax >= best) break;  // 가지치기
            prev = pos;
        }
        int sum = prefix[n] - prefix[prev + 1]; // 마지막 구간
        currentMax = max(currentMax, sum);
        best = min(best, currentMax);

        // 다음 조합 생성 (사전순 순회)
        int i;
        for (i = k - 1; i >= 0; i--) {
            if (comb[i] < n - k + i) {
                comb[i]++;
                for (int j = i + 1; j < k; j++) {
                    comb[j] = comb[j - 1] + 1;
                }
                break;
            }
        }
        if (i < 0) break;
    }

    cout << best;
    return 0;
}
