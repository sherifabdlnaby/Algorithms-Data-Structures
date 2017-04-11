//
// Created by Sherif on 4/9/2017.
//
#include <vector>
#include <stack>
#include <algorithm>
#include "Graph.h"

#ifndef DFS_DFS_H
#define DFS_DFS_H
bool DFS(int curr, int destination, Graph &graph1)      //Runs DFS (Modify it to your needs)
{
    vector<bool> visited = graph1.getVisited();
    stack<int>   stack1;
    visited[curr] = true;
    stack1.push(curr);
    while(!stack1.empty()){
        curr = stack1.top();  stack1.pop();             //Update Current and remove it from stack.
        for (int i = 0; i < graph1[curr].size(); ++i) { //Iterate over all current node edges.
            if(!visited[graph1[curr][i]]) {             //If not visited -> add it to stack.
                stack1.push(graph1[curr][i]);
                visited[graph1[curr][i]] = true;
            }
        }
    }
    return true;
}

vector<int> pathByDFS(int start, int destination, Graph &graph1) //(Not Shortest Path)
{
    vector<bool> visited = graph1.getVisited();
    vector<int>  tail(graph1.size(),-1);    //Back-tracking the path.
    stack<int>   stack1;
    int curr = start;
    visited[curr] = true;  stack1.push(curr);
    while(!stack1.empty()){
        curr = stack1.top();  stack1.pop(); //Update Current and remove it from stack.        
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
            if(!visited[graph1[curr][i]]) {             //If not visited -> add it to stack.
                stack1.push(graph1[curr][i]);
                tail[graph1[curr][i]] = curr;
                visited[graph1[curr][i]] = true;
            }
        }
    }
    return vector<int>(0); //return empty vector (indicating path not found)
}
#endif //DFS_DFS_H
