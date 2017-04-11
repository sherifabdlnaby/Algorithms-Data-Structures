#include <iostream>
#include "DFS.h"
using namespace std;


int main() {
    Graph graph1; //Essentially a Vector of Vector Adjacency List.
    int nNodes, nEdges, nodeB; //Number Of Nodes, Number of Edges for each node, nodeB in connect Edge.

    ///Fill the adjacency list.
    cin >> nNodes;
    for (int nodeA = 0; nodeA < nNodes; ++nodeA) {
        graph1.addNode();
        cin >> nEdges;
        for (int j = 0; j < nEdges; ++j) {
            cin >> nodeB;
            graph1.addEdge(nodeA,nodeB);
        }
    }
    ///Sanity check.
    graph1.print();

    ///RUN BFS
    int start; int destination; cout << "Enter Start <-> Destination..." << endl;
    cin >> start >> destination;
    int x = pathDFS(start, destination, graph1);
    cout << x << endl;

    return 0;
}