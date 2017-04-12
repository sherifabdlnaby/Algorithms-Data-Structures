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


vector<int> &Graph::operator[](int i) {
    return graph[i];
}

int Graph::size() {
    return graph.size();
}

void Graph::addNode() {
    graph.push_back(vector<int>(0));
}

void Graph::addEdge(int nodeA, int nodeB) {
    graph[nodeA].push_back(nodeB);
}

void Graph::print() {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < graph[i].size(); ++j)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}

vector<bool> Graph::getVisited() {
    return vector<bool> (graph.size(),false);
}


#endif //BFS_GRAPH_H
