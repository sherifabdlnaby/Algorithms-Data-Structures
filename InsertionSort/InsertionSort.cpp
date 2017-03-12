//<editor-fold desc="">
#include <iostream>
#include <ctime>
#include "Insert.h"
using namespace std;
int start_s;
int stop_s;
#define timeStart() start_s=clock();
#define timeEnd(s)   stop_s=clock();cout << s << " -> Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " MS" << endl;
//</editor-fold>

int main() {
    int n;
    cout << "Enter the size of your array:" << endl;
    cin >> n;
    int data[n];
    cout << "Enter the array:" << endl;
    for (int i = 0; i < 6; ++i)
        cin >> data[i];

    timeStart()
    insertionSort(data,0,n-1);
    insertionSortSwap(data,0,n-1);
    timeEnd("Insertion Sort")

    printArr(data,n);

    return 0;
}


