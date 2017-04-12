#include <iostream>
#include "ToplogicalOrder.h"
using namespace std;


int main() {
    Graph graph1;              //Essentially a Vector of Vector Adjacency List.
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
    graph1.print();             //Input Graph must be DAC!

    ///RUN DFS
    vector<int> x = DFS(graph1);

    ///Print Toplogical Order (There can be different valid orders)
    cout << "Toplogical Order: ";
    for (int i = 0; i < x.size(); ++i) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}