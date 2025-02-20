#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    int count = 0;
    int result = 0;
    for (int i = 1; i <= N; i++) { // i : 현재 속도
        sum += i; 
        count++;

        int decision = N - (sum * 2);

        if (decision == 0) {
            result = count * 2;
            break;
        }

        if ((sum + i + 1) * 2 >= N) { // sum에 다음 숫자가 더해질 때 sum * 2 >= N임 -> 판정 타이밍
            if (decision <= i + 1) {
                result = (count * 2) + 1;
                break;
            }
            else {
                result = (count * 2) + 2;
                break;
            }
        }
    }

    cout << result;
}

/*
(1 2 3) 4 (1 2 3)처럼
반드시 같은 수열 2개가 존재함
위 코드에서 sum은 6

decision = N - (sum * 2)

경우의 수
(1 2 3) (3 2 1)
decision = 0

(1 2 3) (3 2 1) 1
decision = 1

(1 2 3) 3 (3 2 1)
decision = 현재 속도

(1 2 3) 4 (3 2 1)
decision = 현재 속도 + 1

(1 2) 3 (2 1) 1
decision = 현재 속도 + 2

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

항상
decision == 0
-> count * 2

다음 속도가 sum에 더해진다고 했을 때
(sum * 2) >= N이면 판정

decision > 현재 속도 + 1
-> (count * 2) + 2

decision <= 현재 속도 + 1
-> (count * 2) + 1
*/