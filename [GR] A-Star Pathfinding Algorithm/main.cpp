#include <iostream>
#include <iomanip>
#include "A-star.h"
using namespace std;


int main() {
    Graph graph1; //Essentially a Vector of Vector Adjacency List.
    int nNodes, nEdges, nodeB, weight; //Number Of Nodes, Number of Edges for each node, nodeB in connect Edge.

    ///Fill the adjacency list.
    cin >> nNodes;
    for (int nodeA = 0; nodeA < nNodes; ++nodeA) {
        graph1.addNode( node(nodeA) ); //Add a node of num = nodeA;
        cin >> nEdges;
        for (int j = 0; j < nEdges; ++j) {
            cin >> nodeB >> weight;
            graph1.addEdge(nodeA,nodeB,weight);
        }
    }


    ///Sanity check for graph input.
    graph1.print();


    ///RUN A*
    int start, destination;
    cout << "Enter Start / Destination" << endl;
    cin >> start >> destination;


    ///Single distance between start -> destination;
    cout << "--------------  A* -----------------" << endl;
    cout << "Distance from " << start << " to " << destination << ": " << a_star(start, destination, graph1) << endl;


    ///Path from start -> destination;
    cout << "--------------A* Path---------------" << endl;
    vector<int> path = a_starPath(start, destination, graph1);
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " -> ";
    }
    cout << "end" << endl;



}
