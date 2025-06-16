#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    string str;

    while(N--) {
        int num;

        cin >> str;
        if(str == "push_back") {
            cin >> num;

            v.push_back(num);
        }
        else if(str == "get") {
            cin >> num;
            cout << v[num - 1] << "\n";
        }
        else if(str == "size") {
            cout << v.size() << "\n";
        }
        else if(str == "pop_back") {
            v.pop_back();
        }
    }

    return 0;
}