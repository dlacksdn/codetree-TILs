#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<bool> is_in(n, false); // false면 개통 안 됨

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int result = 0;

    auto last_1 = find(v.rbegin(), v.rend(), 1);
    auto rit = last_1.base() - 1;
    int last1_index = distance(v.begin(), rit);

    for (int i = 0; i < n; i++) {
        if (v[i] == 1 && is_in[i] == false) { // 아직 개통이 되지 않은 1
            result++;
            int wifi = i + m;
            if (wifi >= n) {
                wifi -= (wifi - n - 1);
            }

            for (int j = wifi - m; j <= wifi + m; j++) {
                if (0 <= j && j < n) {
                    is_in[j] = true;
                }
            }
        }

        if (is_in[last1_index]) {
            break;
        }
    }

    cout << result;
}