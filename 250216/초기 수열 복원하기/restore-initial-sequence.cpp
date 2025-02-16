#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N - 1); // 입력받은 수열 (인접한 숫자들의 합

    for (int i = 0; i < N - 1; i++) {
        cin >> v[i];
    }

    vector<int> list(N); // 오리지널 수열
    for (int i = 1; i <= N; i++) { // i : 0번째 인덱스 값
        list[0] = i;
        for (int j = 1; j < N; j++) {
            list[j] = v[j - 1] - list[j - 1];
        }

        unordered_set<int> s(list.begin(), list.end());
        if (list.size() == s.size()) { // 중복이 없다면
            if (find(list.begin(), list.end(), 0) == list.end()) { // list수열내에 0이 없다면
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << list[i] << " ";
    }
}