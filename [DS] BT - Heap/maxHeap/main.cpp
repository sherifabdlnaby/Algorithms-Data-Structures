#include <iostream>
#include "heap.h"
using namespace std;

bool customCmp(int X, int Y)
{
    return X > Y;
}


int main() {
    int n;
    cout << "Enter The number of elements.." << endl;
    cin >> n;
    vector<int> vector1(n);

    cout << "Enter The elements..." << endl;
    for (int i = 0; i < n; ++i) {
        cin >> vector1[i];
    }



    cout << endl << "==== Using Default Cmp ====" << endl;

    ///Using buildHeap(Constructor) [Faster than inserting one by one if data already exist] O{n}
    heap<int> heap1(vector1);
    cout << "Using buildHeap: ";
    for (int i = 0; i < n; ++i) {
        cout << heap1.top() << " ";
        heap1.pop();
    }

    ///Re-insertion vector one by one. O{nLogn} // O{logn} for each insertion
    for (int i = 0; i < n; ++i) {
        heap1.insert(vector1[i]);
    }

    cout << endl << "Using Insertion: ";
    for (int i = 0; i < n; ++i) {
        cout << heap1.top() << " ";
        heap1.pop();
    }


    cout  << endl << "==== Using Custom Cmp ====" << endl;

    ///Using buildHeap(Constructor) [Faster than inserting one by one if data already exist] O{n}
    heap<int> heap2(vector1, customCmp);
    cout << "Using buildHeap: ";
    for (int i = 0; i < n; ++i) {
        cout << heap2.top() << " ";
        heap2.pop();
    }

    ///Re-insertiong vector one by one. O{nLogn} // O{logn} for each inserion
    for (int i = 0; i < n; ++i) {
        heap2.insert(vector1[i]);
    }

    cout << endl << "Using Insertion: ";
    for (int i = 0; i < n; ++i) {
        cout << heap2.top() << " ";
        heap2.pop();
    }

    return 0;
}