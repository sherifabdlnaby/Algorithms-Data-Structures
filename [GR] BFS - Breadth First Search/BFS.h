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


vector<int> shortestPathBFS(int start, int destination, Graph& graph1)
{
    vector<bool> visited = graph1.getVisited();
    vector<int>  tail(graph1.size(),-1); //Back-tracking the path.
    queue<int>   queue1;
    int curr = start;
    visited[curr] = true;  queue1.push(curr);
    while(!queue1.empty()){
        curr = queue1.front(); queue1.pop(); //Update Current and remove it from queue.
        if(curr == destination)
        {
            vector<int> path;
            while(curr != -1) {
                path.push_back(curr);
                curr = tail[curr];
            }
            reverse(path.begin(),path.end());
            return path;
        }
        for (int i = 0; i < graph1[curr].size(); ++i) { //Iterate over all current node edges.
            if(!visited[graph1[curr][i]]) { //If not visited -> enqueue it.
                queue1.push(graph1[curr][i]);
                tail[graph1[curr][i]] = curr;
                visited[graph1[curr][i]] = true;
            }
        }
    }
    return vector<int>(0); //return empty vector (indicating path not found)
}
#endif //BFS_BFS_H
