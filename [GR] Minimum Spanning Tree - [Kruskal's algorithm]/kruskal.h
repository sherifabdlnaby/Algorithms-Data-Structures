#include <algorithm>
#include "disjointsets.h"
#include "graph.h"

class Edge {
public:
    int u, v, weight;

    Edge() {}

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}

    static bool cmp(const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    }
};

Graph kruskalMSP(int nodesSize, vector<Edge> edgesList) {

    //Sort Edges
    std::sort(edgesList.begin(), edgesList.end(), Edge::cmp);

    //Create Disjoint Set
    DisjointSets set(nodesSize);

    //Create Adjacency List Graph that will hold the resulting MSP
    Graph MSP(nodesSize, Graph::FORCE_UNDIRECTED);

    //Start Greed
    int MSTNodes = 0, idx = 0;
    while (MSTNodes < nodesSize - 1) {
        Edge *edge = &edgesList[idx++];

        //Check if Edge doesn't form a cycle.
        if (set.Find(edge->u) != set.Find(edge->v)) {
            //Connect It
            set.Union(edge->u, edge->v);

            //Add Edge to MSP
            MSP.addEdge(edge->u, edge->v, edge->weight);

            //Increment No. of Nodes
            ++MSTNodes;
        }
    }

    return MSP;
}



