#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }

    for (int i = pow(10, n - 1); i < pow(10, n); i++) {
        string str = to_string(i);
        unordered_set<char> s(str.begin(), str.end());

        if (str.size() == s.size()) { // true면 중복이 없는 것
            bool flag = true;

            for (int j = 0; j < n - 1; j++) {
                int num1 = str[j] - '0';
                int num2 = str[j + 1] - '0';
               
                if (num1 + num2 != v[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                for (int j = 0; j < str.size(); j++) {
                    cout << str[j] << " ";
                }
                break;
            }
        }
    }
}