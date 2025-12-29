#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int select_pivot(int arr[], int low, int high) {
    int first = arr[low];
    int last = arr[high];

    int index = (low + high) / 2;
    int middle = arr[index];

    int temp = 0;

    if((first < middle && last < first) || first < last && middle < first) {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        return first;
    }

    if((last < middle && first < last) || last < first && middle < last) {
        return last;
    }

    temp = arr[index];
    arr[index] = arr[high];
    arr[high] = temp;

    return middle;
}

int partition(int arr[], int low, int high) {
    int i = low - 1;
    int pivot = select_pivot(arr, low, high);

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);

    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pos = partition(arr, low, high);

        quick_sort(arr, low, pos - 1);
        quick_sort(arr, pos + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int high = n - 1;

    quick_sort(arr, low, high);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}