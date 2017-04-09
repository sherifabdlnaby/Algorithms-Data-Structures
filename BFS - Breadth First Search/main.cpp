#include <iostream>
#include "BFS.h"
#include "Graph.h"
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
    vector<int> ans = shortestPathBFS(start,destination,graph1); //Runs BFS and returns the shortest path
    ///


    if(ans.size()){ //If There is a path -> Print it.
        cout << "Shortest path takes: " << ans.size()-1 << " Edge(s) to reach destination" << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else {         //There is no path.
        cout << "Path not found." << endl;
    }


    return 0;
}