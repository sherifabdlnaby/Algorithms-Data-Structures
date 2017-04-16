//
// Created by Sherif on 4/9/2017.
//

#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

#include <vector>
using namespace std;

struct edge
{
    int num;    //neighbour node number;
    int weight; //cost for such node;
};

struct node
{
    int num;    //node number;
    vector<edge> neighbour; //all edges;
    node(int num):num(num){};
};

class Graph {
private:
    vector<node> graph;
public:
    void addNode(node node1);
    void addEdge(int nodeA, int nodeB, int weight);
    void print();
    int size(){ return graph.size(); }
    vector<edge> &operator [](int i){ return graph[i].neighbour; }
    node &getNode(int i) { return graph[i]; }
};


void Graph::addNode(node node1) {
    graph.push_back(node1);
}

void Graph::addEdge(int nodeA, int nodeB, int weight) {
    (*this)[nodeA].push_back({nodeB,weight});
}

void Graph::print() {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < graph[i].neighbour.size(); ++j)
            cout << graph[i].neighbour[j].num << "(" << graph[i].neighbour[j].weight << ") - ";
        cout << endl;
    }
}


#endif //BFS_GRAPH_H
