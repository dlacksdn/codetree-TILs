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

    int result = 0;
    if (((L.first == R.first && R.first == B.first)) && (R.second > min(L.second, B.second)) && R.second < max(L.second, B.second)) { // L R B가 한 줄에 있음
        result = abs(L.first - B.first) + abs(L.second - B.second) + 1;
    }
    else if (((L.second == R.second && R.second == B.second)) && (R.first > min(L.first, B.first)) && R.first < max(L.first, B.first)) {
        result = abs(L.first - B.first) + abs(L.second - B.second) + 1;
    }
    else {
        result = abs(L.first - B.first) + abs(L.second - B.second) - 1;
    }

    cout << result;
}

