#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> plus, minus;
    bool is_zero = false;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num > 0) {
            plus.push_back(num);
        }
        else if (num < 0) {
            minus.push_back(num);
        }
        else {
            is_zero = true;
        }
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    int p_index = plus.size() - 1;
    int m_index = minus.size() - 1;

    int p_size = plus.size();
    int m_size = minus.size();

    int p3 = INT_MIN;
    int p1m2 = INT_MIN;
    int zero = INT_MIN;
    int p2m1 = INT_MIN;
    int m3 = INT_MIN;

    if (p_size >= 3) {
        p3 = plus[p_index] * plus[p_index - 1] * plus[p_index - 2];
    }

    if (p_size >= 1 && m_size >= 2) {
        p1m2 = minus[0] * minus[1] * plus[p_index];
    }

    if (is_zero) {
        zero = 0;
    }

    if (p_size >= 2 && m_size >= 1) {
        p2m1 = minus[m_index] * plus[0] * plus[1];
    }

    if (m_size >= 3) {
        m3 = minus[m_index] * minus[m_index - 1] * minus[m_index - 2];
    }

    int result = max({ p3, p1m2, zero, p2m1, m3 });

    cout << result;
}