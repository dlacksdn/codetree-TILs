#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; // 숫자의 개수
    int L; // 최대 몇 개까지 +1이 가능한가

    cin >> N >> L;

    vector<int> v(N); // 주어진 수열

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = N; i >= 0; i--) { // i : 임의의 H점수
        int origin = 0; // 원래 H보다 높은 숫자의 개수
        int plus = 0; // +1을 하면 H가 되는 숫자의 개수

        for (int j = 0; j < N; j++) { // j : 벡터 v를 순회하는 인덱스
            if (v[j] >= i) { // 해당 원소가 H 이상인 경우
                origin++;
            }
            else if (v[j] + 1 == i) { // +1을 하면 H가 되는 경우
                plus++;
            }
        }

        if (origin >= i) { // 원래 숫자 만으로도 H점수 조건 만족
            cout << i;
            return 0;
        }
        else if (origin + plus >= i && plus <= L) { // H점수 조건을 만족하고 +1을 한 숫자가 L개를 넘기지 않은 경우 -> 정답
            cout << i;
            return 0;
        }
    }
}