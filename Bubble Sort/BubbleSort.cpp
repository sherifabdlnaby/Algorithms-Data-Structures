#include <iostream>
#include "BubbleSortLibrary.h"
using namespace std;

int main() {

    int sz;
    cin >> sz;
    int data[sz];
    for (int i = 0; i < sz; ++i) { //Input Data
        cin >> data[i];
    }

    ///////BUBBLE-SORT//////////////////////
    BubbleSort(data,0,sz-1);  //Bubble Sort
    ////////////////////////////////////////

    for (int i = 0; i < sz; ++i) { //Output Array
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
