#include <iostream>
#include "UDCC.h"
using namespace std;


int main() {
    Graph graph1; //Essentially a Vector of Vector Adjacency List.
    int nNodes, nEdges, nodeB; //Number Of Nodes, Number of Edges for each node, nodeB in connect Edge.

    ///Fill the adjacency list.
    cout << "Fill the Adjacency List... (use attached examples)" << endl;
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

    ///Run UDCC
    vector< vector<int> > objects = UDCC(graph1); //Undirected Connected Components

    ///Print Results
    for (int i = 0; i < objects.size(); ++i) {
        cout << "Object " << i << ": ";
        for (int j = 0; j < objects[i].size(); ++j) {
            cout << objects[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}