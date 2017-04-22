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

    tree.print();

    for (int i = 0; i < n; ++i) {
        cout << "Enter a number you want to delete" << endl;
        cin >> x;
        tree.erase(x);
        tree.print();
    }

    return 0;
}