#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5; // 숫자 범위 /  N개의 수가 주어지는거니까 0 ~ n-1이 맞다
    int m = 3; // 숫자 개수 / m개의 구간이니 m-1개의 숫자를 골라서 칸막이 설치

    cin >> n >> m;
    m--;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    vector<int> v(m); // 칸막이

    for (int i = 0; i < m; i++) { // 벡터 초기값 설정
        v[i] = i;
    }



    int result = 100;
    while (true) {
        
        int sum = 0;
        int index = 0;
        int max_num = 0;
        for (int i = 0; i < n; i++) { // i : list를 쭉 순회하는 인덱스
            sum += list[i];

            if (v.size() != index && i == v[index]) { // 현 list의 인덱스가 칸막이까지 온 상황
                index++;
                max_num = max(max_num, sum);
                sum = 0;
            }
        }

        max_num = max(max_num, sum);

        result = min(result, max_num);

        int i;
        for (i = m - 1; i >= 0; i--) { // 벡터의 맨 뒤 인덱스부터 살펴보겠다
            if (v[i] < n - m + i) { // 현재 위치의 숫자를 +1 할 수 있다
                v[i]++;

                for (int j = i + 1; j < m; j++) {
                    v[j] = v[j - 1] + 1;
                }

                break;
            }
        }

        if (i < 0) break;
    }

    cout << result;
}