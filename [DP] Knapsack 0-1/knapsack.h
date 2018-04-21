//
// Created by Sherif on 21-Apr-18.
//

#ifndef INC_09_KNAPSACK_H
#define INC_09_KNAPSACK_H

#include <iostream>
#include <vector>

using namespace std;

class item {
public:
    int id;
    int weight;
    int value;
};

vector<item> knapsackItems(vector<item> items, int maxWeight){
    int N = items.size();
    int W = maxWeight;

    // DP[N+1][W+1] array.
    vector<vector<int>> DP(N + 1, vector<int>(W + 1, 0));
    vector<vector<bool >> traceBack(N + 1, vector<bool >(W + 1, 0));

    //Start Algorithm (note: in T2, item i matches item i-1 in array -> a)
    for (int n = 1; n <= N; ++n) {
        for (int w = 1; w <= W; ++w) {
            /* if we can't take this item, escape it.
               (escaping it mean picking the best result from the previous sub-problem at the same weight. */
            if (items[n - 1].weight > w) {
                DP[n][w] = DP[n - 1][w];
                traceBack[n][w] = false;       // escape item.
            }
                /* if we can take this item, compare if not taking this item led to better value.
                   1. not taking it -same idea as above- Vs.  2. taking it + the best sub-problem with the remaining weight if taken. */
            else {
                int notTakingItem = DP[n - 1][w];
                // Taking the item = current item value + previous sub-problem value of n-1 items and the remaining weight.
                int TakingItem = items[n - 1].value + DP[n - 1][w - items[n - 1].weight];

                if(notTakingItem > TakingItem)
                    DP[n][w] = notTakingItem,
                    traceBack[n][w] = false;   // escape item
                else
                    DP[n][w] = TakingItem,
                    traceBack[n][w] = true;     // take item
            }
        }
    }

    //recollect items via traceBack.
    int n = N, w = W;
    vector<item> selectedItems;

    while (n != 0){
        // if item at 'n' and 'w' was selected, pick it and trace back.
        if(traceBack[n][w] == true) {
            // save original index
            items[n - 1].id = n - 1;
            // add to selected vector
            selectedItems.push_back(items[n - 1]);
            // update weight
            w -= items[n - 1].weight;
        }

        // update n;
        --n;
    }

    return selectedItems;
}

//return value only -no traceback overhead-
int knapsack(vector<item> items, int maxWeight) {
    int N = items.size();
    int W = maxWeight;

    // DP[N+1][W+1] array.
    vector<vector<int>> DP(N + 1, vector<int>(W + 1, 0));

    //Start Algorithm (note: in T2, item i matches item i-1 in array -> a)
    for (int n = 1; n <= N; ++n) {
        for (int w = 1; w <= W; ++w) {
            /* if we can't take this item, escape it.
               (escaping it mean picking the best result from the previous sub-problem at the same weight. */
            if (items[n - 1].weight > w)
                DP[n][w] = DP[n - 1][w];
            /* if we can take this item, compare if not taking this item led to better value.
               1. not taking it -same idea as above- Vs.  2. taking it + the best sub-problem with the remaining weight if taken. */
            else
                DP[n][w] = max(DP[n - 1][w], items[n - 1].value + DP[n - 1][w - items[n - 1].weight]);
        }
    }

    return DP[N][W];
}


#endif //INC_09_KNAPSACK_H
