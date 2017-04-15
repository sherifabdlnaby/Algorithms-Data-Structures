//
// Created by Sherif on 4/9/2017.
// Algorithm by Edsger W. Dijkstra
//
#include <vector>
#include <algorithm> //reverse();
#include <queue>     //priority_queue();
#include "Graph.h"

#ifndef DFS_DFS_H
#define DFS_DFS_H
#define INF 0x3f3f3f3f
typedef pair<int,int> node; ///First = weight, second = Node number;

int dijkstra(int start, int destination, Graph &graph1)
{
    priority_queue<node, vector<node>, greater<node>> pqueue; ///Using Vector container(the fastest), and Greater (to sort by smallest weight(node.first))
    vector<int> dist(graph1.size(), INF);

    ///Initialize the start node and push it to the pQueue;
    dist[start] = 0;
    pqueue.push(make_pair(0,start));

    ///Dijkstra
    while(!pqueue.empty())
    {
        int curr = pqueue.top().second;
        pqueue.pop();
        if(curr == destination)
            return dist[curr];
        for (int i = 0; i < graph1[curr].size(); ++i) {
            int oldPath =  dist[graph1[curr][i].second];
            int newPath =  dist[curr] + graph1[curr][i].first;
            if( oldPath > newPath ) ///If we found a shorter path
            {
                pqueue.push(make_pair(newPath, graph1[curr][i].second));
                dist[graph1[curr][i].second] = newPath;
            }
        }
    }
    return -1; //Path not found.
}


vector<int> dijkstraAllNodes(int start, Graph &graph1)
{
    priority_queue<node, vector<node>, greater<node>> pqueue; ///Using Vector container(the fastest), and Greater (to sort by smallest weight(node.first))
    vector<int> dist(graph1.size(), INF);

    ///Initialize the start node and push it to the pQueue;
    dist[start] = 0;
    pqueue.push(make_pair(0,start));

    ///Dijkstra
    while(!pqueue.empty())
    {
        int curr = pqueue.top().second;
        pqueue.pop();
        for (int i = 0; i < graph1[curr].size(); ++i) {
            int oldPath =  dist[graph1[curr][i].second];
            int newPath =  dist[curr] + graph1[curr][i].first;
            if( oldPath > newPath ) ///If we found a shorter path
            {
                pqueue.push(make_pair(newPath, graph1[curr][i].second));
                dist[graph1[curr][i].second] = newPath;
            }
        }
    }
    return dist; //Return the distances from each node to the start node.
}



vector<int> dijkstraPath(int start, int destination, Graph &graph1)
{
    priority_queue<node, vector<node>, greater<node>> pqueue; ///Using Vector container(the fastest), and Greater (to sort by smallest weight(node.first))
    vector<pair<int,int>> dist(graph1.size(), make_pair(INF,-1));

    ///Initialize the start node and push it to the pQueue;
    dist[start].first = 0;
    pqueue.push(make_pair(0,start));

    ///Dijkstra
    while(!pqueue.empty())
    {
        int curr = pqueue.top().second;
        pqueue.pop();
        if(curr == destination)
            break;
        for (int i = 0; i < graph1[curr].size(); ++i) {
            int oldPath =  dist[graph1[curr][i].second].first;
            int newPath =  dist[curr].first + graph1[curr][i].first;
            if( oldPath > newPath ) ///If we found a shorter path
            {
                pqueue.push(make_pair(newPath, graph1[curr][i].second));
                dist[graph1[curr][i].second].first  = newPath;
                dist[graph1[curr][i].second].second = curr;
            }
        }
    }

    ///Extracting the path
    if(dist[destination].second == -1) //Return empty vector (NO PATH);
        return vector<int>();

    ///Else (Follow the path -> reverse -> return)
    vector<int> path;
    int i = destination;
    path.push_back(destination);
    while(dist[i].second != -1)
    {
        path.push_back(dist[i].second);
        i = dist[i].second; //iterate..
    }
    reverse(path.begin(),path.end());
    return path;
}


vector<pair<int,int>> dijkstraAllNodesPath(int start, Graph &graph1)
{

    priority_queue<node, vector<node>, greater<node>> pqueue; ///Using Vector container(the fastest), and Greater (to sort by smallest weight(node.first))
    vector<pair<int,int>> dist(graph1.size(), make_pair(INF,-1));

    ///Initialize the start node and push it to the pQueue;
    dist[start].first = 0;
    pqueue.push(make_pair(0,start));

    ///Dijkstra
    while(!pqueue.empty())
    {
        int curr = pqueue.top().second;
        pqueue.pop();
        for (int i = 0; i < graph1[curr].size(); ++i) {
            int oldPath =  dist[graph1[curr][i].second].first;
            int newPath =  dist[curr].first + graph1[curr][i].first;
            if( oldPath > newPath ) ///If we found a shorter path
            {
                pqueue.push(make_pair(newPath, graph1[curr][i].second));
                dist[graph1[curr][i].second].first  = newPath;
                dist[graph1[curr][i].second].second = curr;
            }
        }
    }

    return dist;
}


bool dijkstraCommented(int start, int destination, Graph &graph1)
{
    priority_queue<node, deque<node>, greater<node>> pqueue;
    vector<int> dist(graph1.size(), INF);
    dist[start] = 0;
    pqueue.push(make_pair(0,start));
    while(!pqueue.empty())
    {
        int curr = pqueue.top().second;

        pqueue.pop();
        for (int i = 0; i < graph1[curr].size(); ++i) {
            ///Current node we're discovering;
            int dbg1 = graph1[curr][i].second;
            ///weight to Visit the said node;
            int dbg2 = graph1[curr][i].first;
            ///Old Distance to Visit the said Node;
            int old =  dist[graph1[curr][i].second];
            ///New Distance to Visit the said Node;
            int neww = dist[curr] + graph1[curr][i].first;
            if( old > neww )
            {
                pqueue.push(make_pair(neww, graph1[curr][i].second));
                dist[graph1[curr][i].second] = neww;
            }
        }
    }
    return true;
}

#endif //DFS_DFS_H
