#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process {
public:
    string name;
    int height;
    int weight;

    Process(string nm, int hei, int wei) {
        name = nm;
        height = hei;
        weight = wei;
    }
    Process() {}
};

bool isValue(Process left,  Process right) {
    return left.height < right.height;
}

int main() {
    int n;
    cin >> n;

    vector<Process> arr(n);
    string name;
    int height;
    int weight;
    for (int i = 0; i < n; i++) {
        cin >> name >> height >> weight;
        arr[i] = Process(name, height, weight);
    }

    sort(arr.begin(), arr.end(), isValue);
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " " << arr[i].height << " " << arr[i].weight << "\n";
    }


    return 0;
}