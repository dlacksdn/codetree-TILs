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


    for(int pos = 5; pos >= 0; pos--) {
        vector<vector<int>> arr_new(10);
        string str;
        char c;

        for(int i = 0; i < n; i++) {
            str = to_string(arr[i]);

            int size = str.size();
            for(int i = 0; i < 6 - size; i++) {
                str.insert(0, "0");
            }


            c = str[pos];
            int digit = c - '0';

            arr_new[digit].push_back(arr[i]);
        }

        vector<int> store_arr;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < arr_new[i].size(); j++) {
                store_arr.push_back(arr_new[i][j]);
            }
        }

        arr = store_arr;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}