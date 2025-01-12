#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; // 장비 개수
    int C, G, H; // 작업량

    cin >> N >> C >> G >> H;

    vector<pair<int, int>> devices(N);
    int TaMin = 1000;
    int TbMax = 0;

    for (auto& device : devices) {
        cin >> device.first >> device.second;

        if (device.first < TaMin) TaMin = device.first;
        if (device.second > TbMax) TbMax = device.second;
    }

    // 온도 범위 설정 시 TaMin - 1이 음수가 되지 않도록 조정
    int startTemp = (TaMin > 0) ? (TaMin - 1) : 0;
    int endTemp = (TbMax < 1000) ? (TbMax + 1) : 1000;

    int maxWork = 0;
    for (int temp = startTemp; temp <= endTemp; temp++) {
        int currentWork = 0;
        for (const auto& device : devices) {
            if (temp < device.first) {
                currentWork += C;
            }
            else if (device.first <= temp && temp <= device.second) {
                currentWork += G;
            }
            else {
                currentWork += H;
            }
        }
        if (currentWork > maxWork) {
            maxWork = currentWork;
        }
    }
    
    cout << maxWork;
}
