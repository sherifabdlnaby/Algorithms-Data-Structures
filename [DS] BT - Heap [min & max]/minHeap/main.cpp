#include <iostream>
#include "heap.h"
using namespace std;
int main() {
    int n;
    cout << "Enter The number of elements.." << endl;
    cin >> n;
    vector<int> vector1(n);
    cout << "Enter The elements..." << endl;
    for (int i = 0; i < n; ++i) {
        cin >> vector1[i];
    }


    ///Using buildHeap(Constructor) [Faster than inserting one by one if data already exist] O{n}
    heap h(vector1);
    cout << "Using buildHeap: ";
    for (int i = 0; i < n; ++i) {
        cout << h.top() << " ";
        h.pop();
    }


    ///Re-insertiong vector one by one. O{nLogn} // O{logn} for each inserion
    for (int i = 0; i < n; ++i) {
        h.insert(vector1[i]);
    }

    cout << endl << "Using Insertion: ";
    for (int i = 0; i < n; ++i) {
        cout << h.top() << " ";
        h.pop();
    }

    return 0;
}