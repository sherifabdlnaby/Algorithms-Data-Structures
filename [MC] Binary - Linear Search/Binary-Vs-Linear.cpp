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

    fstream readData("inputData.txt", ios::in);
    fstream readSearch("searchData.txt", ios::in);
    int myDataSize = 1000000;
    int *myData = new int[myDataSize]; //Search space.
    int *mySearch = new int[9999]; //Data to search for in the search space.
    int i = 0, j = 0;
    while (!readData.eof()) //Read the whole file into array.
        readData >> myData[i++];
    while (!readSearch.eof()) //Read the whole file into array.
        readSearch >> mySearch[j++];


    ///----------------------------------///

    timeStart()

    for (int i = 0; i < 10000; ++i) { //Linear search on each value in search data.
        linearSearch(myData, mySearch[i], 0, myDataSize - 1);
    }

    timeEnd("LinearSearch")

    ///----------------------------------///

    timeStart()

    for (int i = 0; i < 10000; ++i) { //Binary search on each value in search data.
        binarySearch(myData, mySearch[i], 0, myDataSize - 1);
    }

    timeEnd("Binary Search")

    ///----------------------------------///

    timeStart()

    for (int i = 0; i < 10000; ++i) { //Recursive Binary search on each value in search data.
        recursiveBinarySearch(myData, mySearch[i], 0, myDataSize - 1);
    }

    timeEnd("Recursive Binary Search")

    ///----------------------------------///


    return 0;
}