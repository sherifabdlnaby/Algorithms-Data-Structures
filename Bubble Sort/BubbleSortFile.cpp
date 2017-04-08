#include <iostream>
#include <fstream>
#include <ctime>
#include "BubbleSortLibrary.h"

using namespace std;
int start_s, stop_s;
#define timeStart() start_s=clock();
#define timeEnd(s)   stop_s=clock();cout << s << " -> Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " MS" << endl;

int main() {

    fstream inputData("inputData.txt", ios::in); //Input File
    fstream outputData("outputData.txt", ios::out); //Output file
    int sz = 10000;
    int data[10000];
    for (int i = 0; i < sz; ++i) //Read Input form file.
        inputData >> data[i];


    timeStart()
    ///////BUBBLE-SORT//////////////////////
    BubbleSort(data, 0, sz - 1);  //Bubble Sort
    ////////////////////////////////////////
    timeEnd("BubbleSort")


    for (int i = 0; i < sz; ++i) //Writing data to output file.
        outputData << data[i] << endl;
    return 0;
}
