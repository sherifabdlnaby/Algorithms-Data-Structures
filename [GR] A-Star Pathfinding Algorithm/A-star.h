//
// Created by Sherif on 4/9/2017.
//
#include <vector>
#include <algorithm> //reverse();
#include <queue>     //priority_queue();
#include "Graph.h"

#ifndef DFS_DFS_H
#define DFS_DFS_H
#define INF 0x3f3f3f3f
struct queue_node{
    int num;
    int weight;
    int heuristic;
};

class cmp
{
public:
    ///Note that priority queue cmp() is flipped;
    bool operator() (queue_node i, queue_node j)
    {
        if(i.heuristic < j.heuristic)
            return false;
        else if(i.heuristic > j.heuristic)
            return true;
        else return i.weight > j.weight;
    }
};

//Calculates the heuristic based on the nature of the graph; (struct node can be altered to contain extra information.
//(e.g i,j coordination for the nodes, etc)
int heuristic(node &current, node &destination){
    ///Calculates a Heuristic distance based on Current node and Destination Node.
    ///Default case(prioritize according to weight if all heuristics are equal aka Dijkstra).
    return 0;
}


int a_star(int start, int destination, Graph &graph1, int(*heuristic)(node &curr, node &destination) = heuristic)
{
    priority_queue<queue_node, vector<queue_node>, cmp> pqueue; ///Using Vector container(the fastest), and our cmp class;
    vector<int> dist(graph1.size(), INF);

    ///Initialize the start node and push it to the pQueue;
    dist[start] = 0;
    pqueue.push({start,0,0});

    ///A-star
    while(!pqueue.empty())
    {
        int curr = pqueue.top().num;
        pqueue.pop();
        if(curr == destination)
            return dist[curr];
        for (int i = 0; i < graph1[curr].size(); ++i) {
            int oldPath =  dist[graph1[curr][i].num];
            int newPath =  dist[curr] + graph1[curr][i].weight;
            if( oldPath > newPath ) ///If we found a shorter path
            {
                ///Push into queue constructor of queue_node{num, weight, heuristic}
                /// 1- current neighbour node.
                /// 2- new path distance.
                /// 3- new path + heuristic distance(given parameters of current neighbour node, destination node)
                pqueue.push({graph1[curr][i].num, newPath, newPath + heuristic(graph1.getNode(graph1[curr][i].num), graph1.getNode(destination)) });
                dist[graph1[curr][i].num] = newPath;
            }
        }
    }
    return -1; //Path not found.
}


vector<int> a_starPath(int start, int destination, Graph &graph1)
{
    priority_queue<queue_node, vector<queue_node>, cmp> pqueue;
    vector<pair<int,int>> dist(graph1.size(), make_pair(INF,-1));

    ///Initialize the start node and push it to the pQueue;
    dist[start].first = 0;
    pqueue.push({start,0,0});

    ///A-star
    while(!pqueue.empty())
    {
        int curr = pqueue.top().num;
        pqueue.pop();
        if(curr == destination)
            break;
        for (int i = 0; i < graph1[curr].size(); ++i) {
            int oldPath =  dist[graph1[curr][i].num].first;
            int newPath =  dist[curr].first + graph1[curr][i].weight;
            if( oldPath > newPath ) ///If we found a shorter path
            {
                pqueue.push({graph1[curr][i].num, newPath, newPath + heuristic(graph1.getNode(graph1[curr][i].num), graph1.getNode(destination)) });
                dist[graph1[curr][i].num].first  = newPath;
                dist[graph1[curr][i].num].second = curr;
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


#endif //DFS_DFS_H
