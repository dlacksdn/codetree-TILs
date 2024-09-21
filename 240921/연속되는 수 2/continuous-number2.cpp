#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int n;
int arr[MAX_N];

int main() {
    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 연속하여 동일한 숫자가 나오는 횟수를 구해보며,
    // 그 중 최댓값을 갱신합니다.
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
		// Case 1
        if(i >= 1 && arr[i] == arr[i - 1])
            cnt++;
		// Case 2
        else
            cnt = 1;
        
        ans = max(ans, cnt);
    }
    
    cout << ans;
    return 0;
}