//
// Created by Sherif on 4/9/2017.
//

#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

#include <vector>
using namespace std;

class Graph {
public:
    void addNode();
    void addEdge(int nodeA, int nodeB);
    void print();
    int size();
    Graph(int size);
    Graph(){};
    vector<bool> getVisited();
    vector< vector<int> > graph;
};

int Graph::size() {
    return graph.size();
}

void Graph::addNode() {
    graph.push_back(vector<int>(0));
}

void Graph::addEdge(int nodeA, int nodeB) {
    if(nodeA == nodeB)
        return;
    graph[nodeA].push_back(nodeB);
}

void Graph::print() {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < graph[i].size(); ++j)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    cout <<"------------------------------\n" << endl;
}

vector<bool> Graph::getVisited() {
    return vector<bool> (graph.size(),false);
}

Graph::Graph(int size){
    graph.resize(size);
}


#endif //BFS_GRAPH_H
