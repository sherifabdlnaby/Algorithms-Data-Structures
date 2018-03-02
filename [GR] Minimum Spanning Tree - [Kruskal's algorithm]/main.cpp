#include <iostream>
#include "disjointsets.h"
#include "kruskal.h"

using namespace std;

int main()
{
    int nVertices,nEdges;
    cout << "Enter Number of Graph's nodes followed by Number of Graph's edges" << endl;
    cin >> nVertices >> nEdges;
    vector<Edge> edgesList(nEdges);

    //Takes Edges Input
    cout << "Enter n Edges with triplet format \"X Y Z\" (Node X -> Node Y, with weight = Z) " << endl;
    for (int i = 0; i < nEdges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edgesList[i] = Edge(u, v, w);
    }

    //RUN kruskal
    Graph MSP = kruskalMSP(nVertices,edgesList);

    //Print MPS Adjacency List
    MSP.print();

    return 0;
}