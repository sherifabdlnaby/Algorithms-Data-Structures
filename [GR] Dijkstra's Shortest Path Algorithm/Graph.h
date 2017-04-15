//
// Created by Sherif on 4/9/2017.
//

#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

#include <vector>
using namespace std;


class Graph {
private:
    vector<vector<pair<int,int>>> graph;
public:
    void addNode();
    void addEdge(int nodeA, int nodeB, int weight);
    void print();
    int size();
    vector<pair<int,int>> &operator [](int i);
};
vector<pair<int,int>> &Graph::operator[](int i) {
    return graph[i];
}

int Graph::size() {
    return graph.size();
}

void Graph::addNode() {
    graph.push_back(vector<pair<int,int>>(0));
}

void Graph::addEdge(int nodeA, int nodeB, int weight) {
    graph[nodeA].push_back(make_pair(weight,nodeB));
}

void Graph::print() {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < graph[i].size(); ++j)
            cout << graph[i][j].second << "(" << graph[i][j].first << ") - ";
        cout << endl;
    }
}


#endif //BFS_GRAPH_H
