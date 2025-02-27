#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(2 * N);

    for (int i = 0; i < 2 * N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int result = INT_MAX;
    for (int i = 0; i < N; i++) {
        int num = abs(v[i] - v[i + N]);

        result = min(result, num);
    }

    cout << result;
}