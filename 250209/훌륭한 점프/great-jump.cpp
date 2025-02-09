#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> arr = v;

    sort(arr.begin(), arr.end(), greater<>());

    int standard = max(v[0], v[n - 1]); // 이놈보다 최대값이 낮으면 안 된다.

    int result = INT_MAX;
    for (int i = 0; i < n; i++) { // i : arr을 순환하는 인덱스. 최대값을 관장하는 변수 
        if (arr[i] < standard) break;

        int count = 0;
        vector<int> vec(n, 0);

        for (int j = 0; j < n; j++) { // j : v를 순환하는 인덱스
            if (v[j] <= arr[i]) {
                vec[count++] = j;
            }
        }

        bool flag = true;
        for (int j = 1; j < count; j++) {
            if (vec[j] - vec[j - 1] > k) {
                flag = false;
                break;
            }
        }

        if (flag) {
            result = min(result, arr[i]);
        }
    }

    cout << result;
}