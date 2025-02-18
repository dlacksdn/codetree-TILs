#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b < c || d < a) { // 안 겹침
        cout << "nonintersecting";
    }
    else
        cout << "intersecting";
}