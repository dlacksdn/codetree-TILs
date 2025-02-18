#include <iostream>
using namespace std;

int main() {
    int arr[101] = { 0, };

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = a; i <= b; i++) {
        arr[i]++;
    }

    for (int i = c; i <= d; i++) {
        arr[i]++;
    }

    int count = 0;
    for (int i = 0; i <= 100; i++) {
        if (arr[i] != 0) { // 청소 구역이다
            count++;
        }
    }

    cout << count - 1;
}