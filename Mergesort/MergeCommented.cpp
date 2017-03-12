#include <iostream>
#include "mergesort.h"

using namespace std;


int main() {
    int n;
    cout << "Enter the size of your array:" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    mergeSortCommented(arr, 0, n - 1);

    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl;
    return 0;
}