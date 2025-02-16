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
    
    // 최소 가능한 상한은 배열의 최댓값, 최대는 배열 전체 합
    int low = *max_element(arr.begin(), arr.end());
    int high = 0;
    for (int a : arr) high += a;
    
    int ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        int segments = 1, currentSum = 0;
        for (int i = 0; i < n; i++) {
            if (currentSum + arr[i] > mid) {  // mid를 초과하면 새 구간 시작
                segments++;
                currentSum = arr[i];
            } else {
                currentSum += arr[i];
            }
        }
        
        // m개 이하의 구간으로 분할 가능한 경우
        if (segments <= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
