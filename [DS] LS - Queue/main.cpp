#include "queue.h"
using namespace std;
int main() {
    queue<int> x;
    ///////////////////////////////////
    x.push(2);   x.print();
    x.push(3);   x.print();
    x.push(4);   x.print();
    x.push(5);   x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    x.push(13);  x.print();
    x.push(14);  x.print();
    x.push(315); x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    x.pop();     x.print();
    return 0;
}