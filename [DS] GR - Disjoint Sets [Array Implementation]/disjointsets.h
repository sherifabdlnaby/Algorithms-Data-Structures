//
// Created by Sherif on 25-Feb-18.
//

#ifndef DISJOINT_SETS_DISJOINTSETS_H
#define DISJOINT_SETS_DISJOINTSETS_H

#include <cstring>
#include <list>

/*
 * This is Array Implementation of Disjoint Sets, it uses indices (0~n) as IDs to identify sets, and it requires the number of sets to be known beforehand.
 * in another graph implementation sets can have user-set IDs and dynamically add new sets.
 */
class DisjointSets
{
private:
    int n;
    int* parent;
    int* rank;
public:
    DisjointSets(int n);
    virtual ~DisjointSets();
    int Find(int i);
    int FindRecursive(int i);
    bool Union(int i, int j);
};

DisjointSets::DisjointSets(int n) : n(n) {
    parent = new int[n];
    rank = new int[n];
    memset(parent,-1, n * sizeof(int));
    memset(rank,0, n * sizeof(int));
}

DisjointSets::~DisjointSets() {
    delete[] parent;
    delete[] rank;
}

/* Iterative Version */
int DisjointSets::Find(int i) {

    //List to hold nodes in the root path to be compressed later.
    std::list<int> passCompressionList;

    //Iterate until root
    while(true){
        if(parent[i] == -1)
            break;
        else {
            //Save non-root in a list to be compressed later to directly point to root.
            passCompressionList.push_back(i);
            //Iterate
            i = parent[i];
        }
    }

    //Pass Compression
    std::list<int>::iterator it;
    for (it = passCompressionList.begin(); it != passCompressionList.end(); ++it){
        parent[*it] = i;
    }

    //Return root.
    return i;
}

/* Recursive Version */
int DisjointSets::FindRecursive(int i) {
    if (parent[i] == -1)
        return i;

    //Pass Compression
    parent[i] = FindRecursive(parent[i]);

    return parent[i];
}

bool DisjointSets::Union(int i, int j) {
    //Find set roots.
    int iRoot = Find(i);
    int jRoot = Find(j);

    //If they're in the same set return false.
    if (iRoot == jRoot)
        return false;

    //Union the smaller set with the bigger set, if sets are equal union i with j and increment.
    if(rank[iRoot] > rank[jRoot])
        parent[jRoot] = iRoot;
    else if(rank[iRoot] < rank[jRoot])
        parent[iRoot] = jRoot;
    else
        parent[jRoot] = iRoot, ++rank[iRoot];

    return true;
}

#endif //DISJOINT_SETS_DISJOINTSETS_H