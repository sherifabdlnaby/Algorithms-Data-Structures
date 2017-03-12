//<editor-fold desc="">
#include <iostream>
#include <fstream>
#include <ctime>
#include "Insert.h"
using namespace std;
int start_s;
int stop_s;
#define timeStart() start_s=clock();
#define timeEnd(s)   stop_s=clock();cout << s << " -> Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " MS" << endl;
//</editor-fold>

int main() {
    int sz = 10000;
    int *data1 = new int[sz]; //To store data read from file
    int *data2 = new int[sz]; //---------------------------//
    fstream inputData("inputData.txt",  ios::in);
    fstream outputData("outputData.txt",ios::out);
    for (int i = 0; i < sz; ++i){ //Read data from file to data1 Array, And copy it to data2 Array
        inputData >> data1[i];
        data2[i] = data1[i];
    }

    timeStart()
    insertionSort(data1,0,sz-1);
    timeEnd("Insertion Shift")

    timeStart()
    insertionSortSwap(data2,0,sz-1);
    timeEnd("Insertion Swap")

    for (int i = 0; i < sz; ++i)
        outputData << data1[i] << endl;

    return 0;
}

