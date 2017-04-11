//
// Created by Sherif on 4/9/2017.
//
#include <vector>
#include <stack>
#include <algorithm>
#include "Graph.h"

#ifndef DFS_DFS_H
#define DFS_DFS_H

bool recDFS(int node, Graph &graph1, vector<bool> &visited)      //Runs DFS (Modify it to your needs)
{
    visited[node] = true;
    for (int i = 0; i < graph1[node].size(); ++i) { //Iterate over all current node edges.
        if(!visited[graph1[node][i]]) {             //If not visited -> recurse
            recDFS(graph1[node][i], graph1, visited);
        }
    }
    return true;
}


bool rDFS(int curr, int destination, Graph &graph1)     //Wrapper function
{
    vector<bool> visited = graph1.getVisited();
    recDFS(curr,graph1,visited);
    return true;
}


int recPDFS(int node, int destination, Graph &graph1, vector<bool> &visited, int &found)
{
    visited[node] = true;
    if(node == destination)
        return found = 1;
    for (int i = 0; i < graph1[node].size() && !found; ++i) { //Iterate over all current node edges until end or dest is found.
        if(!visited[graph1[node][i]]) {             //If not visited -> recurse
            recPDFS(graph1[node][i], destination, graph1, visited, found);
        }
    }
    return found ? ++found : found;
}


int pathDFS(int curr, int destination, Graph &graph1)     //Wrapper function
{
    vector<bool> visited = graph1.getVisited();
    int flag = 0;
    //returns all the edges need to be visited to reach desitination
    return recPDFS(curr, destination, graph1, visited, flag) - 1;
}


#endif //DFS_DFS_H
