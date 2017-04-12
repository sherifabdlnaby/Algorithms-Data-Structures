#include <iostream>
#include "InversionCount.h"
using namespace std;

int main() {

    int n;
    cout << "Enter array size: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << countInvertCommented(arr,0,n-1) << endl;

    return 0;
}

