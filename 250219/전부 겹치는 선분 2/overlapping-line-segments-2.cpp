#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    

    vector<int> x(N);
    vector<int> y(N);

    int num1, num2;
    for (int i = 0; i < N; i++) {
        cin >> num1 >> num2;

        x[i] = num1;
        y[i] = num2;
    }

    for (int i = 0; i < N; i++) { // i : 어떤 인덱스를 제외시킬 것인가?
        int max_x = 1;
        int min_y = 100;

        for (int j = 0; j < N; j++) { // j : 벡터 x, y를 순회하는 인덱스
            if (i != j) {
                if (max_x < x[j])
                    max_x = x[j];
                if (min_y > y[j])
                    min_y = y[j];
            }
        }

        if (max_x <= min_y) { // 겹침
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

    
}

// 하나 씩 빼야하니까 배열에 기록을 해야 함