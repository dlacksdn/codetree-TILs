#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> v(10);

    pair<int, int> L;
    pair<int, int> R;
    pair<int, int> B;

    for (int i = 0; i < 10; i++) {
        cin >> v[i];

        for (int j = 0; j < 10; j++) {
            if (v[i][j] == 'L') {
                L.first = i;
                L.second = j;
            }
            else if (v[i][j] == 'R') {
                R.first = i; 
                R.second = j;
            }
            else if (v[i][j] == 'B') {
                B.first = i;
                B.second = j;
            }
        }
    }

    int dist = abs(L.first - B.first) + abs(L.second - B.second);
    int result = dist - 1;

    if (L.first == R.first && R.first == B.first) { // L R B가 같은 가로줄에 있음
        int leftY = min(L.second, B.second);
        int rightY = max(L.second, B.second);

        if (leftY < R.second && R.second < rightY) { // R이 L, B 사이에 있음
            result = dist + 1;
        }
    }
    else if (L.second == R.second && R.second == B.second) { // L R B가 같은 세로줄에 있음
        int topX = min(L.first, B.first);
        int bottomX = max(L.first, B.first);

        if (topX < R.first && R.first < bottomX) { // R이 L, B 사이에 있음
            result = dist + 1;
        }
    }

    cout << result;
}

