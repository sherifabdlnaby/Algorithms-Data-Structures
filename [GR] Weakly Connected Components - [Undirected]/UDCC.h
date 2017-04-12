//
// Created by Sherif on 4/9/2017.
//
#include <vector>
#include <queue>
#include <algorithm>
#include "Graph.h"

#ifndef BFS_BFS_H
#define BFS_BFS_H
bool BFS(int curr, int destination, Graph& graph1) 		//Runs DFS (Modify it to your needs)
{
    vector<bool> visited = graph1.getVisited();
    queue<int>   queue1;
    visited[curr] = true;
    queue1.push(curr);
    while(!queue1.empty()){
        curr = queue1.front(); queue1.pop(); 			//Update Current and remove it from queue. 
        for (int i = 0; i < graph1[curr].size(); ++i) { //Iterate over all current node edges.
            if(!visited[graph1[curr][i]]) {				//If not visited -> enqueue it.
                queue1.push(graph1[curr][i]);
                visited[graph1[curr][i]] = true;
            }
        }
    }
    return true;
}

vector<vector<int>> UDCC(Graph &graph1) //Undirected Connected Components
{
    vector< vector<int> > objects;
    vector<bool> visited = graph1.getVisited();
    for (int k = 0; k < visited.size(); ++k) { //Iterate over all nodes & escape visited
        if(visited[k])
            continue; //ESCAPE
        int curr = k; //BFS on this node;
        queue<int> queue1;
        vector<int> object;
        visited[curr] = true;
        queue1.push(curr); //Queue node..
        object.push_back(curr); //Added it to current objects
        while (!queue1.empty()) {
            curr = queue1.front();
            queue1.pop();            //Update Current and remove it from queue.
            for (int i = 0; i < graph1[curr].size(); ++i) { //Iterate over all current node edges.
                if (!visited[graph1[curr][i]]) {            //If not visited -> enqueue it -> Added it connected Object...
                    visited[graph1[curr][i]] = true;
                    queue1.push(graph1[curr][i]);
                    object.push_back(graph1[curr][i]);
                }
            }
        }
        objects.push_back(object);
    }
    return objects;
}


#endif //BFS_BFS_H
