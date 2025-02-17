#include <iostream>
#include <vector>
using namespace std;

void decide(vector<int> v, vector<int>& plus, int H, bool& flag) { // H점수가 가능한지 판단하는 함수
    for (int i = 0; i < plus.size(); i++) {
        v[plus[i]]++;
    }

    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= H)
            count++;
    }

    if (count >= H) {
        flag = true;
    }
}

int main() {
    int N; // 주어지는 숫자의 개수
    int L; // +1을 하는 원소의 개수

    cin >> N >> L;

    vector<int> v(N); // 입력받은 수열
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> plus(L);
    

    bool flag = false;
    for (int i = N; i >= 0; i--) { // i : 임의의 H점수
        for (int j = 0; j < L; j++) {
            plus[j] = j;
        }

        while (true) {
            decide(v, plus, i, flag);
            if (flag) {
                cout << i;
                return 0;
            }

            int j;
            for (j = L - 1; j >= 0; j--) { // j : 벡터 plus를 순회하는 인덱스
                if (N - L + j <= plus[j]) { // 더 이상 올릴 수 없음
                    continue;
                }

                plus[j]++;

                for (int k = j + 1; k < L; k++) {
                    plus[k] = plus[k - 1] + 1;
                }

                break;
            }

            if (j < 0) {
                break;
            }
        }
    }
}