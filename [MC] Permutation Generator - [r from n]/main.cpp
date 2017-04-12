#include <iostream>
#include "Permu.h"

using namespace std;


int main() {

    //Collecting Data
    int n,r;  vector<vector<int>> permutations;
    cout << "Enter the size of your list: " << endl;
    cin >> n;
    cout << "Enter the list: " << endl;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << "Enter Permutation size: " << endl;
    cin >> r;

    ////Program Start here/////

    permutations = generatePerm(nums, r);
    cout << permutations.size() << " Permutation generated." << endl;
    //Print all permutations...
    for (int i = 0; i < permutations.size(); ++i) {
        for (int j = 0; j < r; ++j)
            cout << permutations[i][j] << " ";
        cout << endl;
    }

    return 0;
}


