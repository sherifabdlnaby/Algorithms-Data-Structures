//
// Created by Sherif on 4/9/2017.
//
#include <vector>
#include <stack>
#include <algorithm>
#include "Graph.h"
#ifndef DFS_DFS_H
#define DFS_DFS_H


void rDFS(int node, int &n, vector<int> &visited, Graph &graph1)
{
    //->No need to mark it as visited before visiting it's neighbours since it's a DAC graph.
    for (int i = 0; i < graph1[node].size(); ++i) { //Iterate over all current node edges...
        if(visited[graph1[node][i]] == -1) {        //If not visited
            rDFS(graph1[node][i], n, visited, graph1);
        }
    }
    visited[node] = n--;
    return;
}

vector<int> DFS(Graph &graph1)//Wrapper function (GRAPH MUST BE DAC)
{
    int size = graph1.size(), n = size-1; //n = No. of idxs
    vector<int> visited(size,-1);
    //Iterate over all non-visited nodes.
    for (int i = 0; i < size; ++i) {
        if(visited[i] == -1) //if not visited -> visit it;
            rDFS(i, n, visited, graph1);
    }
    //Now our visited vector has values correspond to each node's priority.
    vector<int> order(size);
    for (int i = 0; i < size; ++i) {
        order[visited[i]] = i;
    }
    return order;
}


#endif //DFS_DFS_H
