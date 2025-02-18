#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, a1, b1, a2, b2;

    cin >> x1 >> y1 >> x2 >> y2 >> a1 >> b1 >> a2 >> b2;

    if (x2 < a1 || a2 < x1 || b2 < y1 || y2 < b1) { // 안 겹침
        cout << "nonoverlapping";
    }
    else {
        cout << "overlapping";
    }
}