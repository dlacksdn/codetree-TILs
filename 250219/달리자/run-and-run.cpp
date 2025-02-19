#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> origin(N);
    vector<int> change(N);

    for (int i = 0; i < N; i++) {
        cin >> origin[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> change[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        int num = origin[i] - change[i];

        if (num > 0) {
            origin[i] -= num;
            origin[i + 1] += num;
            count += num;
        }
    }

    cout << count;
}