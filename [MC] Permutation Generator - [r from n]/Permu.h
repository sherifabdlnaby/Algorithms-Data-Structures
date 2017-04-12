#ifndef P3_PERMU_H
#define P3_PERMU_H
#include <vector>
#include <iostream>

using namespace std;

//Fill the 2D-Vector with all possible permutation of size r from src.
void permutation(vector<int> src, int r, vector<int> total, vector<vector<int>> &permutations) {
    if(total.size() == r) {
        permutations.push_back(total);
        return;
    }
    else
    {
        for (int i = 0; i < src.size(); ++i) {
            vector<int> newTotal = total; //TODO CAN BE OPTIMIZED ?
            vector<int> newSrc = src;
            newTotal.push_back(src[i]);
            newSrc.erase(newSrc.begin()+i);
            permutation(newSrc, r, newTotal, permutations);
        }
    }
}

//Wrapper Function
vector<vector<int>> generatePerm(vector<int> src, int r) {
    vector<vector<int>> permutations;
    if(r > src.size())
        cout << "The size of permutation must be less than or equal the size of the source" << endl;
    else
        permutation(src, r, vector<int>(), permutations); //Fill our permutations vector.
    return permutations;
}



#endif //P3_PERMU_H
