#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    list<char> l;
    for(int i = 0; i < n; i++) {
        l.push_back(str[i]);
    }

    list<char> :: iterator it;
    it = l.end();

    while(m--) {
        char c;
        cin >> c;

        if(c == 'L') {
            if(it != l.begin()) 
                it--;
        }
        else if(c == 'R') {
            if(it != l.end())
                it++;
        }
        else if(c == 'D') {
            if(it != l.end()) {
                it = l.erase(it);
            }
        }
        else if(c == 'P') {
            cin >> c;
            l.insert(it, c);
        }
    }

    for(it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }

    return 0;
}