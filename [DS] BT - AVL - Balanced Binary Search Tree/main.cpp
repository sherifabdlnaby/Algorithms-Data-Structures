#include <iostream>
#include "AVL.h"
using namespace std;
int main() {

    AVL tree;
    int x, n;

    cout << "Enter the number of Nodes" << endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter Node No. " << i+1 << " ..." << endl;
        cin >> x;
        tree.insert(x);
    }

    tree.printInOrder();

    return 0;
}