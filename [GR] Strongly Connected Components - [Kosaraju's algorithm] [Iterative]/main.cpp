#include <iostream>
#include "SCC.h"
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    int nNodes = 875714, int a,b; //Number Of Nodes, nodeA, nodeB;
    fstream data("data.txt", ios::in);
    ///Fill the adjacency list.
    cout << "Enter The adjacency list... (see attached example)" << endl;

    Graph graph1(nNodes); //Essentially a Vector of Vector Adjacency List.

    ///THIS IS A SPECIFED HARDCODED VALUES TO MATCH THE data.txt INPUT FILE(#TODO cleanup/refactor).
    for (int i = 0; i < 5105043; ++i) {
            data >> a; data >> b;
        graph1.addEdge(a,b);
    }

    ///RUN Kosaraju's algorithm for Strongly Connected Components.
    vector<vector<int>> x = SCC(graph1);

    ///Print Results (Sort them for extracting ALGO1-Stanford questions answer)
    fstream out("out.txt", ios::out);
    for (int i = 0; i < x.size(); ++i) {
        out << x[i].size() << ": ";
        for (int j = 0; j < x[i].size(); ++j) {
            out << x[i][j] << " ";
        }
        out << endl;
    }
    return 0;
}