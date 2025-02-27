#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum += v[i];
    }

    int target_num = sum / N;

    int result = 0;
    for (int i = 0; i < N; i++) {
        result += abs(v[i] - target_num);
    }

    cout << result / 2;
}

/*
합 전부 계산하고 합 / N 해서 나오는 값이 최종적으로 각 요소들이 되어야 하는 값이다.
필요한 값을 전부 계산하고 나누기 2를 한다. 왜냐하면 블럭을 옮기는 작업이기 때문에 각 과정이 2번 count된다.
*/