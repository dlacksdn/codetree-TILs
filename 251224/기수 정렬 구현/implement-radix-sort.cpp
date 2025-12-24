#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p = 1;
    for(int pos = 5; pos >= 0; pos--) {
        vector<vector<int>> arr_new(10);
        string str;
        char c;

        for(int i = 0; i < n; i++) {
            int digit = (arr[i] / p) % 10;

            arr_new[digit].push_back(arr[i]);
        }

        int index = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < arr_new[i].size(); j++) {
                arr[index++] = arr_new[i][j];
            }
        }

        p *= 10;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}