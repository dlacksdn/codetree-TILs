#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> m;  // 위치별 방문 횟수 기록
    vector<pair<int, char>> v(n);  // 명령 저장

    // 명령 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int index = 0;  // 현재 위치
    for (int i = 0; i < n; i++) {
        if (v[i].second == 'R') {
            // 오른쪽으로 v[i].first 만큼 이동
            for (int j = 0; j < v[i].first; j++) {
                m[index++]++;
            }
        } else if (v[i].second == 'L') {
            // 왼쪽으로 v[i].first 만큼 이동
            for (int j = 0; j < v[i].first; j++) {
                m[index--]++;
            }
        }
    }

    // 2번 이상 지나간 구역의 크기 계산
    int count = 0;
    for (const auto& pair : m) {
        if (pair.second >= 2) {
            count++;
        }
    }

    cout << count << endl;
}