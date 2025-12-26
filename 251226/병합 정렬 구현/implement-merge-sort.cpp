#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> merged_arr;

void merge(vector<int>& arr, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    

    while(i <= mid && j <= high) {
        if(arr[i] < arr[j]) {
            merged_arr[k] = arr[i];
            k++; i++;
        }
        else {
            merged_arr[k] = arr[j];
            k++; j++;
        }
    }

    while(i <= mid) {
        merged_arr[k] = arr[i];
        k++; i++;
    }

    while(j <= high) {
        merged_arr[k] = arr[j];
        k++; j++;
    }

    for(int l = low; l <= high; l++) {
        arr[l] = merged_arr[l];
    }

}

void merge_sort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = 0;
    int j = n - 1;
    
    merged_arr.resize(n);

    merge_sort(arr, i, j);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}