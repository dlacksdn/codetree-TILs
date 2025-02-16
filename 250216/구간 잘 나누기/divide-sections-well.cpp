#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list; // 문제에서 주어진 수열
int n; // 숫자 범위
int m; // 숫자 개수 

void process(vector<int>& v, int& result) {
    int sum = 0;
    int index = 0;
    int max_num = 0;
    for (int i = 0; i < n; i++) { // i : list를 쭉 순회하는 인덱스
        sum += list[i];

        if (v.size() != index && i == v[index]) { // 현 list의 인덱스가 칸막이까지 온 상황
            index++;
            max_num = max(max_num, sum);
            sum = 0;
        }
    }

    max_num = max(max_num, sum);

    result = min(result, max_num);
}

void backTracking(vector<int>& v, int start, int range, int size, int& result) {
    if (v.size() == size) {
        process(v, result);
        return;
    }

    for (int i = start; i <= range; i++) {
        v.push_back(i);
        backTracking(v, i + 1, range, size, result);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.push_back(num);
    }

    int result = 100;
    vector<int> vec;

    backTracking(vec, 0, n, m - 1, result);

    cout << result;
}