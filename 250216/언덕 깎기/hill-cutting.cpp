#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

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
            if (v[j] < i || v[j] > i + 17) { // 숫자가 정해진 범위에 들어 있지 않은 경우 
                int num1 = abs(v[j] - i);
                int num2 = abs(v[j] - (i + 17));
                int distance = min(num1, num2);

                count += distance * distance;
            }
        }

        result = min(result, count);
    }

    cout << result;
}
