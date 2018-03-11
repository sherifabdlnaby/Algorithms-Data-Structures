#include <iostream>
#include "disjointsets.h"
#include "prim.h"

using namespace std;

int main()
{
    Graph inputGraph;                   //Essentially a Vector of Vector Adjacency List.
    int nNodes, nEdges, nodeB, weight;  //Number Of Nodes, Number of Edges for each node, nodeB in connect Edge.

    ///Fill the adjacency list.
    cin >> nNodes;
    for (int nodeA = 0; nodeA < nNodes; ++nodeA) {
        inputGraph.addNode();
        cin >> nEdges;
        for (int j = 0; j < nEdges; ++j) {
            cin >> nodeB >> weight;
            inputGraph.addEdge(nodeA,nodeB,weight);
        }
    }

    inputGraph.print();

    //RUN Prim
    Graph MSP = primMSP(inputGraph);

    //Print MPS Adjacency List
    MSP.print();

    return 0;
}