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
    for (int i = N - 1; i >= 1; i--) { // i : 인원수를 채워야하는 인덱스
        int goal = change[i] - origin[i]; // 부족한 인원 수

        for (int j = i - 1; j >= 0; j--) { // 인원을 끌어오는 인덱스
            int need = goal - origin[j]; // 해당 인덱스에서 인원채용이 끝나는지 판정하는데 도움을 주는 변수

            if (need <= 0) { // j인덱스 선에서 인원 채용이 끝남
                origin[i] += goal;
                origin[j] -= goal;

                count += (i - j) * goal;
                break;
            }
            else {
                origin[i] += origin[j];
                count += (i - j) * origin[j];

                goal -= origin[j];
                origin[j] = 0;
            }
        }
    }

    cout << count;
}