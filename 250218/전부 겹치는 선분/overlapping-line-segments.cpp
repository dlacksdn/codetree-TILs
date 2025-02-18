#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int max_x = 1;
    int min_y = 100;
    for (int i = 0; i < N; i++) {
        int num1, num2;
        cin >> num1 >> num2;

        if (max_x < num1)
            max_x = num1;
        if (min_y > num2)
            min_y = num2;
    }

    if (max_x <= min_y) { // 겹침
        cout << "Yes";
    }
    else
        cout << "No";
}