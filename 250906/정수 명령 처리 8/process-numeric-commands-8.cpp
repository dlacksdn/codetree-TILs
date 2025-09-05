#include <iostream>
#include <list>
using namespace std;

int main() {
    int N;
    cin >> N;

    list<int> L;

    while(N--) {
        string str;
        cin >> str;

        int num;
        if (str == "push_front") {
            cin >> num;
            L.push_front(num);
        }
        if (str == "push_back") {
            cin >> num;
            L.push_back(num);
        }
        if (str == "pop_front") {
            cout << L.front() << "\n";
            L.pop_front();
        }
        if (str == "pop_back") {
            cout << L.back() << "\n";
            L.pop_back();
        }
        if (str == "size") {
            cout << L.size() << "\n";
        }
        if (str == "empty") {
            cout << L.empty() << "\n";
        }
        if (str == "front") {
            cout << L.front() << "\n";
        }
        if (str == "back") {
            cout << L.back() << "\n";
        }
    }
    return 0;
}