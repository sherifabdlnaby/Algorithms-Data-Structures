//
// Created by Sherif on 4/9/2017.
// Kosaraju's algorithm for Strongly Connected Components.
//
//
#include <vector>
#include <stack>
#include "Graph.h"

#ifndef DFS_DFS_H
#define DFS_DFS_H

vector<vector<int>> SCC(Graph &graph1); //Return a Vector of Vectors with all strong connected components.
void tDFS(int node, Graph &graph1, vector<int> &visited, int &T);               //DFS on the given node and fill visited vector with time taken base on passed &T.
void oDFS(int node, Graph &graph1, vector<int> &visited, vector<int> &object);  //DFS on the given node and return an object of all discoverable elements.
Graph reverseGraph(Graph &graph1);  //Return a Reversed Graph.

vector<vector<int>> SCC(Graph &graph1)
{
    Graph reversed = reverseGraph(graph1); //Reverse Graph1


    ///RUN DFS 1st time on reversed Graph. -> Fill Visited1 by Time of each node.
    int T = 0; //Time counter
    vector<int> visited1(graph1.size(),-1);
    for(int i=graph1.size()-1; i >= 0; i--) {
        if(visited1[i] == -1)
            tDFS(i, reversed, visited1, T);
    }


    ///We need to reverse indices with values in the visited1 vector after first DFS in visited2.
    ///Instead of creating another graph with new time values in visited1, flip visited1 -> in visited2 and use it as a reference.
    vector<int> visited2(visited1.size());
    for (int i = 0; i < visited1.size(); ++i) {
        visited2[visited1[i]] = i;
    }


    ///Run DFS 2nd time on original graph; (Using Visited2 as reference to original graph)
    vector<vector<int>> SCC;
    fill(visited1.begin(),visited1.end(),-1);        //re-use the first visited1 array space (other than allocate extra memory)
    for (int i = graph1.size()-1; i >= 0 ; --i) {   //iterate over all nodes...
        if(visited1[visited2[i]] == -1) {           //note* using Visited2 as a reference to original graph node(which are flagged on visited1 by DFS)...
            vector<int> object;
            oDFS(visited2[i], graph1, visited1, object); //fill object vector with a SCC object.(Passing the node on visited2 not just i)
            if(object.size() > 1)
                SCC.push_back(object);
        }
    }
    return SCC;
}


void tDFS(int node, Graph &graph1, vector<int> &visited, int &T)      //Runs DFS (Modify it to your needs)
{
    stack<pair<int,bool>>   stack1;
    visited[node] = 1;
    pair<int,bool> n = make_pair(node, false);
    stack1.push(n);
    while(!stack1.empty()){
        n = stack1.top();
        if(!n.second)
            stack1.top().second = true;
        else
        {
            stack1.pop();
            visited[n.first] = T++;
            continue;
        }
        for (int i = 0; i < graph1.graph[n.first].size(); ++i) { //Iterate over all current node edges.
            if(visited[graph1.graph[n.first][i]] == -1) {             //If not visited -> add it to stack.
                stack1.push(make_pair(graph1.graph[n.first][i], false));
                visited[graph1.graph[n.first][i]] = 1;
            }
        }
    }
    return;
}

void oDFS(int node, Graph &graph1, vector<int> &visited, vector<int> &object)      //Runs DFS (Modify it to your needs)
{
    stack<int>   stack1;
    visited[node] = 1;
    stack1.push(node);
    while(!stack1.empty()){
        node = stack1.top();  stack1.pop();             //Update Current and remove it from stack.
        object.push_back(node);
        for (int i = 0; i < graph1.graph[node].size(); ++i) { //Iterate over all current node edges.
            if(visited[graph1.graph[node][i]]==-1) {             //If not visited -> add it to stack.
                stack1.push(graph1.graph[node][i]);
                visited[graph1.graph[node][i]] = 1;
            }
        }
    }
    return;
}

Graph reverseGraph(Graph &graph1) {
    Graph reversed(graph1.size());
    for (int i = 0; i < graph1.size(); ++i) {
        for (int j = 0; j < graph1.graph[i].size(); ++j) {
            reversed.graph[graph1.graph[i][j]].push_back(i);
        }
    }
    return reversed;
}


#endif //DFS_DFS_H
