#include <iostream>
#include <iomanip>
#include "Dijkstra.h"
using namespace std;


int main() {
    Graph graph1; //Essentially a Vector of Vector Adjacency List.
    int nNodes, nEdges, nodeB, weight; //Number Of Nodes, Number of Edges for each node, nodeB in connect Edge.

    ///Fill the adjacency list.
    cin >> nNodes;
    for (int nodeA = 0; nodeA < nNodes; ++nodeA) {
        graph1.addNode();
        cin >> nEdges;
        for (int j = 0; j < nEdges; ++j) {
            cin >> nodeB >> weight;
            graph1.addEdge(nodeA,nodeB,weight);
        }
    }


    ///Sanity check for graph input.
    graph1.print();


    ///RUN Dijkstra
    int start, destination;
    cout << "Enter Start / Destination" << endl;
    cin >> start >> destination;


    ///Single distance between start -> destination;
    cout << "----------------Dijkstra-----------------" << endl;
    cout << "Distance from " << start << " to " << destination << ": " << dijkstra(start,destination,graph1) << endl;


    ///Path from start -> destination;
    cout << "--------------dijkstraPath---------------" << endl;
    vector<int> path = dijkstraPath(start,destination,graph1);
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " -> ";
    }
    cout << "end" << endl;


    ///All shortest path distance between start and all nodes;
    cout << "------------dijkstraAllNodes-------------" << endl;
    vector<int> allNodes = dijkstraAllNodes(start, graph1);
    for (int i = 0; i < allNodes.size(); ++i) {
        if(allNodes[i] == INF)
            cout << "(" << i << ", NO PATH)" << " , ";
        else
            cout << "(" << i << ", " << allNodes[i] << ")" << " , ";
    }
    cout << endl;


    ///Shortest path between all nodes and Start;
    cout << "----------dijkstraAllNodesPath-----------" << endl;
    vector<pair<int,int>> allPaths = dijkstraAllNodesPath(start,graph1);
    for (int i = 0; i < allPaths.size(); ++i) {
        int j = i;
        cout << "From node " << start << " to node " << j << ": " << j << " <- ";
        while(allPaths[j].second != -1)
        {
            cout << allPaths[j].second  <<" <- ";
            j = allPaths[j].second; //iterate..
        }
        if(allPaths[i].first == INF)
            cout << "Start" << " (Distance: NO PATH)" << endl;
        else
            cout << "Start" << " (Distance: " << allPaths[i].first << ")" << endl;
    }
    return 0;
}