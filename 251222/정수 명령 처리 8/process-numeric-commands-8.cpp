#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    string str;
    int num;

    cin >> num;

    while(num--) {
        cin >> str;
        int n;
        if(str == "push_back") {
            cin >> n;
            l.push_back(n);
        }
        else if(str == "push_front") {
            cin >> n;
            l.push_front(n);
        }
        else if(str == "pop_front") {
            n = l.front();
            l.pop_front();
            cout << n << "\n";
        }
        else if(str == "pop_back") {
            n = l.back();
            l.pop_back();
            cout << n << "\n";
        }
        else if(str == "size") {
            cout << l.size() << "\n";
        }
        else if(str == "empty") {
            cout << l.empty() << "\n";
        }
        else if(str == "front") {
            cout << l.front() << "\n";
        }
        else if(str == "back") {
            cout << l.back() << "\n";
        }
    }
    return 0;
}