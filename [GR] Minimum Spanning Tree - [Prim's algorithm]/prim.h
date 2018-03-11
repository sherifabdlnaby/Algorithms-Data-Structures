#include <algorithm>
#include <queue>
#include "disjointsets.h"
#include "graph.h"

class Edge {
public:
    int u, v, weight;

    Edge() {}

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}

    static bool cmp(const Edge &a, const Edge &b) {
        return a.weight > b.weight;
    }
};

Graph primMSP(Graph graph) {
    //Just for Clarity
    int nodesSize = graph.size();

    //Create Disjoint Set
    DisjointSets disjointSet(nodesSize);

    //Create Adjacency List Graph that will hold the resulting MSP
    Graph MSP(nodesSize, Graph::FORCE_UNDIRECTED);

    //Priority Queue
    priority_queue<Edge, std::vector<Edge>, bool (*)(const Edge &, const Edge &)> priorityQueue(Edge::cmp);

    //Add first Node
    for (int i = 0; i < graph[0].size(); ++i) {
        priorityQueue.emplace(0, graph[0][i].destination, graph[0][i].weight);
    }

    //Start from Node 0 and build our way through.
    int MSTNodes = 0, idx = 0;
    while (MSTNodes < nodesSize - 1) {
        //Pull from queue
        Edge edge = priorityQueue.top();
        priorityQueue.pop();

        //If Non Visited node -> Union it
        if (disjointSet.Union(edge.u, edge.v)) {
            //Add Edge to MSP
            MSP.addEdge(edge.u, edge.v, edge.weight);

            //Add new Node's Edges
            for (int i = 0; i < graph[edge.v].size(); ++i)
                priorityQueue.emplace(edge.v, graph[edge.v][i].destination, graph[edge.v][i].weight);

            //Increment No. of Nodes
            ++MSTNodes;
        }
    }

    return MSP;
}



