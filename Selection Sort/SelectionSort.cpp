#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr) {
    int minIdx;
    for (int i = 0; i < arr.size(); ++i) {
        minIdx = i;
        for (int j = i; j < arr.size(); ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    selectionSort(arr);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}