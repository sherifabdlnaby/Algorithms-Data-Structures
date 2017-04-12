//
// Created by Sherif on 4/9/2017.
//

#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

#include <vector>
using namespace std;

class Graph {
private:
    vector< vector<int> > graph;
public:
    void addNode();
    void addEdge(int nodeA, int nodeB);
    void print();
    int size();
    vector<bool> getVisited();
    vector<int> &operator [](int i);
};


#endif //BFS_GRAPH_H
