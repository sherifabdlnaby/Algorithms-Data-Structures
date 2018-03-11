#include <vector>
#include <iostream>

using namespace std;

class adjEdge {
public:
    int destination;
    int weight;

    adjEdge(int destination, int weight) : destination(destination), weight(weight) {}

    adjEdge() {}
};

/*
 * Use FORCE_UNDIRECTED flag when constructing the object to handle undirected input,
 * so that if edge from X to Y is added, an edge from Y to X is also added to the adjacency list
 * (usually problems input is directed so if (X -> Y) another input must exist to make (Y -> X )so that the graph is undirected)
 * */

class Graph {
private:
    vector<vector<adjEdge>> graph;
public:
    enum Flag {
        DIRECTED = 0, FORCE_UNDIRECTED = 1
    };
    Flag flag;

    Graph(int size = 0, Flag = DIRECTED);

    void addNode();

    void addEdge(int nodeA, int nodeB, int weight);

    void print();

    int size();

    vector<adjEdge> &operator[](int i);
};

vector<adjEdge> &Graph::operator[](int i) {
    return graph[i];
}

int Graph::size() {
    return graph.size();
}

void Graph::addNode() {
    graph.push_back(vector<adjEdge>(0));
}

void Graph::addEdge(int nodeA, int nodeB, int weight) {
    graph[nodeA].push_back(adjEdge(nodeB, weight));
    if (flag == FORCE_UNDIRECTED)
        graph[nodeB].push_back(adjEdge(nodeA, weight));
}

void Graph::print() {
    for (int i = 0; i < graph.size(); ++i) {
        std::cout << "Edge " << i << ": ";
        for (int j = 0; j < graph[i].size(); ++j)
            std::cout << graph[i][j].destination << " W(" << graph[i][j].weight << ")"
                      << (j < graph[i].size() - 1 ? " - " : "");
        std::cout << endl;
    }
}

Graph::Graph(int size, Flag flag) : flag(flag) {
    graph = vector<vector<adjEdge>>(size, vector<adjEdge>(0));
}
