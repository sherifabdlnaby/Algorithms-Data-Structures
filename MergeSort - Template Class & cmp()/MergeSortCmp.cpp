#include <iostream>
#include <fstream>
#include <ctime>
#include "merge.h"
using namespace std;
int start_s;
int stop_s;
#define timeStart() start_s=clock();
#define timeEnd(s)   stop_s=clock();cout << s << " -> Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " MS" << endl;
bool cmp(int i, int j)
{
    return i < j;
}

int main() {
    fstream inputData("inputData.txt", ios::in);
    fstream outputData1("outputData1.txt", ios::out);
    fstream outputData2("outputData2.txt", ios::out);
    int  myDataSize = 100000;
    int *myData1 = new int[myDataSize];
    int *myData2 = new int[myDataSize];
    int i = 0;
    while (!inputData.eof())
    {
        inputData >> myData1[i];
        myData2[i] = myData1[i++];
    }

    timeStart();
    mergeSort(myData1, 0, myDataSize-1);
    timeEnd("Merge   ");

    timeStart();
    mergeSortOpt(myData2, 0, myDataSize-1);
    timeEnd("MergeOpt");

    for (int j = 0; j < myDataSize; ++j) //Writing Data to output files
    {
        outputData1 << myData1[j] << endl;
        outputData2 << myData2[j] << endl;
    }
    cout << "Data Written to Output Files Successfully !" << endl;
    return 0;
}