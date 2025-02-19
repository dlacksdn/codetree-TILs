#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(11, 2); // 0: 왼쪽, 1: 오른쪽, 2: 언급이 안 됨

    int count = 0;
    for (int i = 0; i < N; i++) {
        int index, num;
        cin >> index >> num;

        if (v[index] == 2) { // 입력받은 비둘기가 언급 된 적이 없다
            v[index] = num;
        }
        else if (v[index] != num) { // 비둘기가 위치를 옮김
            count++;
            v[index] = num;
        }
    }

    cout << count;
}