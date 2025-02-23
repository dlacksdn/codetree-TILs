#include <iostream>
#include <vector>
using namespace std;

int process(int A, int B, int C) {
    if (A == B && B == C) { // 셋 다 명예의 전당
        return 6;
    }
    else if (B == C) {
        return 5;
    }
    else if (A == C) {
        return 4;
    }
    else if (A == B) {
        return 3;
    }
    else if (C > A && C > B) {
        return 2;
    }
    else if (B > A && B > C) {
        return 1;
    }
    else {
        return 0;
    }
    
   
}

int main() {
    int N;
    cin >> N;

    vector<pair<char, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int prev = 6;
    int A = 0, B = 0, C = 0;

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].first == 'A')
            A += v[i].second;

        else if (v[i].first == 'B')
            B += v[i].second;

        else
            C += v[i].second;

        int present = process(A, B, C);

        if (prev != present) {
            count++;
        }

        prev = present;
    }

    cout << count;
}