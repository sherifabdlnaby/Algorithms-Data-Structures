#include <iostream>
#include "node.h"
using namespace std;

int main() {
    LinkedList x;
    x.addFirst(1);
    x.addFirst(2);
    x.addFirst(3);
    x.addBack(6);
    x.addBack(5);
    x.print();
    return 0;
}