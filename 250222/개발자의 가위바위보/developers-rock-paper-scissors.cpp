#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int process(int gawi, int bawi, int bo, int left, int right) {
    int left_num; // 0 : 가위, 1 : 바위, 2 : 보
    if (gawi == left) {
        left_num = 0;
    }
    else if (bawi == left) {
        left_num = 1;

    }
    else {
        left_num = 2;
    }

    int right_num; // 0 : 가위, 1 : 바위, 2 : 보
    if (gawi == right) {
        right_num = 0;
    }
    else if (bawi == right) {
        right_num = 1;
    }
    else {
        right_num = 2;
    }

    return (right - left + 3) % 3;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    vector<int> list({ 1, 2, 3 });

    int result = 0;
    do {
        int count = 0;
        for (int i = 0; i < N; i++) {
            int num = process(list[0], list[1], list[2], v[i].first, v[i].second);

            if (num == 2)
                count++;
        }

        result = max(result, count);

    } while (next_permutation(list.begin(), list.end()));

    cout << result;
}