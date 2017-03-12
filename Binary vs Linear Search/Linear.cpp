//
// Created by Sherif on 3/3/2017.
//
#include <iostream>
#include <fstream>
#include <ctime>
#include "BinaryLinearSearchLibrary.h"

int start_s;
int stop_s;
#define timeStart() start_s=clock();
#define timeEnd(s)   stop_s=clock();cout << s << " -> Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " MS" << endl;
using namespace std;
int main() {

    fstream readData("data.txt", ios::in); //Search space.
    int myDataSize = 1000000;
    int *myData = new int[1000000];
    int myInput = 509099;
    int i = 0;
    while (!readData.eof()) //Read the whole file.
        readData >> myData[i++];


    ///----------------------------------///

    timeStart()

    if( binarySearch(myData, myInput, 0, myDataSize-1) )
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    timeEnd("BinarySearch")

    ///----------------------------------///

    return 0;
}