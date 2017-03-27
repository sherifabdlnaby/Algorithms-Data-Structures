#include <iostream>
#include <algorithm>
#include <ctime>
#include "QuickSort.h"
int start_s,stop_s; //Time holders;
#define timeStart() start_s=clock();
#define timeEnd(s)  stop_s=clock(); cout << s << " -> Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " MS" << endl;

int main() {
    srand(time(NULL));

    unsigned int sz;
    cout << "Enter the size of the list: " << endl;
    cin >> sz;
    vector<int> data1(sz),data2(sz),data3(sz),data4(sz);

    cout << "Generating Random Data of size: " << sz << "..." << endl;
    for (int i = 0; i < sz; ++i) {
        data1[i] = rand()%10000000;
        data2[i] = data3[i] = data4[i] = data1[i];
    }

    timeStart();
    quickSort(data1, 0, sz-1);
    timeEnd("QuickSort\t\t");

    timeStart();
    quickSortNoSkip(data2, 0, sz-1);
    timeEnd("QuickSortNoSkip\t\t");

    timeStart();
    sort(data3.begin(), data3.end());
    timeEnd("STL-Sort\t\t");

    timeStart();
    quickSortNaive(data4,0,sz-1);
    timeEnd("Naive-Sort\t\t");

    if(sz > 30000)
        cout << "->>>>> Naive Q-Sort worst case is n^2, your n is > 30000, this will take a significant time..." << endl;

    sort(data4.begin(),data4.end(), greater<int>()); //sort descending to demonstrate worst case scenario.
    timeStart();
    quickSortNaive(data4,0,sz-1);
    timeEnd("Naive-Q-Sort(WorstCase)\t");


    return 0;
}