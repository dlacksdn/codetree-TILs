#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b < c || d < a) { // 안 겹침
        cout << (b - a) + (d - c);
    }
    else {
        cout << max(b, d) - min(a, c);
    }
}