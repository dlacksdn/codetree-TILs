#include <iostream>
#include <vector>
using namespace std;

const int MAX_POS = 100;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> segments(n);
    vector<vector<int>> coverage(n, vector<int>());
    vector<int> totalCoverage(MAX_POS + 1, 0);

    // 입력 및 커버리지 저장
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
        for (int pos = segments[i].first; pos <= segments[i].second; pos++) {
            coverage[i].push_back(pos);
            totalCoverage[pos]++;
        }
    }

    int validCombinations = 0;

    // 모든 3개 선분 조합 검사
    for (int seg1 = 0; seg1 < n; seg1++) {
        for (int seg2 = seg1 + 1; seg2 < n; seg2++) {
            for (int seg3 = seg2 + 1; seg3 < n; seg3++) {
                bool isValid = true;

                // 선분 seg1, seg2, seg3 제거
                for (auto pos : coverage[seg1]) {
                    if (--totalCoverage[pos] >= 2) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    for (auto pos : coverage[seg2]) {
                        if (--totalCoverage[pos] >= 2) {
                            isValid = false;
                            break;
                        }
                    }
                }
                if (isValid) {
                    for (auto pos : coverage[seg3]) {
                        if (--totalCoverage[pos] >= 2) {
                            isValid = false;
                            break;
                        }
                    }
                }

                // 카운트 복구
                for (auto pos : coverage[seg1]) totalCoverage[pos]++;
                for (auto pos : coverage[seg2]) totalCoverage[pos]++;
                for (auto pos : coverage[seg3]) totalCoverage[pos]++;

                // 유효한 조합인 경우
                if (isValid) validCombinations++;
            }
        }
    }

    cout << validCombinations;

    return 0;
}
