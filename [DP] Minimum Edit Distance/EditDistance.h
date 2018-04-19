#ifndef INC_11_EDITDISTANCE_H
#define INC_11_EDITDISTANCE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


///////////////////////////////// Utility Classes and enums ////////////////////////
enum OperationType {
    INSERT, DELETE, REPLACE, NOTHING
};

class editOperation {
public:
    int index;
    char character = '\0';
    OperationType operationType;

    editOperation(int index, char character, OperationType operationType) : index(index), character(character),
                                                                            operationType(operationType) {}

    editOperation(int index, OperationType operationType) : index(index), operationType(operationType) {}

    friend ostream &operator<<(ostream &os, const editOperation &operation) {
        if (operation.operationType == INSERT)
            os << "Insert  -> at index: " << operation.index << ", char: " << operation.character;
        else if (operation.operationType == DELETE)
            os << "Delete  -> at index: " << operation.index;
        else if (operation.operationType == REPLACE)
            os << "Replace -> at index: " << operation.index << ", char: " << operation.character;
        else
            os << "Nothing";
    }
};

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////\\\\\DEFINITIONS\\\\//////////////////////////////////


vector<editOperation> editDistance(string str1, string str2);

int editDistanceValue(string str1, string str2);

vector<editOperation> traceBackOp(string str1, string str2, vector<vector<OperationType>> &traceBack);

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////\\\\\IMPLEMENTATIONS\\\\///////////////////////////////


vector<editOperation> editDistance(string str1, string str2) {
    int N = str1.size();
    int M = str2.size();

    //Declare DP and traceBack 2D Vectors.
    vector<vector<int>> DP(N+1, vector<int>(M+1));
    vector<vector<OperationType>> traceBack(N+1, vector<OperationType>(M+1));

    // INITIALIZE DP & traceBack TABLE 1st row & col.
    for (int j = 0; j <= M; ++j) {
        DP[0][j] = j;
        traceBack[0][j] = INSERT;    // 0 for insert.
    }

    for (int i = 0; i <= N; ++i) {
        DP[i][0] = i;
        traceBack[i][0] = DELETE;    // 1 for delete.
    }

    //START DP
    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {
            //NO DECISION - ESCAPE
            if (str1[n - 1] == str2[m - 1]) {
                DP[n][m] = DP[n - 1][m - 1];
                traceBack[n][m] = NOTHING;
            } else {

                //Check min cost for  -INSERT-          -REPLACE           -DELETE-
                int minCost = min(DP[n][m - 1], min(DP[n - 1][m - 1], DP[n - 1][m]));

                //Save new cost.
                DP[n][m] = 1 + minCost;

                //Save Decision
                if (minCost == DP[n][m - 1])
                    traceBack[n][m] = INSERT;
                else if (minCost == DP[n - 1][m])
                    traceBack[n][m] = DELETE;
                else
                    traceBack[n][m] = REPLACE;
            }
        }
    }
    return traceBackOp(str1, str2, traceBack);
}

int editDistanceValue(string str1, string str2) {
    int N = str1.size();
    int M = str2.size();

    //Declare DP and traceBack 2D Vectors.
    vector<vector<int>> DP(N+1, vector<int>(M+1));
    vector<vector<OperationType>> traceBack(N+1, vector<OperationType>(M+1));

    // INITIALIZE DP & traceBack TABLE 1st row & col.
    for (int j = 0; j <= M; ++j) {
        DP[0][j] = j;
        traceBack[0][j] = INSERT;    // 0 for insert.
    }

    for (int i = 0; i <= N; ++i) {
        DP[i][0] = i;
        traceBack[i][0] = DELETE;    // 1 for delete.
    }

    //START DP
    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {
            //NO DECISION - ESCAPE
            if (str1[n - 1] == str2[m - 1]) {
                DP[n][m] = DP[n - 1][m - 1];
                traceBack[n][m] = NOTHING;
            } else {

                //Check min cost for  -INSERT-          -REPLACE           -DELETE-
                int minCost = min(DP[n][m - 1], min(DP[n - 1][m - 1], DP[n - 1][m]));

                //Save new cost.
                DP[n][m] = 1 + minCost;

                //Save Decision
                if (minCost == DP[n][m - 1])
                    traceBack[n][m] = INSERT;
                else if (minCost == DP[n - 1][m])
                    traceBack[n][m] = DELETE;
                else
                    traceBack[n][m] = REPLACE;
            }
        }
    }
    return DP[N][M];
}

vector<editOperation> traceBackOp(string str1, string str2, vector<vector<OperationType>> &traceBack) {
    int n = str1.size(), m = str2.size(), operationCount = 0;

    vector<editOperation> operations;

    while (n != 0 || m != 0) {
        // add to list if it's an operation and not an Escape.
        if (traceBack[n][m] != NOTHING) {
            // if Operation is Insert Or Delete add operation with a char.
            if (traceBack[n][m] == INSERT || traceBack[n][m] == REPLACE)
                operations.push_back(editOperation(n, str2[m - 1], traceBack[n][m]));
            else
                operations.push_back(editOperation(n, traceBack[n][m]));

            /*
             * Notice that the indices saved are relative to the DP table, however this indices shall be offseted
               Accordingly (a Delete operation will offset the index -1, and an Insert +1. however we can't offset them unless
               they're all collected and sorted.
           `*/
        }

        // iterate (traceBack).
        if (traceBack[n][m] == INSERT)
            --m;
        else if (traceBack[n][m] == DELETE)
            --n;
        else
            --n, --m;
    }

    //Reverse Operations and Offset Indices
    reverse(operations.begin(), operations.end());

    //used to offset indexes after insert/delete .
    int deleteCount = 0;
    int insertCount = 0;

    //offset indices
    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i].operationType == INSERT)
            operations[i].index += deleteCount + insertCount++;
        else if (operations[i].operationType == DELETE)
            operations[i].index +=  insertCount - deleteCount++ - 1;
        else if (operations[i].operationType == REPLACE)
            operations[i].index +=  insertCount - deleteCount - 1;
    }

    return operations;
}

#endif //INC_11_EDITDISTANCE_H
