#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    int nNodes, nEdges, nodeB, weight; //Number Of Nodes, Number of Edges for each node, nodeB in connect Edge.

    ///Fill the adjacency list.
    cout << "Enter Number of Graph's nodes: ";
    cin >> nNodes;
    Graph graph(nNodes); //Essentially a Vector of Vector Adjacency List.
    cout << "Enter the Adjacency List \"X Y Z\" (Node X -> Node Y, with weight = Z) " << endl;
    for (int nodeA = 0; nodeA < nNodes; ++nodeA) {
        cin >> nEdges;
        for (int j = 0; j < nEdges; ++j) {
            cin >> nodeB >> weight;
            graph.addEdge(nodeA,nodeB,weight);
        }
    }


    ///Sanity check for graph input.
    graph.print();


}