#include <iostream>
#include "InversionCount.h"

using namespace std;


int main() {

    int n;
    cout << "Enter Array Size:" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter The Array:" << endl;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << countInvert(arr, 0, n - 1) << endl;

    return 0;
}

