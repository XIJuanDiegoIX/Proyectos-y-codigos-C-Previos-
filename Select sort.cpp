#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[pos]) {
                pos = j;
            }
            swap(arr[i], arr[pos]);
        }
    }
}


int main() {
    int arr[] = {4, 37, 81, 12, 95, 6, 23, 68, 47, 76, 29, 42};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    //selectSort(arr, n);
    cout<<"Sorted array: \n";
    for(int i = 0; i < n; i++)
    cout<< arr[i] << " ";
    return 0;
}
