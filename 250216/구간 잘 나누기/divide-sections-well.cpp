#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
vector<long long> prefix;  // 누적합 배열
int best = 1e9;          // 최적해 (최대 구간 합의 최소값)

void computePrefix() {
    prefix.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
}

// parts에는 분할 경계(칸막이)의 인덱스가 저장된다. (m 구간이면 m-1개 선택)
void backtrack(vector<int>& parts, int start) {
    if (parts.size() == m - 1) {  // 모든 분할점을 선택했다면
        int currentMax = 0;
        int prev = -1;
        // 각 구간의 합을 누적합을 통해 계산
        for (int p : parts) {
            int sum = prefix[p + 1] - prefix[prev + 1];
            currentMax = max(currentMax, sum);
            // 가지치기: 이미 현재 구간 합의 최대가 best 이상이면 더 계산할 필요 없음
            if (currentMax >= best) return;
            prev = p;
        }
        int sum = prefix[n] - prefix[prev + 1]; // 마지막 구간
        currentMax = max(currentMax, sum);
        best = min(best, currentMax);
        return;
    }

    for (int i = start; i < n; i++) {
        parts.push_back(i);
        backtrack(parts, i + 1);
        parts.pop_back();
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 누적합 배열 계산
    computePrefix();

    vector<int> parts;
    backtrack(parts, 0);

    cout << best;
    return 0;
}
