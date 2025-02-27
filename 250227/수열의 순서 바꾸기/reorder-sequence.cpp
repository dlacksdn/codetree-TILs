#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> test = v;
    sort(test.begin(), test.end());

    int count = 0;

    while (v != test) {
        if (v[0] != 1) { // 맨 앞이 최소가 아님
            auto it = find(v.begin(), v.end(), v[0] - 1);
            rotate(v.begin(), v.begin() + 1, it + 1);
        }
        else {
            auto it = find(v.begin(), v.end(), N);
            rotate(v.begin(), v.begin() + 1, it + 1);
        }

        count++;
    }

    cout << count;
}

