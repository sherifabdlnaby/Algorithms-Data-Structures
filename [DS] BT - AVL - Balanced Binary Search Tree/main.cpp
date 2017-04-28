#include <iostream>
#include "AVL.h"
using namespace std;
int main() {

    AVL tree;
    int x, n;

    cout << "Enter the number of nodes" << endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        tree.insert(x);
    }

    tree.printInOrder();

    return 0;
}