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

    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            result++;
            i += 2 * m + 1;
        }
    }

    cout << result;
}