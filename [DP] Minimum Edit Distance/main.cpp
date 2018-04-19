#include<iostream>
#include "EditDistance.h"

using namespace std;


int main(){
    string string1, string2;

    cout << "Enter Source String: " << endl;
    cin >> string1;

    cout << "Enter Goal String: " << endl;
    cin >> string2;

    vector<editOperation> operations = editDistance(string1, string2);
    for (int i = 0; i < operations.size(); ++i) {
        cout << i + 1 << ". " << operations[i] << endl;
    }


    // to get the number of minimum operations only without overhead of tracback
    int minOperations = editDistanceValue(string1, string2);
    cout << "Operations count: " << minOperations << endl;

}

