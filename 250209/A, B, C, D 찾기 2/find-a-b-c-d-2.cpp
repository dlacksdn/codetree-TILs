#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(15);

    for (int i = 0; i < 15; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int max_num = v[14];

    for (int A = 0; A <= 14; A++) {
        for (int B = A+1; B <= 14; B++) {
            for (int C = B+1; C <= 14; C++) {
                for (int D = C+1; D <= 14; D++) {
                    
                    if (v[A] + v[B] + v[C] + v[D] == max_num) {

                        if (find(v.begin(), v.end(), v[A] + v[B]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[B] + v[C]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[C] + v[D]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[D] + v[A]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[A] + v[C]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[B] + v[D]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[A] + v[B] + v[C]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[A] + v[B] + v[D]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[A] + v[C] + v[D]) == v.end()) continue;
                        if (find(v.begin(), v.end(), v[B] + v[C] + v[D]) == v.end()) continue;

                        cout << v[A] << " " << v[B] << " " << v[C] << " " << v[D];
                        return 0;
                    }
                }
            }
        }
    }
}