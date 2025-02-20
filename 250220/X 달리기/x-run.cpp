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