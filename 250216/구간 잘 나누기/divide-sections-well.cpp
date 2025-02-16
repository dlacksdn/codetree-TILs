#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 주어진 상한(maxSum)으로 m개 이하의 구간으로 분할 가능한지 판단
bool canPartition(const vector<int>& arr, int m, int maxSum) {
    int segments = 1, currentSum = 0;
    for (int a : arr) {
        if (currentSum + a > maxSum) {
            segments++;
            currentSum = a;
        } else {
            currentSum += a;
        }
    }
    return segments <= m;
}

// 재귀적으로 이분 탐색 수행: [low, high] 범위 내에서 최적 해를 찾음
int binarySearch(const vector<int>& arr, int m, int low, int high) {
    if (low > high) return low;
    int mid = (low + high) / 2;
    if (canPartition(arr, m, mid)) {
        return binarySearch(arr, m, low, mid - 1);
    } else {
        return binarySearch(arr, m, mid + 1, high);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int low = *max_element(arr.begin(), arr.end());
    int high = 0;
    for (int a : arr) high += a;
    
    int ans = binarySearch(arr, m, low, high);
    cout << ans << "\n";
    return 0;
}
