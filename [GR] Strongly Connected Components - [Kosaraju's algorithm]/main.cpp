#include <iostream>
#include "SCC.h"
using namespace std;


int main() {
    Graph graph1; //Essentially a Vector of Vector Adjacency List.
    int nNodes, nEdges, nodeB; //Number Of Nodes, Number of Edges for each node, nodeB in connect Edge.

    ///Fill the adjacency list.
    cout << "Enter The adjacency list... (see attached example)" << endl;
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

    ///RUN Kosaraju's algorithm for Strongly Connected Components.
    vector<vector<int>> x = SCC(graph1);

    ///Prints Results
    cout << "Total of " << x.size() << " Strongly Connected Components" << endl;
    for (int i = 0; i < x.size(); ++i) {
        cout << "Object " << i+1 << ": ";
        for (int j = 0; j < x[i].size(); ++j) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}